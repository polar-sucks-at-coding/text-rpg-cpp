#include <ostream>
#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include "header.h"

void makeSpace()
{
    std::cout << std::endl;
}

void doubleSpace()
{
    std::cout << "\n\n";
}

void notImplemented()
{
    std::cout << "This isnt implemented yet\n";
}

void clearHistory()
{
    system("clear");
}