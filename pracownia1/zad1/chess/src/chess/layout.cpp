#include "layout.hpp"

Layouts::Layouts(std::vector<std::string> layouts)
{
   for (auto lay : layouts)
      push_back(lay);
}

Layouts::operator std::string() const
{
   std::string str = {};

   for(auto lay : *this)
      str += std::string(lay) + " ";
   
   return str;
}

const char opponentOf(const char playerColor)
{
   return playerColor == 'w' ? 'b' : 'w';
}

const char getPlayerColor(const std::string & lay)
{
   return lay[PLAYER_COLOR];
}

const std::string getWKingPosition(const std::string & lay)
{
   return lay.substr(W_KING_LETTER, 2);
}

const char getWKingLetter(const std::string & lay)
{
   return lay[W_KING_LETTER];
}

const char getWKingNumber(const std::string & lay)
{
   return lay[W_KING_NUMBER];
}

const std::string getBKingPosition(const std::string & lay)
{
   return lay.substr(B_KING_LETTER, 2);
}

const char getBKingLetter(const std::string & lay)
{
   return lay[B_KING_LETTER];
}

const char getBKingNumber(const std::string & lay)
{
   return lay[B_KING_NUMBER];
}

const std::string getWRookPosition(const std::string & lay)
{
   return lay.substr(W_ROOK_LETTER, 2);
}

const char getWRookLetter(const std::string & lay)
{
   return lay[W_ROOK_LETTER];
}

const char getWRookNumber(const std::string & lay)
{
   return lay[W_ROOK_NUMBER];
}