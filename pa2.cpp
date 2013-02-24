#include "pa2functions.h"
#include "matrix.h"
#include <cstdlib>
#include <iostream>
#include <fstream>


int main(int argc, char** argv)
{
    underwood::GREETING();
    matrix<int> enterThe(2,2);
    enterThe[0][0] = 0;
    enterThe[1][0] = 1;
    enterThe[0][1] = 1;
    enterThe[1][1] = 0;

    std::ifstream inputFile;
    inputFile.open("input.txt", std::ios::in);

    if(inputFile.is_open())
    {
        std::cout << "reading file: 1\n";
        matrix<int> neo(inputFile);
        std::cout << "reading file: 2\n";
        inputFile.close();
        std::cout << "reading file: 3\n";
        std::cout << neo;
        return EXIT_SUCCESS;
    }
    else 
    {
        std::cout << "Failed to open file\n";
        return 1;
    }

/*
    for(int i = 0; i < enterThe.getDemRows(); ++i)
        for(int j = 0; j < enterThe.getDemCols(); ++j)
            enterThe[i][j] = (i%2 | j%2 & (i - j)%2);
*/
/*
    matrix<int> neo(3,3);
    for(int i = 0; i < neo.getDemRows(); ++i)
        for(int j = 0; j < neo.getDemCols(); ++j)
            neo[i][j] = (i+9 * j+7);
*/

    std::cout << enterThe << std::endl;
//    std::cout << neo << std::endl;
    std::cout << enterThe * enterThe << std::endl;;
//    std::cout << neo.getDemRows() << "x" << neo.getDemCols() << std::endl;


    return 0;
    return EXIT_SUCCESS;
}
