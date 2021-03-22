#include "rules.hpp"

enum game_type {STANDARD_GAME, SPECIAL_NUMBER_DECK};

struct state
{
   size_t figurantWins;
   size_t blotkarzWins;
   size_t numOfGames;
};

class Game
{
public:
   Game(size_t _numOfGames, game_type type);
   state launch();

private:
   size_t numOfGames;
   Figurant figurant;
   Blotkarz blotkarz;
};

size_t getScore(const std::vector<poker_card> & hand);