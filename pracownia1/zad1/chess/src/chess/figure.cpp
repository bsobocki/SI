#include "figure.hpp"
#include <cmath>
#include <algorithm>

bool belongsToChessBoard(const std::string & pos)
{
   return pos[0] >= 'a' and pos[0] <= 'h' and pos[1] >= '1' and pos[1] <='8'; 
}

bool isFigureOn(const std::string & layout, const std::string & pos)
{
  return getBKingPosition(layout) == pos or getWKingPosition(layout) == pos or getWRookPosition(layout) == pos;
}

Layouts possibleWRookMoveLayouts(const std::string & lay)
{
   Layouts lays;
   lays.reserve(16);
   const char nextPlayerColor = opponentOf(getPlayerColor(lay));

   for(auto letter : {"a", "b", "c", "d", "e", "f", "g", "h"})
   {
      std::string pos = letter;
      pos += getWRookNumber(lay);

      if (canWRookMove(lay, pos))
      {
         std::string p;
         p += nextPlayerColor;
         lays.push_back(p + getWKingPosition(lay) + pos + getBKingPosition(lay));
      }
   }

   for(auto number : {"1", "2", "3", "4", "5", "6", "7", "8"})
   {
      std::string pos;
      pos += getWRookLetter(lay);
      pos += number;

      if (canWRookMove(lay, pos))
      {
         std::string p;
         p += nextPlayerColor;
         lays.emplace_back(p + getWKingPosition(lay) + pos + getBKingPosition(lay));
      }
   }

   return lays;
}

bool canWRookMove(const std::string & lay, const std::string & pos)
{
   auto wKingPos = getWKingPosition(lay);
   auto wRookPos = getWRookPosition(lay);
   auto bKingPos = getBKingPosition(lay);

   if (pos == wRookPos)
      return false;

   if (dist(pos, bKingPos) ==1)
      return false;

   if (getWRookMoveDirection(wRookPos, pos) == getWRookMoveDirection(wRookPos, bKingPos))
      return dist(wRookPos, bKingPos) > dist(wRookPos, pos); 

   if (getWRookMoveDirection(wRookPos, pos) == getWRookMoveDirection(wRookPos, wKingPos))
      return dist(wKingPos, wRookPos) > dist(pos, wRookPos); 
   
   return true;
}

move_direction getWRookMoveDirection(const std::string & from, const std::string & to)
{
   if (from[0] == to[0])
   {
      if (from[1] < to[1])
         return move_direction::UP;
      return move_direction::DOWN;
   }

   if (from[1] == to[1])
   {
      if (from[0] < to[0])
         return move_direction::RIGHT;
      return move_direction::LEFT;
   }

   return move_direction::NONE;
}

size_t dist(const std::string & p1, const std::string & p2)
{
   if (p1[0] == p2[0]) return abs(p1[1] - p2[1]);
   return abs(p1[0] - p2[0]);
}

Layouts possibleWKingMoveLayouts(const std::string & layout)
{
   Layouts moves;
   moves.reserve(9);

   for (char l = getWKingLetter(layout)-1; l <= getWKingLetter(layout)+1; l++)
   {
      for (char n = getWKingNumber(layout)-1; n <= getWKingNumber(layout)+1; n++)
      {
         std::string pos;
         pos += l;
         pos += n;

         if (canWKingMove(layout, pos))
         {
            std::string p;
            p += opponentOf(getPlayerColor(layout));

            moves.push_back(p + pos + getWRookPosition(layout) + getBKingPosition(layout));
         }
      }
   }

   return moves;
}

Layouts possibleBKingMoveLayouts(const std::string & layout)
{
   Layouts moves;
   moves.reserve(9);

   for (char l = getBKingLetter(layout)-1; l <= getBKingLetter(layout)+1; l++)
   {
      for (char n = getBKingNumber(layout)-1; n <= getBKingNumber(layout)+1; n++)
      {
         std::string pos;
         pos += l;
         pos += n;

         if (canBKingMove(layout, pos))
         {
            std::string p;
            p += opponentOf(getPlayerColor(layout));

            moves.push_back(p + getWKingPosition(layout) + getWRookPosition(layout) + pos);
         }
      }
   }

   return moves;
}

bool canWKingMove(const std::string & layout, const std::string & pos)
{
   return belongsToChessBoard(pos) and not isFigureOn(layout, pos) and not isWKingCheck(layout, pos);
}

bool canBKingMove(const std::string & layout, const std::string & pos)
{
   return belongsToChessBoard(pos) and not isFigureOn(layout, pos) and not isBKingCheck(layout, pos);
}

bool isWKingCheck(const std::string & layout, const std::string & pos)
{
   for (char l = getBKingLetter(layout)-1; l <= getBKingLetter(layout)+1; l++)
      for (char n = getBKingNumber(layout)-1; n <= getBKingNumber(layout)+1; n++)
         if (pos[0] == l and pos[1] == n)
            return true;
   return false;
}

bool isBKingCheck(const std::string & layout, const std::string & pos)
{
   if (pos[0] == getWRookLetter(layout) or pos[1] == getWRookNumber(layout))
      return true;

   for (char l = getWKingLetter(layout)-1; l <= getWKingLetter(layout)+1; l++)
      for (char n = getWKingNumber(layout)-1; n <= getWKingNumber(layout)+1; n++)
         if (pos[0] == l and pos[1] == n)
            return true;

   return false;
}