#include "poker.hpp"
#include <iostream>

enum score {
   NOTHING, 
   ONE_PAIR, 
   BLOTKARZ_TWO_PAIRS, 
   FIGURANT_TWO_PAIRS, 
   BLOTKARZ_THREE_OF_A_KIND, 
   FIGURANT_THREE_OF_A_KIND, 
   STRAIGHT, 
   FLUSH, 
   BLOTKARZ_FULL_HOUSE, 
   FIGURANT_FULL_HOUSE, 
   BLOTKARZ_FOUR_OF_A_KIND, 
   FIGURANT_FOUR_OF_A_KIND, 
   STRAIGHT_FLUSH
};

size_t getBlotkarzScore(const std::vector<poker_card> & hand)
{
   if (isStraightFlush(hand))
      return STRAIGHT_FLUSH;

   if (isFourOfAKind(hand))
      return BLOTKARZ_FOUR_OF_A_KIND;

   if (isFullHouse(hand))
      return BLOTKARZ_FULL_HOUSE;

   if (isFlush(hand))
      return FLUSH;

   if (isStraight(hand))
      return STRAIGHT;

   if (isThreeOfAKind(hand))
      return BLOTKARZ_THREE_OF_A_KIND;

   if (isTwoPairs(hand))
      return BLOTKARZ_TWO_PAIRS;

   // we don't have to check onePair, because Figurant will always have at least one pair, which will be higher than Blotkarz's one
   return NOTHING;
}

size_t getFigurantScore(const std::vector<poker_card> & hand)
{
   if (isFourOfAKind(hand))
      return FIGURANT_FOUR_OF_A_KIND;
   
   if (isFullHouse(hand))
      return FIGURANT_FULL_HOUSE;

   if (isThreeOfAKind(hand))
      return FIGURANT_THREE_OF_A_KIND;

   if (isTwoPairs(hand))
      return FIGURANT_TWO_PAIRS;

   return ONE_PAIR;
}

Game::Game(size_t _numfOfGames, game_type type): 
   numOfGames(_numfOfGames),
   blotkarz(type)
{ 
}

state Game::launch()
{
   state st = {0, 0, numOfGames};

   for(size_t i=0; i<numOfGames; i++)
   {
      auto blotkarzScore = getBlotkarzScore(blotkarz.hand);
      auto figurantScore = getFigurantScore(figurant.hand);
      
      if(blotkarzScore > figurantScore)
         st.blotkarzWins++;
      else
         st.figurantWins++;

      blotkarz.randomCards();
      figurant.randomCards();
   }

   return st;
}