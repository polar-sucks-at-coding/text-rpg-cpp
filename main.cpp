#include <pthread.h>
#include <unistd.h>
#include "character.h"
#include "menu.h"
#include "setting.h"
#include "utility.h"
#include <iostream>
#include "dialog.h"

void createNewGame()
{
    Gender gender_input = Neutral;
    int gender_picker_output;
    std::string name_input = "";
    
    bool toilet = 1;
    Menu* character_creator = new Menu(CharacterCreator);
    while (toilet)
    {
        character_creator->typeTitleAndSubAndCreateOptions();

        switch (character_creator->returnPlayerInput())
        {
            case 1:
                {
                    bool skibidi = 1;

                    Menu* gender_picker = new Menu(GenderPicker);

                    while (skibidi)
                    {
                        Utility::typeText("Current gender: ", 0);
                        switch(gender_input)
                        {
                            case Male: Utility::typeText("Male"); break;
                            case Female: Utility::typeText("Female"); break;
                            case Neutral: Utility::typeText("Neutral"); break;
                            case Inanimate: Utility::typeText("Inanimate"); break;
                        }
                        
                        gender_picker->typeTitleAndSubAndCreateOptions();

                        switch (gender_picker->returnPlayerInput())
                        {
                            case 1: gender_input = Male; break;
                            case 2: gender_input = Female; break;
                            case 3: gender_input = Neutral; break;
                            case 4: gender_input = Inanimate; break;
                            case 5: skibidi = 0; break;
                        }
                    }
                    delete gender_picker;
                }
            break;
    
            case 2: 
                Utility::typeText("What would you like your name to be?");
                std::cin >> name_input;
            break;

            case 3: 
                if (name_input == "")
                {
                    Utility::typeText("You must pick a name.");
                }

                else toilet = 0; 
                
            break;

            default: Utility::typeText("amount_of_options not assigned correctly to character creator."); break;
        }
    }
    delete character_creator;
    
    //Player pointer is created in character.h.
    player = new Character();
    player->gender = gender_input;
    player->assignPronouns();
    player->name = name_input;

    Utility::clearHistory();
    
}

void createSettings()
{
    int fuck = 1;
    Menu* settings = new Menu(Settings);
    while (fuck)
    {
        settings->typeTitleAndSubAndCreateOptions();

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
    Setting::resetSettings();

    /*
    bool fuck = 1;
    Menu* main_menu = new Menu(Main);
    while (fuck)
    {
        main_menu->typeTitleAndSubAndCreateOptions();

        switch (main_menu->returnPlayerInput())
        {
            case 1: createNewGame(); fuck = 0; break;

            case 3: createSettings(); break;
            
            default: Utility::notImplemented(); break;
        }
    }    
    delete main_menu;


    player->reportStats();
    */


    Dialogue skibidi;

    skibidi.addLine("Im a femboy uwu", "INTRO1");
    skibidi.getLineByID("INTRO1")->addOption("purr", "CONTINUE", false);
    skibidi.getLineByID("INTRO1")->addOption("meow", "CONTINUE2");
    skibidi.getLineByID("INTRO1")->addOption("uwu", "", true);

    skibidi.addLine("ommgggg purrrrr", "CONTINUE");
    skibidi.getLineByID("CONTINUE")->addOption("nvm go back", "INTRO1");
    skibidi.getLineByID("CONTINUE")->addOption("ew weirdo fuck off", "", true);
    skibidi.getLineByID("CONTINUE")->addOption("can we redo im kinda retarded", "CONTINUE");
    skibidi.getLineByID("CONTINUE")->addOption("*diddles your dad*", "CONTINUE2");

    skibidi.addLine("omg this is the climax im gonna cummy wummy", "CONTINUE2");
    skibidi.getLineByID("CONTINUE2")->addOption("ok can we go back I wanna edge you", "CONTINUE");
    skibidi.getLastLine()->addOption("poop porn", "INTRO1",1);

    skibidi.play("INTRO1");

    return 0;
}
