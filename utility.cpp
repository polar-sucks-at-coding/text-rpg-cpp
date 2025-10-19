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
std::string message = "This isn't implemented yet.";

for (std::size_t i = 0; i < message.size(); i++)
{
    std::cout << message[i] << std::flush;

    std::this_thread::sleep_for(std::chrono::milliseconds(Setting::typing_speed->value));
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
