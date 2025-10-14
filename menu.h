#ifndef MENU_H
#define MENU_H
#include <string>
#include "character.h"

class Menu
{
    std::string text;
    std::string name;
    uint amount_of_choices;
    std::string valid_menu_list = "main_menu main_character_creator gender_picker stat_selection short_stat_selection";
    public:
    Menu(std::string name_param);
    void settingsMenu();
    void choiceCreator();
    std::string getPlayerChoice(bool clear_history);
    uint getPlayerIntChoice(bool clear_history);
    void statReporter(Character* character);
    void mainCharacterCreator();
    void genderPicker();
    void mainMenu();
    void typeMenuText();
    void assignTextAndType(std::string text);
    void statSelection();
    uint slider(uint min_value, uint max_value);
    std::string createChoicesAndGetPlayerChoice();
};

#endif