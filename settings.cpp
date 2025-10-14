#include "header.h"

uint Setting::default_typing_speed = 50;

uint Setting::amount_of_settings = 1;

Setting* Setting::typing_speed = new Setting("typing_speed");

std::vector<Setting*> Setting::settings;

Setting::Setting(std::string name)
{
    this->name = name;
    
    if (this->name == "typing_speed")
    {
        this->value = default_typing_speed;
    }
    settings.push_back(this);
}

void Setting::resetSettings()
{
    for (Setting* setting : settings)
    {
        if (setting->name == "typing_speed")
        {
            setting->value = default_typing_speed;
        }
    } 
}

