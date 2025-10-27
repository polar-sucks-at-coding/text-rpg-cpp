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


    //Assigning the menu variables based on its type.
    switch (type)
    {
        case Main: assignVariables(3, "Main Menu"); break;
        case CharacterCreator: assignVariables(1 +1, "Character Creator", "Pick what you want to decide about your character."); break;
        case GenderPicker: assignVariables(3 +1, "Gender Picker"); break;
    }
    //If amount_of_options has a +1 or +2, that is for the reset and/or finish options.

    //Typing the menu's title and subtext if it has them.
    if (this->title != "")
    {
        this->typeMenuTitle();
    }
    if (this->subtext != "")
    {
        this->typeMenuSubtext();
    }
    //Creating the options for this menu that the player will choose from.
    this->createOptions(type);

    //Getting player input and assigning "player_input" that value so that we can access it from outside the Menu class.
    this->player_input = Utility::getPlayerChoice(this->amount_of_options);
    
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

