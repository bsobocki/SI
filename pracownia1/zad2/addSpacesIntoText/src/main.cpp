#include <TextDivider.hpp>
#include <fstream>
#include <iostream>
#include <memory>

using namespace textDivider;

int main(int argc, const char * argv[])
{
   std::string dictPath =  "polskie_slowa.txt"; // std::string(argv[1]);
   std::string iFilePath = "zad2_input.txt"; //std::string(argv[2]);
   std::string oFilePath = "zad2_output.txt"; //std::string(argv[3]);

   std::string textLine;
   TextDivider textDivider(dictPath);
   std::ifstream iFile(iFilePath.c_str());
   std::ofstream oFile(oFilePath.c_str());

   while(std::getline(iFile, textLine))
   {
      auto words = textDivider.bestDivide(textLine);
      for(auto word : words) oFile<<word<<" ";
      oFile<<std::endl;
   }

   return 0;
}