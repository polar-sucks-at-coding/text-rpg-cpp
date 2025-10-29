#include <pthread.h>
#include <unistd.h>
#include "character.h"
#include "menu.h"
#include "setting.h"
#include "utility.h"

void createNewGame()
{
    Gender player_gender = Neutral;
    int gender_picker_output;
    
    bool toilet = 1;
    Menu* character_creator = new Menu(CharacterCreator);
    while (toilet)
    {
        character_creator->doEverything();

        switch (character_creator->returnPlayerInput())
        {
            case 1:
            {
                bool skibidi = 1;

                Menu* gender_picker = new Menu(GenderPicker);

                while (skibidi)
                {
                    Utility::typeText("Current gender: ", 0);
                    switch(player_gender)
                    {
                        case Male: Utility::typeText("Male"); break;
                        case Female: Utility::typeText("Female"); break;
                        case Neutral: Utility::typeText("Neutral"); break;
                        case Inanimate: Utility::typeText("Inanimate"); break;
                    }
                    
                    gender_picker->doEverything();

                    switch (gender_picker->returnPlayerInput())
                    {
                        case 1: player_gender = Male; break;
                        case 2: player_gender = Female; break;
                        case 3: player_gender = Neutral; break;
                        case 4: player_gender = Inanimate; break;
                        case 5: skibidi = 0; break;
                    }
                }
                delete gender_picker;
            }
            break;
    
            case 2: toilet = 0; break;

            default: Utility::typeText("amount_of_options not assigned correctly to character creator."); break;
        }
    }
    delete character_creator;
    
    //Player pointer is created in character.h.
    player = new Character(Player, player_gender);
    
}

void createSettings()
{
    int fuck = 1;
    Menu* settings = new Menu(Settings);
    while (fuck)
    {
        settings->doEverything();

        switch (settings->returnPlayerInput())
        {
            case 1: 
            {
                //"typing_speed" is actually the delay between each character appearing in milliseconds, so subtracting from 101.
                Setting::typing_speed = 101 - Utility::slider(1, 100);
            }
            break;
            case Setting::amount_of_settings + 1: Setting::resetSettings(); break;
            case Setting::amount_of_settings + 2: fuck = 0; break;
        }
    }
    delete settings;
   
}

int main()
{
    Utility::clearHistory();

    bool fuck = 1;
    Menu* main_menu = new Menu(Main);
    while (fuck)
    {
        main_menu->doEverything();

        switch (main_menu->returnPlayerInput())
        {
            case 1: createNewGame(); fuck = 0; break;

            case 3: createSettings(); break;
            
            default: Utility::notImplemented(); break;
        }
    }    
    delete main_menu;

    player->reportStats();
    Utility::typeText(player->pronoun1);


    //This is where code to start the game's prologue will go when said code actually exists.

    
    return 0;
}
