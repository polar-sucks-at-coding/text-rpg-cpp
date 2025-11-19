#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>
#include "character.h"
#include "menu.h"
#include "setting.h"
#include "utility.h"
#include <iostream>
#include "dialog.h"

void settingsMenuShenanigans()
{
    Menu* settings_menu = new Menu();
    settings_menu->addTitle("Settings");
    settings_menu->addOption("Typing Speed", 0, Setting::changeTypingSpeedPreset);
    settings_menu->addOption("Reset to Defaults", 0, Setting::resetSettings);
    settings_menu->addOption("Exit", 1);

    settings_menu->play();
    
    delete settings_menu;
}

void mainMenuShenanigans()
{

    Menu* main_menu = new Menu();

    main_menu->addTitle("Main Menu");

    main_menu->addOption("New Game", 1);
    main_menu->addOption("Load Game", 1);
    main_menu->addOption("Settings", 1);
    main_menu->addOption("Exit gam", 1);

    bool meow = 1;

    while (meow)
    {
        main_menu->play();

        switch (main_menu->player_input)
        {
            case 1: Utility::notImplemented(); break;
            case 2: Utility::notImplemented(); break;
            case 3: settingsMenuShenanigans(); break;
            case 4: meow = 0; break;
        }
    }
    delete main_menu;
}

int main()
{
    Utility::clearHistory();
    Setting::resetSettings();

    mainMenuShenanigans();

    /*Menu *main_menu = new Menu();
    main_menu->addTitle("Main Menu");
    main_menu->addSubText("AWWAWDAWDSADSA");
    main_menu->addOption("skibidi toilet", 1, sex);
    main_menu->play();
    if (main_menu->player_input == 1) Utility::typeText("meowoewdowodw");*/

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

    /*Dialogue skibidi;

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

    skibidi.play("INTRO1");*/

    /*Menu *menu = new Menu();

    menu->addTitle("meow");
    menu->addSubText("purr");
    menu->addSubText("awwww");
    menu->displayTitles();
    menu->displaySubtexts();*/

    return 0;
}
