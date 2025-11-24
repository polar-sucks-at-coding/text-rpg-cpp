#include <pthread.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include "character.h"
#include "setting.h"
#include "utility.h"
#include "menu.h"

Menu::~Menu()
{
    for (Menu_Option* option : options)
    {
        delete option;
    }
}

Menu_Option* Menu::getOptionFromID(int _id)
{
    for (Menu_Option* menu_option : options)
    {
        if (_id == menu_option->ID + 1) return menu_option;
    }
    Menu_Option* sex;
    std::cout << "fucking didnt find option with id idiot"; return sex;
}

int Menu::getChoice()
{
    int player_choice = Utility::getPlayerChoice(options.size());

    if (getOptionFromID(ID_tracker)->func != NULL) getOptionFromID(ID_tracker)->active = 1;

    return player_choice;
}

void Menu::addOption(const std::string& _content, bool _ends_menu, void (*_func)())
{
    options.push_back(new Menu_Option(_content, ID_tracker, _ends_menu, _func));
    ID_tracker++;
}

void Menu::addTitle(const std::string& _content)
{
    titles.emplace_back(_content);
}

void Menu::addSubText(const std::string& _content)
{
    subtexts.emplace_back(_content);
}

void Menu::displayOptions()
{
    for (int i = 1; i < (options.size() + 1); i++)
    {
        Utility::typeText(std::to_string(i), 0);
        Utility::typeText(") ", 0);
        
        Utility::typeText(getOptionFromID(i)->content);
    }
}

void Menu::displayTitles()
{
    for (std::string title : titles)
    {
        Utility::typeText(title);
        Utility::makeSpace();
    }
}

void Menu::displaySubtexts()
{
    for (std::string subtext : subtexts)
    {
        Utility::typeText(subtext);
    }
}

void Menu::displayAll()
{
    displayTitles();
    displaySubtexts();
    displayOptions();
    
}

void Menu::play()
{
    while (1)
    {
        displayAll();
        player_input = getChoice();

        if (getOptionFromID(player_input)->active) getOptionFromID(player_input)->func();
        
        if (getOptionFromID(player_input)->ends_menu) break;
    }
    
}