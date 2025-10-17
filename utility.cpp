#include <ostream>
#include <pthread.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <thread>
#include "utility.h"
#include "setting.h"

uint Utility::getPlayerIntChoice(bool clear_history)
    {
        uint player_decision;
        Utility::makeSpace();
        std::cin >> player_decision;
        Utility::makeSpace();

        if (clear_history == 1)
        {
            Utility::clearHistory();
        }

        return player_decision;
    }


std::string Utility::getPlayerChoice(bool clear_history)
    {
        std::string player_decision;
        Utility::makeSpace();
        std::cin >> player_decision;
        Utility::makeSpace();

        if (clear_history == 1)
        {
            Utility::clearHistory();
        }
        return player_decision;
    }

uint Utility::slider(uint min_value, uint max_value)
    {
        typeText("Assign a number ");
        typeText(std::to_string(min_value));
        typeText(" through ");
        typeText(std::to_string(max_value));
        typeText(" this value.");
        Utility::makeSpace();
        
        uint value;

        std::cin >> value;
        return value;
        
    }

void Utility::typeText(std::string text)
    {
        for (std::size_t i = 0; i < text.size(); i++)
        {
            std::cout << text[i] << std::flush;

            std::this_thread::sleep_for(std::chrono::milliseconds(Utility::getTypingSpeed()));
        }
        Utility::makeSpace();
    }

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