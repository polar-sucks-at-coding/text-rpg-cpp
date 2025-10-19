#ifndef MENU_H
#define MENU_H
#include <string>
#include "character.h"

class Menu
{
    std::string text;
    std::string name;
    uint amount_of_choices;
    public:
    Menu(std::string name_param);
    void choiceCreator();
    void mainCharacterCreator();
    void genderPicker();
    void mainMenu();
    void assignTextAndType(std::string text);
    void statSelection();
    std::string createChoicesAndGetPlayerChoice();
};

#endif