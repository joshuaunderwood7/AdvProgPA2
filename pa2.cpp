#include "pa2functions.h"
#include "matrix.h"
#include <cstdlib>
#include <iostream>
#include <fstream>


int main(int argc, char** argv)
{
  if(argc == 2)
  {
    underwood::GREETING();

    std::ifstream inputFile;
    inputFile.open("input.txt", std::ios::in);

    if(inputFile.is_open())
    {
        matrix<int> neo(inputFile);
        inputFile.close();
        std::cout << neo;
        size_t u,v;
        underwood::PROMPT_U_V(u,v);
        std::cout << "The shortest path from " << u << " to " << v << "; p = "
                  << CALCULATE_SHORTEST_PATH(neo, 0, 1) << std::endl;
        return EXIT_SUCCESS;
    }
    else 
    {
        std::cout << "Failed to open file\n";
        return 2;
    }

  }

  else
  {

    std::cerr << "enter filename as argument\n";
    return 1;

  }

}
