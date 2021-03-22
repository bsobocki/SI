#include "card_deck.hpp"

bool isStraightFlush(const std::vector<poker_card> & hand);
bool isFlush(const std::vector<poker_card> & hand);
bool isFourOfAKind(const std::vector<poker_card> & hand);
bool isFullHouse(const std::vector<poker_card> & hand);
bool isStraight(const std::vector<poker_card> & hand);
bool isThreeOfAKind(const std::vector<poker_card> & hand);
bool isTwoPairs(const std::vector<poker_card> & hand);
std::vector<size_t> sortedFigureCounters(const std::vector<poker_card> & hand);
