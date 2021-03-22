#include "poker_card.hpp"

struct card_deck
{
   static const std::vector<card_color::color> colors;

   card_deck(const std::vector<size_t> & _figures);
   void randomCards();
   std::string asString();

   std::vector<size_t> figures;
   std::vector<poker_card> deck;
   std::vector<poker_card> hand;
};

class Figurant : public card_deck
{
public:
   Figurant();
};

class Blotkarz : public card_deck
{
public:
   Blotkarz(bool specialDeck);
};