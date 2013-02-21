#include "matrix.h"
#include <cstdlib>
#include <iostream>


int main(int argc, char** argv)
{
    matrix<int> enterThe(2,2);
    enterThe[0][0] = 0;
    enterThe[1][0] = 1;
    enterThe[0][1] = 1;
    enterThe[1][1] = 0;
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
