#include <filesystem>
#ifndef SOME_CLASS_H
#include <iostream>
typedef unsigned int uint;

void makeSpace();
void doubleSpace();
void notImplemented();
void clearHistory();

static uint typing_speed = 30; //it's actually the delay between each individual letter, but yk

#define CHOICE_H

class Choice
{
    bool available;
    std::string text;

    public:

    void constructor();
    Choice(std::string name_of_menu_param, uint choice_number);
    void typeText();
    void assignText(std::string text_param);
    void typeNumberOfChoice(uint choice_number);

    private:

};

class Character
{
    public: std::string type;
    uint HP;
    uint mana;
    uint STR;
    uint DEX;
    uint CON;
    uint INT;
    uint WIS;
    uint CHA;
    std::string gender;
    std::string name;
    std::string pronoun1;
    std::string pronoun2;
    std::string pronoun3;

    public:
    Character(std::string type_param, std::string gender_param);
    void baseStatAssigner();
    void pronounAssigner();
};

class Menu
{
    std::string text;
    std::string name;
    uint amount_of_choices;
    std::string valid_menu_list = "main_menu main_character_creator gender_picker stat_selection short_stat_selection";
    public:
    Menu(std::string name_param);
    void choiceCreator();
    std::string getPlayerChoice();
    uint getPlayerIntChoice();
    void statReporter(Character* character);
    public:void mainCharacterCreator();
    void genderPicker();
    void mainMenu();
    void typeMenuText();
    void assignTextAndType(std::string text);
    void statSelection();
};


static Character* main_character;

static std::string most_recent_input;

#endif

