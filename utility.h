#ifndef UTLITY_H
#define UTLITY_H
#include <string>

typedef unsigned int uint;

class Utility
{
    public:
    static void makeSpace();
    static void doubleSpace();
    static void notImplemented();
    static void clearHistory();
    static void changeTypingSpeed(uint speed);
    static uint getTypingSpeed();
    static uint slider(uint min_value, uint max_value);
    static void typeText(std::string text);
    static std::string getPlayerChoice(bool clear_history = 1);
    static uint getPlayerIntChoice(bool clear_history = 1);
};

#endif