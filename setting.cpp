#include "classless.h"
#include "setting.h"
#include "character.h"
#include "utility.h"
#include "choice.h"

uint Setting::amount_of_settings = 1;

std::vector<Setting*> Setting::settings;

Setting* Setting::typing_speed = new Setting(50);

Setting::Setting(int default_value)
{
    this-> default_value = default_value;
    this->value = this->default_value;
    settings.push_back(this);
}

void Setting::createSettingChoices()
{
    Utility::makeSpace();

    for (uint i = 1; i < amount_of_settings + 3; i++)
    {
        Choice* choice = new Choice("settings", 1, i);
    }   
}

