#include <TextDivider.hpp>
#include <algorithm>
#include <iterator>
#include <iostream>

namespace textDivider
{

TextDivider::TextDivider(const std::string _filePath)
{
   loadDictFromFile(_filePath);
}

void TextDivider::loadDictFromFile(const std::string filePath)
{
   std::string word;
   std::ifstream file(filePath.c_str());

   while(getline(file, word))
      dict.insert(word);
}

std::vector<std::string> TextDivider::bestDivide(const std::string text)
{
   if (text.empty()) 
      return {};
   if (text.length() == 1 and dict.count(text)) 
      return { text }; 

   int textLen = text.length();
   std::vector<std::string> max_words [textLen];

   for(int indexStart = text.length()-1; indexStart >= 0; indexStart--)
   {
      for(int indexEnd = indexStart+1; indexEnd <= textLen; indexEnd++)
      {
         if(indexEnd < indexStart)
            std::cout<<"end : "<<indexEnd<<"  start: "<<indexStart<<std::endl;

         auto word = text.substr(indexStart, indexEnd-indexStart);
         
         if (dict.count(word))
         {
            if (indexEnd < textLen) 
            {
               if (not max_words[indexEnd].empty())
               {
                  std::vector<std::string> tempSet = {word};

                  std::copy(
                     max_words[indexEnd].begin(), 
                     max_words[indexEnd].end(), 
                     std::back_inserter(tempSet)
                  );

                  setMaxWord(max_words[indexStart], tempSet); 
               }
            }
            else 
               setMaxWord(max_words[indexStart], {word});
         }
      }
   }

   return max_words[0];
}

void TextDivider::setMaxWord(std::vector<std::string> & oldSet, const std::vector<std::string> newSet)
{
   if (oldSet.empty() or sqrSum(oldSet) < sqrSum(newSet))
      oldSet = newSet;
}

uint64_t TextDivider::sqrSum(const std::vector<std::string> & _words)
{
   uint64_t sum = 0;
   for(auto word : _words)
   {
      uint64_t len = word.length();
      sum += len * len;
   }

   return sum;
}

}