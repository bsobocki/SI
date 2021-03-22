#include <cstdlib>
#include <vector>

struct IncorrectLine
{
   size_t type;
   size_t index;
   std::vector<bool> data;
};

const size_t ROWS = 0;
const size_t COLUMNS = 1;

struct IncorrectLines
{
   std::vector<IncorrectLine> lines [2];
};