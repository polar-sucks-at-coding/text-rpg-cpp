#include <pthread.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include "option.h"
#include "menu.h"
#include "setting.h"
#include "utility.h"

Menu_Option::Menu_Option(MenuType menu_type, int option_number, int max_option_amount)
{
    switch (menu_type) 
    {
        case Settings:
        {
            switch (option_number)
            {
                case 1: this->assignText("Typing speed"); break;
                case Setting::amount_of_settings + 1: this->assignText("Reset Settings"); break;
                case Setting::amount_of_settings + 2: this->assignText("Finish"); break;
                //+1 and +2 are for the reset and finish options
            }
        }    
        break;

        case GenderPicker:
        {
            switch (option_number) 
            {
                case 1: assignText("Male (he/him/his)"); break;
                case 2: assignText("Female (she/her)"); break;
                case 3: assignText("Neutral (they/them/their)"); break;
                case 4: assignText("Inanimate (it/it/its)"); break;
                case 5: assignText("Finish"); break;
            }
        }  
        break;

        case CharacterCreator:
        {
            switch (option_number)
            {
                case 1: assignText("Gender"); break;
                case 2: assignText("Name"); break;
                case 3: assignText("Start the game"); break;
            }
        } 
        break;

        case Main:
        {
            switch (option_number)
            {
                case 1: assignText("New Game"); break;
                case 2: assignText("Load Game"); break;
                case 3: assignText("Settings"); break;
                default: assignText("Invalid Option"); break;
            }
        }
        break;
    }
};

void Menu_Option::assignText(std::string text_param)
{
    this->text = text_param;
}

void Menu_Option::typeNumber(int option_number)
{
    std::cout << option_number;
}

void Menu_Option::typeOption(int option_number)
{
    typeNumber(option_number);
    Utility::typeText(") ", 0);
    Utility::typeText(this->text);
}

