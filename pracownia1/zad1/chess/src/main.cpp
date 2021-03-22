#include <iostream>
#include <fstream>
#include <chess/chess.hpp>

std::string getLayout(std::string line)
{
   std::string layout = line.substr(0,1);
   line = line.substr(line.find(' ')+1);
   layout += line.substr(0,2);
   line = line.substr(line.find(' ')+1);
   layout += line.substr(0,2);
   line = line.substr(line.find(' ')+1);
   layout += line.substr(0,2);
   return layout;
}

int main(int argc, const char ** argv)
{
   std::string line;
   std::ifstream iFile("zad1_input.txt");
   std::ofstream oFile("zad1_output.txt");

   while(std::getline(iFile, line))
   {
      chess ch(getLayout(line));
      oFile<<ch.getMinNumOfMoves()<<std::endl;
      if (argc > 1)
      {
         std::cout<<std::endl<<line<<std::endl<<std::endl;
         ch.printSteps();
         std::cout<<"\n=====================================\n";
         std::cout<<"=====================================\n\n";
      }
   }


   return 0;
}