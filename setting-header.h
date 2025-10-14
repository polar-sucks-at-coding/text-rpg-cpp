#ifndef SETTING_HEADER_H
#define SETTING_HEADER_H
#include <vector>
#include <string>

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
    static void resetSettings();
     static std::vector<Setting*> settings;
};


#endif