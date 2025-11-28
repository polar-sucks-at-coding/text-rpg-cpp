#pragma once
#include <string>
#include <vector>

typedef unsigned int uint;

class Menu_Option
{

    public:
    std::string content;
    int ID;
    bool active = false;
    void (*func)();
    void callOptionFunction();
    bool ends_menu;

    Menu_Option(std::string _content, int _ID, bool _ends_menu, void (*_func)() = NULL):
        content{_content},
        ID{_ID},
        func{_func},
        ends_menu{_ends_menu}
    {
        if (func != NULL) active = 1;
    }
};

class Menu
{
    public:
    int option_number;
    int player_input;
    int ID_tracker = 0;

    std::vector<Menu_Option*> options;
    std::vector<std::string> titles;
    std::vector<std::string> subtexts;

    ~Menu();
    Menu_Option* getOptionFromID(const int &_id);

    void addOption(const std::string& _content, const bool &_ends_menu = 0, void (*_func)() = NULL);
    void addTitle(const std::string& _content);
    void addSubText(const std::string& _content);
    void displayTitles();
    void displaySubtexts();
    void displayOptions();
    void displayAll();
    int getChoice();
    void play();

};