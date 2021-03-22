#include <string>
#include <vector>
#include <iostream>

enum fig {PLAYER_COLOR, W_KING_LETTER, W_KING_NUMBER, W_ROOK_LETTER, W_ROOK_NUMBER, B_KING_LETTER, B_KING_NUMBER};

const char opponentOf(const char playerColor);
const char getPlayerColor(const std::string & lay);
const std::string getWKingPosition(const std::string & lay);
const char getWKingLetter(const std::string & lay);
const char getWKingNumber(const std::string & lay);
const std::string getBKingPosition(const std::string & lay);
const char getBKingLetter(const std::string & lay);
const char getBKingNumber(const std::string & lay);
const std::string getWRookPosition(const std::string & lay);
const char getWRookLetter(const std::string & lay);
const char getWRookNumber(const std::string & lay);

struct Layouts : public std::vector<std::string>
{
   Layouts()=default;
   Layouts(std::vector<std::string> layouts);
   operator std::string() const;
};