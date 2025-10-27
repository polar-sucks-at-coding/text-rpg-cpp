#include <pthread.h>
#include <unistd.h>
#include "character.h"
#include "menu.h"
#include "utility.h"

void createNewGame()
{
    Gender player_gender = Neutral;
    int gender_picker_output;
    
    bool toilet = 1;
    while (toilet)
    {
        Menu* character_creator = new Menu(CharacterCreator);

        switch (character_creator->returnPlayerInput())
        {
            case 1:
            {
                bool skibidi = 1;
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
                    
                    Menu* gender_picker = new Menu(GenderPicker);

                    switch (gender_picker->returnPlayerInput())
                    {
                        case 1: player_gender = Male; break;
                        case 2: player_gender = Female; break;
                        case 3: player_gender = Neutral; break;
                        case 4: skibidi = 0; delete gender_picker; break;
                    }
                }
            }
            delete character_creator;
            break;
    
            case 2: toilet = 0; delete character_creator; break;

            default: Utility::typeText("amount_of_options not assigned correctly to character creator."); break;
        }
    }
    
    //Player pointer is created in character.h as static, this actually creates the Character object for it.
    player = new Character(Player, player_gender);
    
}

int main()
{
    Utility::clearHistory();

    bool fuck = 1;
    while (fuck)
    {
        Menu* main_menu = new Menu(Main);
        switch (main_menu->returnPlayerInput())
        {
            case 1: createNewGame(); fuck = 0; break;
            
            default: Utility::notImplemented(); break;
        }
        delete main_menu;
    }    

    player->reportStats();


    //This is where code to start the game's prologue will go when said code actually exists.

    
    return 0;
}
