#include "matrix.h"
#include <cstdlib>
#include <iostream>


int main(int argc, char** argv)
{
    matrix<int> enterThe(3,3);
    for(int i = 0; i < enterThe.getDemRows(); ++i)
        for(int j = 0; j < enterThe.getDemCols(); ++j)
            enterThe[i][j] = (i+5 * j+1);

    std::cout << enterThe << std::endl;
    std::cout << enterThe.getlocation(2,2) << std::endl;
    //std::cout << enterThe.getDemRows() << std::endl;
    //std::cout << enterThe.getDemCols() << std::endl;
    return EXIT_SUCCESS;
}
