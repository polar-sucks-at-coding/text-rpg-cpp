#include <pthread.h>
#include <unistd.h>
#include "character.h"
#include "menu.h"
#include "utility.h"

void createNewGame()
{
    //Creating temporary variables for assigning stuff.
    Gender player_gender = Neutral;
    int gender_picker_output;

    //Creating the character creator menu.
    
    //Setting up a loop for the character_creator.
    bool toilet = 1;
    while (toilet)
    {
        //Creating character_creator
        Menu* character_creator = new Menu(CharacterCreator);

        //Receiving the user input
        switch (character_creator->returnPlayerInput())
        {
            case 1:
            {
                //Setting up another loop, but this time for the gender picker.
                bool skibidi = 1;
                while (skibidi)
                {
                    //Telling the player what the current gender is. "Neutral" by default.
                    Utility::typeText("Current gender: ", 0);
                    switch(player_gender)
                        {
                            case Male: Utility::typeText("Male"); break;
                            case Female: Utility::typeText("Female"); break;
                            case Neutral: Utility::typeText("Neutral"); break;
                            case Inanimate: Utility::typeText("Inanimate"); break;
                        }
                    
                    //Creating the gender picker menu.
                    Menu* gender_picker = new Menu(GenderPicker);

                    //Assigning the gender based on player input, and quitting the menu and deleting it if the appropriate input is given.
                    switch (gender_picker->returnPlayerInput())
                    {
                        case 1: player_gender = Male; break;
                        case 2: player_gender = Female; break;
                        case 3: player_gender = Neutral; break;
                        case 4: skibidi = 0; delete gender_picker; break;
                    }
                }
            }
            //Deleting character creator because we're going to make a new one.
            delete character_creator;
            break;
            
            //The "Finish" case. Exits out of the character creator and deletes it.
            case 2: toilet = 0; delete character_creator; break;

            //Just in case somehow the character creator gets created wrong.
            default: Utility::typeText("amount_of_options not assigned correctly to character creator."); break;
        }
    }
    
    //Player pointer is created in character.h as static, this actually creates the Character object for it.
    player = new Character(Player, player_gender);
    
}

int main()
{
    //Clearing terminal history
    Utility::clearHistory();

    //Creating a variable for looping the main menu
    bool fuck = 1;
    while (fuck)
    {
        Menu* main_menu = new Menu(Main);
        switch (main_menu->returnPlayerInput())
        {
            //Calls function to create the menus used in starting a new game.
            case 1: createNewGame(); fuck = 0; break;
            
            //Loading the game or settings not implemented just yet, so giving output to clarify that.
            default: Utility::notImplemented(); break;
        }
        //Deleting main_menu once we're done with it.
        delete main_menu;
    }    

    //Checking if the gender assignment worked as intended.
    player->reportStats();


    //This is where code to start the game's prologue will go when said code actually exists.

    
    return 0;
}
