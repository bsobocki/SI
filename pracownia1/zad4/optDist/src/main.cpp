#include <fstream>
#include <iostream>
#include <funcs/funcs.hpp>

std::pair<std::string, int> getParams(const std::string & line)
{
   auto spaceIter = line.find(' ');
   return {line.substr(0, spaceIter), std::atoi(line.substr(spaceIter+1).c_str())};
}

int main(int argc, const char * argv [])
{
   std::ifstream iFile("zad4_input.txt");
   std::ofstream oFile("zad4_output.txt");
   std::string line;
   
   while(getline(iFile, line))
   {
      auto params = getParams(line);
      oFile<<optDist(params.first, params.second)<<std::endl;
   }

   return 0;
}