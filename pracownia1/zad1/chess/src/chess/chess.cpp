#include "chess.hpp"
#include <iostream>
#include <algorithm>

void chess::printLayout(const std::string & layout)
{
   std::cout<<"  | A | B | C | D | E | F | G | H |\n";
   std::cout<<"--+---+---+---+---+---+---+---+---+\n";
   for (char number : {'1','2','3','4','5','6','7','8'})
   {
      std::cout<<number<<" | ";
      for (char letter : {'a','b','c','d','e','f','g','h'})
      {
         if (getBKingLetter(layout) == letter and getBKingNumber(layout) == number)
            std::cout<<"♔";
         else if (getWKingLetter(layout) == letter and getWKingNumber(layout) == number)
            std::cout<<"♚";
         else if (getWRookLetter(layout) == letter and getWRookNumber(layout) == number)
            std::cout<<"♜";
         else
            std::cout<<"_";

         std::cout<<" | ";
      }
      std::cout<<std::endl;
   }
   std::cout<<std::endl<<std::endl;
}

void chess::printSteps()
{
   std::string step = lastStep.layout;
   std::deque<std::string> steps;

   while(step != "")
   {
      steps.push_front(step);
      step = parent[step];
   }

   for (auto s : steps)
      printLayout(s);
}

chess::chess(const std::string & _startLayout):
   startLayout(_startLayout)
{
   checkedLayouts.reserve(50000);
}

size_t chess::getMinNumOfMoves()
{
   bool found = false;
   steps.emplace_back(startLayout, 0, "");
   checkedLayouts.insert(startLayout);

   while(not steps.empty())
   {
      auto st = steps.front();

      parent[st.layout] = st.parent;
      steps.pop_front();

      auto blackKingMoves = possibleBKingMoveLayouts(st.layout);

      if (isBKingCheck(st.layout, getBKingPosition(st.layout)) and blackKingMoves.empty())
      {
         lastStep = st;
         found = true;
         break;
      }

      if (getPlayerColor(st.layout) == 'b')
      {            
         for (auto move : blackKingMoves)
            if (not checkedLayouts.count(move))
            {
               steps.emplace_back(move, st.stepCount+1, st.layout);
               checkedLayouts.insert(move);
            }
      }
      else
      {
         for (auto move : possibleWRookMoveLayouts(st.layout))
            if (not checkedLayouts.count(move))
            {
               steps.emplace_back(move, st.stepCount+1, st.layout);
               checkedLayouts.insert(move);
            }

         for (auto move : possibleWKingMoveLayouts(st.layout))
            if (not checkedLayouts.count(move))
            {
               steps.emplace_back(move, st.stepCount+1, st.layout);
               checkedLayouts.insert(move);
            }
      }
   }

   if (not found)
      return -1;
   
   return lastStep.stepCount;
}

size_t chess::minMoves(const std::string & layout)
{
   size_t min = 0xFFFFFFFF;

   auto blackKingMoves = possibleBKingMoveLayouts(layout);

   if (isBKingCheck(layout, getBKingPosition(layout)) and blackKingMoves.empty())
      return 0;
   
   if (not checkedLayouts.count(layout)) 
      return min;
   else 
   {
      checkedLayouts.insert(layout);
      std::cout<<checkedLayouts.size()<<std::endl;
   }

   if (getPlayerColor(layout) == 'b')
   {
      if (blackKingMoves.empty())
         return 0;
         
      for (auto move : blackKingMoves)
         min = std::min(min, minMoves(move)+1);
   }
   else
   {
      for (auto move : possibleWRookMoveLayouts(layout))
         min = std::min(min, minMoves(move)+1);

      for (auto move : possibleWKingMoveLayouts(layout))
         min = std::min(min, minMoves(move)+1);
   }

   return min;
}