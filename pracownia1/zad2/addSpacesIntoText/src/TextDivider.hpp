#include <fstream>
#include <memory>
#include <vector>
#include <unordered_set>

namespace textDivider
{

class TextDivider
{
public:
   TextDivider(const std::string _filePath);
   std::vector<std::string> bestDivide(const std::string text);

private:
   void loadDictFromFile(const std::string _filePath);
   uint64_t sqrSum(const std::vector<std::string> & _words);
   void setMaxWord(std::vector<std::string> & oldSet, const std::vector<std::string> newSet);

   std::string::iterator iter;
   std::unordered_set<std::string> dict;
};

}