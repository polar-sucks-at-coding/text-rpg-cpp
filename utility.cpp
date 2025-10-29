#include <algorithm>
#include <cctype>
#include <ostream>
#include <pthread.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <thread>
#include "utility.h"
#include "setting.h"
#include <typeinfo>

bool Utility::isDigits(std::string str)
{
    for (char ch : str)
    {
        if (!std::isdigit(ch)) return false;
    }
    return true;
}

void Utility::reportInvalidOption()
{
    Utility::typeText("Not a valid option.");
}


uint Utility::getPlayerChoice(int amount_of_options, bool clear_history)
{
    std::string skibidi;
    if (clear_history == 1) Utility::clearHistory();
    while (1)
    {
        std::cin >> skibidi;

        if (!Utility::isDigits(skibidi)) {Utility::reportInvalidOption(); continue;}

        if (stoi(skibidi) > 0 && stoi(skibidi) <= amount_of_options) return stoi(skibidi);

        Utility::reportInvalidOption();
    }
    
}

//Allows to assign a value to a variable with a minimum and maximum.
uint Utility::slider(uint min_value, uint max_value)
{
    while (1)
    {
        typeText("Assign a number ", 0);
        typeText(std::to_string(min_value), 0);
        typeText(" through ", 0);
        typeText(std::to_string(max_value), 0);
        typeText(" for this value.", 0);
        Utility::makeSpace();

        uint value;

        std::cin >> value;

        //Checking if the value is actually within the bounds.
        if (min_value <= value && value <= max_value) return value;

        else Utility::typeText("The value you entered isn't within the available range.");
    }
}

//Types out all characters in a string smoothly.
void Utility::typeText(std::string text, bool make_space, int speed)
{
    //Checks the provided string's size 
    for (std::size_t i = 0; i < text.size(); i++)
    {
        //Outputs one character. 
        std::cout << text[i] << std::flush;
        //Makes the program stop for the given time, allowing the characters in the string to be typed one by one visibly.
        std::this_thread::sleep_for(std::chrono::milliseconds(speed));
    }
    if (make_space == 1)
    {
        Utility::makeSpace();
    }

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
    typeText("This isn't implemented yet.");
}

//Checks which system the user is on and types in the appropriate command to clear their terminal's history.
//Not sure how it works on devices besides Windows and Linux.
void Utility::clearHistory()
{
#ifdef __linux__
system("clear");

#elif defined(_WIN32)
system("cls");
#endif
}
