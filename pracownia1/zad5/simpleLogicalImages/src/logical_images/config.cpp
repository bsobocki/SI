#include "config.hpp"
#include <fstream>
#include <string>

Config createConfigFromInputFile(const char * filePath)
{
   std::ifstream iFile(filePath);

   Config config;
   std::string line;
   
   std::getline(iFile, line);
   
   auto delim = line.find(' ');
   config.numOfRows = std::stoul(line.substr(0, delim)); 
   config.numOfColumns = std::stoul(line.substr(++delim));

   for(size_t i=0; i<config.numOfRows; i++)
   {
      std::getline(iFile, line);
      config.rowBlockSize.push_back(std::stoul(line));
   }

   for(size_t i=0; i<config.numOfColumns; i++)
   {
      std::getline(iFile, line);
      config.columnBlockSize.push_back(std::stoul(line));
   }

   return config;
}