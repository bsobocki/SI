#include "poker_card.hpp"

const symbols card_figure::ascii = {"J", "Q", "K", "A"};
const symbols card_color::ascii = { "♤", "♥", "♦", "♧"};

std::string card_color::asString(size_t colorNum)
{
   return ascii[colorNum];
}

std::string card_figure::asString(size_t cardNum)
{
   return cardNum <= 10 ? std::to_string(cardNum) : ascii[cardNum-figure::J] ;
}

std::string poker_card::asString()
{
   size_t colorNum = color;
   return card_figure::asString(figure) + card_color::asString(colorNum);
}

bool poker_card::operator==(const poker_card & card)
{
   return color == card.color and figure == card.figure;
}

bool poker_card::operator!=(const poker_card & card)
{
   return not (*this == card);
}

poker_card::operator std::string ()
{
   return asString();
}