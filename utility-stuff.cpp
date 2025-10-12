#include <ostream>
#include <pthread.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <thread>
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
    std::string message = "This isn't implemented yet.";

    for (std::size_t i = 0; i < message.size(); i++)
        {
            std::cout << message[i] << std::flush;

            std::this_thread::sleep_for(std::chrono::milliseconds(typing_speed));
        }
}

void clearHistory()
{
    #ifdef __linux__
    system("clear");

    #elif defined(_WIN32)
    system("cls");
    #endif
}

void changeTypingSpeed(uint speed)
{
    typing_speed = speed;
}