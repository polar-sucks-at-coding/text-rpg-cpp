#ifndef MENU_H
#define MENU_H
#include <string>

typedef unsigned int uint;

enum MenuType
{
    Main,
    CharacterCreator,
    GenderPicker,
    Settings

};


class Menu
{
    MenuType type;
    uint amount_of_options;
    std::string title = "";
    std::string subtext = "";
    void typeMenuSubtext();
    void typeMenuTitle();
    void createOptions();
    void assignVariables(int amount_of_options = 0, std::string title = "", std::string subtext = "");
    public:
    void doEverything();
    void typeTitleAndSub();
    Menu(MenuType type);
    uint player_input;
    int returnPlayerInput();
};

#endif