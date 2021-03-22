#include "rules.hpp"
#include <algorithm>
#include <unordered_map>

bool isStraightFlush(const std::vector<poker_card> & hand)
{
   return isStraight(hand) and isFlush(hand);
}

bool isFourOfAKind(const std::vector<poker_card> & hand)
{
   auto counts = sortedFigureCounters(hand);
   return counts.size() == 2 and counts[1] == 4;
}

bool isFullHouse(const std::vector<poker_card> & hand)
{
   auto counts = sortedFigureCounters(hand);
   return counts.size() == 2 and counts[1] == 3;
}

bool isFlush(const std::vector<poker_card> & hand)
{
   auto cardColor = hand[0].color;

   for(auto card : hand)
      if (card.color != cardColor)
         return false;

   return true;
}

bool isStraight(const std::vector<poker_card> & hand)
{
   auto sortedHand = hand;
   auto compareFigures = [](poker_card & a, poker_card & b) -> bool { return a.figure < b.figure; };

   std::sort(sortedHand.begin(), sortedHand.end(), compareFigures);
   
   size_t i = sortedHand[0].figure;

   for(auto card : sortedHand)
      if (card.figure != i++)
         return false;
   
   return true;
}

bool isThreeOfAKind(const std::vector<poker_card> & hand)
{
   auto counts = sortedFigureCounters(hand);
   return counts.size() == 3 and counts[2] == 3;
}

bool isTwoPairs(const std::vector<poker_card> & hand)
{
   auto counts = sortedFigureCounters(hand);
   return counts.size() == 3 and counts[2] == 2;
}

std::vector<size_t> sortedFigureCounters(const std::vector<poker_card> & hand)
{
   std::vector<size_t> counters;
   std::unordered_map<size_t, size_t> umap;

   for(auto card : hand)
   {
      if (umap.count(card.figure))
         umap[card.figure]++;
      else
         umap[card.figure] = 1;  
   }

   for(auto counter : umap)
      counters.push_back(counter.second);
   
   std::sort(counters.begin(), counters.end());

   return counters;
}