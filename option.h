#ifndef CHOICE_H
#define CHOICE_H
#include "menu.h"
#include <string>

typedef unsigned int uint;

class Menu_Option
{
    std::string text;
    void assignText(std::string text_param);
    void caseAssignText(int option_number, std::string text_param);
    public:
        void typeNumber(int option_number);
        void typeOption(int option_number);
        Menu_Option(MenuType menu_type, int option_number, int max_option_amount);

};

#endif