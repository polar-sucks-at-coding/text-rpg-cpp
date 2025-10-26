#ifndef UTLITY_H
#define UTLITY_H
#include <string>
#include "setting.h"

typedef unsigned int uint;

namespace Utility
{
void makeSpace();
void doubleSpace();
void notImplemented();
void clearHistory();
uint slider(uint min_value, uint max_value);
void typeText(std::string text, bool make_space = 1, int speed = Setting::typing_speed);
uint getPlayerChoice(int amount_of_options, bool clear_history = 0);
void invalidInput();
};

#endif