#include "logical_image.hpp"
#include <funcs/funcs.hpp>
#include <random>

#include <iostream>

namespace 
{
   const std::string sign [] = {".", "#"};
}

logical_image::logical_image()
{
}

logical_image::logical_image(const Config & _config): config(_config)
{
   initImgWithRandomValues();
   solve();
}

void logical_image::initImgWithZero()
{
   img = {};
   for (size_t i=0; i<config.numOfRows; i++)
      {
         std::vector<bool> vec;

         for (size_t j=0; j<config.numOfColumns; j++)
            vec.push_back(0);
         
         img.push_back(vec);
      }
}

void logical_image::initImgWithRandomValues()
{
   std::random_device rd;
   std::mt19937 generator(rd());
   std::uniform_int_distribution<size_t> randomBool(0, 1);

   img = {};
   for (size_t i=0; i<config.numOfRows; i++)
   {
      std::vector<bool> vec;

      for (size_t j=0; j<config.numOfColumns; j++)
         vec.push_back(randomBool(generator));
      
      img.push_back(vec);
   }
}

void logical_image::solve()
{
   size_t count = 0;
   size_t number = 10000;

   IncorrectLines incorrectLines = getIncorrectLines();

   while(isThereAnyIncorrectLine(incorrectLines))
   {
      size_t rowIndex, columnIndex;
      auto incorrect = getRandomIncorrectLine(incorrectLines);

      if (incorrect.type == ROWS)
      {
         rowIndex = incorrect.index;
         columnIndex = getColumnNumberOfPixelToChange(incorrect);
      }
      else
      {
         rowIndex = getRowNumberOfPixelToChange(incorrect);
         columnIndex = incorrect.index;
      }

      changePixel(rowIndex, columnIndex);

      if (count ++ == number)
      {
         count = 0;
         initImgWithZero();
      }

      incorrectLines = getIncorrectLines();
   }
}

bool logical_image::isThereAnyIncorrectLine(IncorrectLines & iLines)
{
   return not iLines.lines[ROWS].empty() or not iLines.lines[COLUMNS].empty();
}

IncorrectLine logical_image::getRandomIncorrectLine(IncorrectLines & iLines)
{
   std::random_device rd;
   std::mt19937 generator(rd());
   std::uniform_int_distribution<size_t> randomLineType(0, 1);
   
   size_t lineType = randomLineType(generator);

   if (iLines.lines[lineType].empty()) lineType = not lineType;

   std::uniform_int_distribution<size_t> randomIndex(0, iLines.lines[lineType].size()-1);

   return iLines.lines[lineType][randomIndex(generator)];
}

size_t logical_image::getColumnNumberOfPixelToChange(IncorrectLine & iLine)
{
   size_t minDist = config.numOfColumns;
   size_t minDistIndex = 0;

   for (size_t i=0; i<config.numOfColumns; i++)
   {
      auto column = getColumn(i);
      auto row = iLine.data;
      size_t columnBlockSize = config.columnBlockSize[i];
      size_t rowBlockSize = config.rowBlockSize[iLine.index];
      
      column[iLine.index] = column[iLine.index];
      row[i] = not row[i];

      size_t columnDist = optDist(column, columnBlockSize);
      size_t rowDist = optDist(row, rowBlockSize);
      if (columnDist + rowDist < minDist)
      {
         minDist = columnDist + rowDist;
         minDistIndex = i;
      }
   }

   return minDistIndex;
}

size_t logical_image::getRowNumberOfPixelToChange(IncorrectLine & iLine)
{
   size_t minDist = config.numOfRows;
   size_t minDistIndex = 0;

   for (size_t i=0; i<config.numOfRows; i++)
   {
      auto row = img[i];
      auto column = iLine.data;
      size_t rowBlockSize = config.rowBlockSize[i];
      size_t columnBlockSize = config.columnBlockSize[iLine.index];

      row[iLine.index] = row[iLine.index];
      column[i] = not column[i];

      size_t rowDist = optDist(row, rowBlockSize);
      size_t columnDist = optDist(column, columnBlockSize);
      if (columnDist + rowDist < minDist)
      {
         minDist = columnDist + rowDist;
         minDistIndex = i;
      }
   }

   return minDistIndex;
}

void logical_image::changePixel(size_t rowIndex, size_t columnIndex)
{
   img[rowIndex][columnIndex] = not img[rowIndex][columnIndex];
}

IncorrectLines logical_image::getIncorrectLines()
{
   IncorrectLines incorrectLines;

   for(size_t i=0; i<config.numOfRows; i++)
      if (not containsMaxOneBlock(img[i]) or not correctNumOfSetBits(img[i], config.rowBlockSize[i]))
         incorrectLines.lines[ROWS].push_back({ROWS, i, img[i]});

   for(size_t i=0; i<config.numOfColumns; i++)
   {
      auto column = getColumn(i);
      if (not containsMaxOneBlock(column) or not correctNumOfSetBits(column, config.columnBlockSize[i]))
         incorrectLines.lines[COLUMNS].push_back({COLUMNS, i, column});
   }

   return incorrectLines;
}

bool logical_image::containsMaxOneBlock(const std::vector<bool> & line)
{
   bool afterBLock = false;
   bool blockAlreadyExists = false;

   for(auto elem : line)
   {
      if (elem) 
      {
         if (afterBLock) return false;
         blockAlreadyExists = true;
      }
      else if (blockAlreadyExists) afterBLock = true;
   }

   return true;
}

bool logical_image::correctNumOfSetBits(const std::vector<bool> & line, size_t expectedNumOfSetBits)
{
   return getNumberOfSetBits(line) == expectedNumOfSetBits;
}

size_t logical_image::getNumberOfSetBits(const std::vector<bool> & line)
{
   size_t count = 0;

   for (auto elem : line) count += elem;

   return count;
}

std::vector<bool> logical_image::getColumn(size_t index)
{
   std::vector<bool> column;

   for(auto & row : img) column.push_back(row[index]);
   
   return column;
}

const std::string logical_image::rowAsStr(const std::vector<bool> & row)
{
   std::string str = {};

   for(auto bit : row)
      str += sign[bit];
   
   return str;
}

const std::string logical_image::asString()
{
   std::string imgAsStr = {}; 

   for(auto & row : img)
      imgAsStr += rowAsStr(row) + "\n";
   
   return imgAsStr;
}