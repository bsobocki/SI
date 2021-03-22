#include "card_deck.hpp"
#include <random>
 
namespace
{
   const std::vector<size_t> FULL_NUMBER_DECK = {2,3,4,5,6,7,8,9,10};
   const std::vector<size_t> FULL_FIGURE_DECK = {card_figure::J, card_figure::Q, card_figure::K,card_figure::A};
   const std::vector<size_t> SPECIAL_NUMBER_DECK = {8,9,10};
}

const std::vector<card_color::color> card_deck::colors
{
   card_color::SPADE, 
   card_color::HEART, 
   card_color::DIAMOND, 
   card_color::CLUB
};

card_deck::card_deck(const std::vector<size_t> & _figures):
   figures(_figures)
{
   for (auto color : colors)
      for (auto figure : figures)
         deck.push_back({color, figure});

   randomCards();
}

void card_deck::randomCards()
{
   std::random_device rd;
   std::mt19937 generator(rd());
   std::vector<size_t> indexes;
   hand = {};

   for (size_t i=0; i<deck.size(); i++)
      indexes.push_back(i);

   for (int i=0; i<5; i++)
   {
      std::uniform_int_distribution<size_t> randomCardIndex(0, indexes.size()-1);
      size_t randomIndex = randomCardIndex(generator);
      
      hand.push_back(deck[indexes[randomIndex]]);

      std::swap(indexes[indexes.size()-1], indexes[randomIndex]);
      indexes.resize(indexes.size()-1);
   }
}

std::string card_deck::asString()
{
   std::string str = "{ ";

   for(auto card : hand)
      str += std::string(card) + " ";

   str += "}";

   return str;
}

Figurant::Figurant(): card_deck(FULL_FIGURE_DECK)
{
}

Blotkarz::Blotkarz(bool specialDeck): 
   card_deck(specialDeck ? SPECIAL_NUMBER_DECK : FULL_NUMBER_DECK)
{
}