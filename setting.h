#ifndef SETTING_H
#define SETTING_H
#include <vector>
#include <string>

typedef unsigned int uint;

class Setting
{
    public:

    static Setting* typing_speed;
    static uint amount_of_settings;
    int default_value;
    uint value;
    Setting(int default_value);
    void resetSettings();
    static void createSettingChoices();
    static void createSettings();
    void changeSettings();
    static std::vector<Setting*> settings;
};


#endif