#ifndef HEADER_H
#define HEADER_H
#include <filesystem>
#include <iostream>

typedef unsigned int uint;

class Setting
{
    public:

    static uint amount_of_settings;
    static uint default_typing_speed;
    static Setting* typing_speed;
    uint value;
    std::string name;
    Setting(std::string name);
};

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
    void settingsMenu();
    void choiceCreator();
    std::string getPlayerChoice();
    uint getPlayerIntChoice();
    void statReporter(Character* character);
    void mainCharacterCreator();
    void genderPicker();
    void mainMenu();
    void typeMenuText();
    void assignTextAndType(std::string text);
    void statSelection();
};



static Character* main_character;

static std::string most_recent_input;

#endif

