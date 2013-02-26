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
    inputFile.open(argv[1], std::ios::in);

    if(inputFile.is_open())
    {
        matrix<int> neo(inputFile);
        inputFile.close();
        std::cout << neo;
        size_t u,v;
        underwood::PROMPT_U_V(u,v);
        std::cout << "The shortest path from " << u << " to " << v << "; p = "
                  << CALCULATE_SHORTEST_PATH(neo, u, v) << std::endl;
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
    std::cerr << "File must be of format:\n"
              << "1. The input data will be in the following format within the file.\n"
              << "6\n"
              << "// The number of vertices in the vertex set V.\n"
              << "1 2 3 4 5 6\t"
              << "// The vertex set, V, space delimited.\n"
              << "12\t" << "// The number of edges in th edge set E.\n"
              << "1 3\t" << "// Edge (u, v), one per line, u and v space delimited\n"
              << "1 4\t" << "......" << std::endl;
    return 1;

  }
}
