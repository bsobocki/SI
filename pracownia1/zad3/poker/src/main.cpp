#include <iostream>
#include <fstream>
#include <poker/poker.hpp>

int main()
{
   Game game(100000, STANDARD_GAME);
   state st = game.launch();

   std::cout << "\nnumber of games: " << st.numOfGames << std::endl;
   std::cout << std::endl;
   std::cout << "blotkarz wins: " << st.blotkarzWins << std::endl;
   std::cout << "figurant wins: " << st.figurantWins << std::endl;
   std::cout << std::endl;
   std::cout << "szanse blotkarza: " << ((double)st.blotkarzWins / (double)st.numOfGames) * 100 << "%" << std::endl;
   std::cout << "szanse figurants: " << ((double)st.figurantWins / (double)st.numOfGames) * 100 << "%" << std::endl;
   return 0;
}