#include <iostream>
#include <fstream>
#include <string>
#include <logical_images/logical_image.hpp>

int main()
{
   std::ofstream oFile("zad5_output.txt");
   Config config = createConfigFromInputFile("zad5_input.txt");
   oFile << logical_image(config).asString();
}