#include "figure.hpp"
#include <deque>
#include <unordered_map>

struct state
{
   std::string layout;
   uint32_t stepCount;
   std::string parent;

   state() = default;
   state(const std::string & l, const uint32_t sC, const std::string & p)
   {
      layout = l;
      stepCount = sC;
      parent = p;
   }
};

class chess
{
public:
   chess(const std::string & _startLayout);
   size_t getMinNumOfMoves();
   void printSteps();

private:
   size_t minMoves(const std::string & lay);
   void printLayout(const std::string & layout);

   std::string startLayout;
   std::unordered_set<std::string> checkedLayouts;
   std::deque<state> steps;
   std::unordered_map<std::string, std::string> parent;
   state lastStep;
};