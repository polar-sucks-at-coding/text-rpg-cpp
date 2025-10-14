#include <ostream>
#include <pthread.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <thread>
#include "utility-header.h"
#include "setting-header.h"




void Utility::makeSpace()
{
    std::cout << "\n";
}

void Utility::doubleSpace()
{
    std::cout << "\n\n";
}

void Utility::notImplemented()
{
    std::string message = "This isn't implemented yet.";

    for (std::size_t i = 0; i < message.size(); i++)
        {
            std::cout << message[i] << std::flush;

            std::this_thread::sleep_for(std::chrono::milliseconds(getTypingSpeed()));
        }
}

void Utility::clearHistory()
{
    #ifdef __linux__
    system("clear");

    #elif defined(_WIN32)
    system("cls");
    #endif
}

void Utility::changeTypingSpeed(uint speed)
{
    Setting::typing_speed->value = speed;
}

uint Utility::getTypingSpeed()
{
    return Setting::typing_speed->value;
}