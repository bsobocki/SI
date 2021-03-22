#include <cstdlib>
#include <vector>

struct Config
{
   std::size_t numOfColumns;
   std::size_t numOfRows;
   std::vector<size_t> rowBlockSize;
   std::vector<size_t> columnBlockSize;
};

Config createConfigFromInputFile(const char * filePath);