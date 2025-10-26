#include <pthread.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include "character.h"
#include "option.h"
#include "utility.h"
#include "menu.h"

Menu::Menu(MenuType type)
{
    /*Menu Template
        Title
    Subtext
    (Options)
    */

    switch (type)
    {
        case Main: assignVariables(3, "Main Menu"); break;
        case CharacterCreator: assignVariables(1 +1, "Character Creator", "Pick what you want to decide about your character."); break;
        case GenderPicker: assignVariables(3 +1, "Gender Picker", "Pretty self-explanatory"); break;
    }
    /*If amount_of_options has a +1 or +2, that is for the reset and/or finish options.*/

    if (this->title != "")
    {
        this->typeMenuTitle();
    }
    if (this->subtext != "")
    {
        this->typeMenuSubtext();
    }
    this->createOptions(type);

    this->exit_value = Utility::getPlayerChoice(this->amount_of_options);
    
}

void Menu::assignVariables(int amount_of_options, std::string title, std::string subtext)
{
    this->amount_of_options = amount_of_options;
    this->title = title;
    this->subtext = subtext;

}

void Menu::createOptions(MenuType type)
{
    for (int i = 1; i < this->amount_of_options + 1; i++)
    {
        Option* option = new Option(type, i, this->amount_of_options);
        option->typeOption(i);
        delete option;
    }  
}

void Menu::typeMenuTitle()
{

    std::cout << "      ";
    Utility::typeText(this->title);
    Utility::makeSpace();
}

void Menu::typeMenuSubtext()
{
    Utility::typeText(this->subtext);
    Utility::doubleSpace();
}

