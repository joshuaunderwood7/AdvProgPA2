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
              << "This program was made for CSCI 3320 Program Assignment 1 Spring 2013:"
              << "By: Joshua Underwood"
              << std::endl << std::endl 
              << "This program is made to use templates" << std::endl    
              << "It calulates zeros of non-linear functions using the Newton and Secant" << std::endl
              << "Methods.  These methods are implemented with templates." << std::endl;
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
