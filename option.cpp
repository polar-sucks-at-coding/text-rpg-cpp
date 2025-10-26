#include <pthread.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include "option.h"
#include "menu.h"
#include "utility.h"

Option::Option(MenuType menu_type, int option_number, int max_option_amount)
{
    switch (menu_type) 
    {

        case GenderPicker:
            switch (option_number) 
            {
                case 1: assignText("Male (he/him/his)"); break;
                case 2: assignText("Female (she/her)"); break;
                case 3: assignText("Neutral (they/them/their)"); break;
                case 4: assignText("Finish"); break;
            }
        break;
        case CharacterCreator:
            switch (option_number)
            {
                case 1: assignText("Gender"); break;
                case 2: assignText("Start the game"); break;
            }
        break;
        case Main:
             switch (option_number)
             {
                case 1: assignText("New Game"); break;
                case 2: assignText("Load Game"); break;
                case 3: assignText("Settings"); break;
                default: assignText("Invalid Option"); break;
             }
        break;
    }
};

void Option::assignText(std::string text_param)
{
    this->text = text_param;
}

void Option::typeNumber(int option_number)
{
    std::cout << option_number;
}

void Option::typeOption(int option_number)
{
    typeNumber(option_number);
    Utility::typeText(") ", 0);
    Utility::typeText(this->text);
}

