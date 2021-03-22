#include "config.hpp"
#include "incorrect_lines.hpp"
#include <string>
#include <vector>
#include <fstream>

class logical_image
{
public:
   logical_image();
   logical_image(const Config & _config);
   const std::string asString(); 

private:
   void solve();
   void initImgWithZero();
   void initImgWithRandomValues();
   void changePixel(size_t row, size_t column);
   const std::string rowAsStr(const std::vector<bool> & row);

   bool isThereAnyIncorrectLine(IncorrectLines & iLines);
   bool containsMaxOneBlock(const std::vector<bool> & line);
   bool correctNumOfSetBits(const std::vector<bool> & line, size_t expectedNumOfSetBits);

   IncorrectLines getIncorrectLines();
   std::vector<bool> getColumn(size_t index);
   size_t getNumberOfSetBits(const std::vector<bool> & line);
   size_t getRowNumberOfPixelToChange(IncorrectLine & iLine);
   size_t getColumnNumberOfPixelToChange(IncorrectLine & iLine);
   IncorrectLine getRandomIncorrectLine(IncorrectLines & iLines);

   std::vector<std::vector<bool>> img;
   std::vector<int> numOfBitsNeedToSetInRow;
   std::vector<int> numOfBitsNeedToSetInColumn;
   Config config;
};