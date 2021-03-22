#include <string>
#include <vector>
#include <unordered_set>
#include <memory>
#include "layout.hpp"

enum move_direction {NONE, LEFT_UP, LEFT, LEFT_DOWN, UP, DOWN, RIGHT_UP, RIGHT, RIGHT_DOWN};
enum chess_color {WHITE, BLACK};


bool belongsToChessBoard(const std::string & pos);
bool isFigureOn(const std::string & layout, const std::string & pos);

Layouts possibleWKingMoveLayouts(const std::string & layout);
Layouts possibleBKingMoveLayouts(const std::string & layout);
Layouts possibleWRookMoveLayouts(const std::string & layout);

bool canWKingMove(const std::string & layout, const std::string & pos);
bool canBKingMove(const std::string & layout, const std::string & pos);
bool canWRookMove(const std::string & layout, const std::string & pos);

bool isBKingCheck(const std::string & layout, const std::string & pos);
bool isWKingCheck(const std::string & layout, const std::string & pos);

size_t dist(const std::string & p1, const std::string & p2);
move_direction getWRookMoveDirection(const std::string & from, const std::string & to);