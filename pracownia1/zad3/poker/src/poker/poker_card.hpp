#pragma once

#include <vector>
#include <string>

using symbols = std::vector<std::string>;

struct card_color 
{
   enum color {SPADE, HEART, DIAMOND, CLUB};
   static std::string asString(size_t colorNum);

   static const std::vector<std::string> ascii;
};

struct card_figure
{
   enum figure {J=11, Q, K, A};
   static const std::vector<std::string> ascii;
   static std::string asString(size_t cardNum);
};

struct poker_card
{
   std::string asString();
   bool operator==(const poker_card & card);
   bool operator!=(const poker_card & card);
   operator std::string ();

   card_color::color color;
   size_t figure;
};