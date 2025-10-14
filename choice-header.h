#ifndef CHOICE_HEADER_H
#define CHOICE_HEADER_H
#include <string>

typedef unsigned int uint;

class Choice
{
    bool available;
    std::string text;

    public:
    Choice(std::string name_of_menu_param, uint choice_number);
    void typeText();
    void assignText(std::string text_param);
    void typeNumberOfChoice(uint choice_number);
};

#endif