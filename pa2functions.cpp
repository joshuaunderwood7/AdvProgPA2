#include "pa2functions.h"
#include <cstdio>
#include <iostream>


/* moved to pa1templates
template <typename T>
bool underwood::DISPLAY_ROW(const T& a, const T& b, const T& c) {...}
*/

bool underwood::GREETING(void)
{
    std::cout << "Greetings user." << std::endl
              << "This program was made for CSCI 3320 Program Assignment 2 Spring 2013:"
              << "By: Joshua Underwood"
              << std::endl << std::endl 
              << "Class requirements" << std::endl
<< "Write a general template and a specialization for a matrix class. Your matrix classes must" << std::endl
<< "be based on dynamic arrays that are allocated using operator new. In addition, your" << std::endl
<< "classes must include the following members." << std::endl
<< "1. Constant members to return the matrix dimensions." << std::endl
<< "2. Overloaded operator [ ] to return a matrix cell. Notice that the syntax for returning a" << std::endl
<< "cell is m[i][j], where m is a matrix, and i and j are the row-column indices" << std::endl
<< "respectively." << std::endl
<< "3. T** data member that represents a pointer to a dynamically allocated matrix." << std::endl
<< "4. Overloaded operator << to display a matrix in a formatted tabular form." << std::endl
<< "5. The specialization will be for the type int." << std::endl
<< "Program requirements" << std::endl
<< "1. Present the user with a greeting." << std::endl
<< "2. Read the data (V and E) from a file passed to the program in argv[1]." << std::endl
<< "3. Instantiate the matrix class with the data." << std::endl
<< "4. Display the matrix." << std::endl
<< "5. Prompt for and get vertices u and v." << std::endl
<< "6. Compute a shortest path p between u and v" << std::endl
<< "7. Display the value of the shortest path that your program computed." << std::endl;
    return true;
}

/*
bool underwood::FINISH_TABLE(void)
{
    std::cout << std::setfill('-') << std::setw(54) << "-" << std::endl;
    return true;
}
*/

bool underwood::ENTER_TO_CONTINUE(void)
{
    std::cout << "Press ENTER to continue.\n"; std::getchar();
    return true;   
}
