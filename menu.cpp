#include <pthread.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include "character.h"
#include "option.h"
#include "setting.h"
#include "utility.h"
#include "menu.h"

Menu::Menu(MenuType type)
{
    this->type = type;

    switch (this->type)
    {
        case Main: assignVariables(3, "Main Menu"); break;
        case CharacterCreator: assignVariables(2 +1, "Character Creator", "Pick what you want to decide about your character."); break;
        case GenderPicker: assignVariables(4 +1, "Gender Picker"); break;
        case Settings: assignVariables(Setting::amount_of_settings + 2, "Settings"); break;
    }
    //If amount_of_options has a +1 or +2, that is for the reset and/or finish options.
}

void Menu::typeTitleAndSubAndCreateOptions()
{
    this->typeTitleAndSub();
    this->createOptions();
    this->player_input = Utility::getPlayerChoice(this->amount_of_options);
}

void Menu::typeTitleAndSub()
{
    if (this->title != "") this->typeMenuTitle();

    if (this->subtext != "") this->typeMenuSubtext();
}

int Menu::returnPlayerInput()
{
    return this->player_input;
}

void Menu::assignVariables(int amount_of_options, std::string title, std::string subtext)
{
    this->amount_of_options = amount_of_options;
    this->title = title;
    this->subtext = subtext;

}

//Creates options depending on the "amount_of_options" variable and types them out. Deletes them after.
void Menu::createOptions()
{
    for (int i = 1; i < this->amount_of_options + 1; i++)
    {
        Option* option = new Option(this->type, i, this->amount_of_options);
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

