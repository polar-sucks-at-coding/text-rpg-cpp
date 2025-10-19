#include "classless.h"
#include "utility.h"
#include "setting.h"


void changeSettings()
{
    while (1)
    {
        Utility::typeText("Settings");
        Utility::doubleSpace();
        Setting::createSettingChoices();

        int player_choice;
        std::cin >> player_choice;

        if (player_choice <= Setting::amount_of_settings + 2)
        {
            if (player_choice == 1)
            {
                Setting::typing_speed->value = 101 - Utility::slider(1, 100);
            }
            else if (player_choice == 2)
            {
                resetSettings();
            }
            else if (player_choice == 3)
            {
                break;
            }
        }
        else 
        {
            Utility::typeText("Setting doesn't exist.");
        }
    }
}

void resetSettings()
{
    for (Setting* setting : Setting::settings)
    {
        setting->value = setting->default_value;
    } 
}