#include <pthread.h>
#include <unistd.h>
#include "character.h"
#include "menu.h"
#include "utility.h"

Character* main_character;

uint getMenuOutput(Menu* menu)
{
    return menu->exit_value;
}

void createNewGame()
{
    Gender player_gender;
    int gender_picker_output;
    Menu* character_creator = new Menu(CharacterCreator);
    switch (getMenuOutput(character_creator))
    {
        default: Utility::invalidInput();
        case 1: {Menu* gender_picker = new Menu(GenderPicker); gender_picker_output = getMenuOutput(gender_picker); delete gender_picker;} break;
        case 2: 
        switch (gender_picker_output)
        {
            case 1: {player_gender = Male;} break;
            case 2: {player_gender = Female;} break;
            case 3: {player_gender = Neutral;} break;
        }
        break;
    }
    main_character = new Character(Player, player_gender);
    delete character_creator;
}

int main()
{
    Utility::clearHistory();
    bool fuck = 1;
    while (fuck)
    {
        Menu* main_menu = new Menu(Main);
        switch (main_menu->exit_value)
        {
            case 1: delete main_menu; createNewGame(); fuck = 0; break;
            
            default: Utility::notImplemented(); break;
        }
    }    

    //This is where code to start the game will go when said code actually exists.

    
    return 0;
}
