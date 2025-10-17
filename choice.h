#ifndef CHOICE_H
#define CHOICE_H
#include <string>

typedef unsigned int uint;

class Choice
{
    bool available;
    std::string text;

    public:
    Choice(std::string name_param, bool event_or_menu, uint choice_number);
    void typeText();
    void assignText(std::string text_param);
    void typeNumberOfChoice(uint choice_number);
};

#endif