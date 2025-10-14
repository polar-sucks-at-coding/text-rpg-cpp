#ifndef UTLITY_HEADER_H
#define UTLITY_HEADER_H

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
};

#endif