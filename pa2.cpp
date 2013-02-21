#include "matrix.h"
#include <cstdlib>
#include <iostream>


int main(int argc, char** argv)
{
    matrix<int> enterThe(3,3);
    for(int i = 0; i < enterThe.getDemRows(); ++i)
        for(int j = 0; j < enterThe.getDemCols(); ++j)
            enterThe[i][j] = (i+5 * j+1);

    matrix<int> neo(3,3);
    for(int i = 0; i < neo.getDemRows(); ++i)
        for(int j = 0; j < neo.getDemCols(); ++j)
            neo[i][j] = (i+9 * j+7);


    std::cout << enterThe << std::endl;
    std::cout << neo << std::endl;
    std::cout <<  (enterThe * neo)  << std::endl;

    return EXIT_SUCCESS;
}
