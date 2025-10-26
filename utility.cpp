#include <ostream>
#include <pthread.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <thread>
#include "utility.h"
#include "setting.h"

void Utility::invalidInput()
{
    Utility::typeText("Are you sure you entered right?");
}

uint Utility::getPlayerChoice(int amount_of_options, bool clear_history)
{
    int skibidi;
    std::cin >> skibidi;
    if (clear_history == 1)
    {
        Utility::clearHistory();
    }
    while (1)
    {
        if (skibidi > 0 && skibidi <= amount_of_options)
        {
            return skibidi;
        }
        else
        {
            Utility::typeText("Not a valid option.");
        }
    }
    
    
}

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

if (min_value <= value && value <= max_value)
{
    return value;
    break;
}

else  
{
    Utility::typeText("The value you entered isn't within the available range.");
}
}

}

void Utility::typeText(std::string text, bool make_space, int speed)
{
for (std::size_t i = 0; i < text.size(); i++)
{
std::cout << text[i] << std::flush;

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

void Utility::clearHistory()
{
#ifdef __linux__
system("clear");

#elif defined(_WIN32)
system("cls");
#endif
}
