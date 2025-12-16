#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>
#include "character.h"
#include "equipment.h"
#include "inventory.h"
#include "item.h"
#include "menu.h"
#include "setting.h"
#include "utility.h"
#include "dialog.h"
#include "fight.h"
#include "ability.h"
#include <iostream>

typedef Character C;

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
    //Utility::clearHistory();
    Setting::resetSettings();
    
    
    player = new Character();
    player->player_controlled = true;

    player->is_essential = true;

    Armors::Fart_Coat *fart_coat = new Armors::Fart_Coat();
    Weapons::Fart_Sword *fart_sword = new Weapons::Fart_Sword();

    player->addItemToInv(fart_coat);
    player->addItemToInv(fart_sword); 

    player->accessInventory();
    
    /*

    Fight* test = new Fight();

    test->createTeam("balls team");

    Character* balls = new Character("balls1");
    Character* balls2 = new Character("balls2");
    Character* balls3 = new Character("balls3");
    Character* balls4 = new Character("balls4");

    balls->fight_speed = 500;
    balls2->fight_speed = 5000;
    balls3->fight_speed = 1000;
    balls4->fight_speed = 2000;

    test->returnTeamByName("balls team")->addFighter(balls);
    test->returnTeamByName("balls team")->addFighter(balls2);
    test->returnTeamByName("balls team")->addFighter(balls3);
    test->returnTeamByName("balls team")->addFighter(balls4);

    test->makeTurnOrder();

    for (Character* peepee : test->fighters_in_order)
    {
        std::cout << peepee->name << "\n";
    }

    */

    /*
    mainMenuShenanigans();
    */

    
    //Equipment Test



    //Fight Test

    /*
    Fight* test_fight = new Fight();
    test_fight->createTeam("sexers");
    std::cout << test_fight->returnTeamByName("sexers")->name << "\n";

    Characters::Shitpisser* sexer = new Characters::Shitpisser();

    std::vector<C*> test_targets = {new Character("guy1", 100), new Character("guy2", 100), new C("guy3", 100), new C("guy4", 100), new C("guy5", 100) };
    std::cout << "1" << "\n";

    //Abilities::Shit* shit = new Abilities::Shit();
    //sexer->addAbility(shit);
    sexer->returnAbilityByName("Shit")->addTargetVector(test_targets);
    sexer->useAbilityByName("Shit");

    //Abilities::Piss* piss = new Abilities::Piss();
    //sexer->addAbility(piss);
    sexer->returnAbilityByName("Piss")->addTargetVector(test_targets);
    sexer->useAbilityByName("Piss");

    delete sexer;
    */


    //test_fight->returnTeamByName("sexers")->addFighter(guy1);

    //std::cout << test_fight->returnTeamByName("sexers")->returnFighterByName("guy")->name << "\n";
    

    //Inventory Test

    /*
    Character* character = new Character("character", 500);
    character->HP = 400;
    for (int i = 0; i < 20; i++)
    {
        Health_Potion* peepee = new Health_Potion();
        character->inventory->addItem(peepee);
    }
    for (Item* poo : character->inventory->items)
    {
        if (!poo) continue;

        if (auto hp = dynamic_cast<Health_Potion*>(poo)){
            hp->use(character);
        }

        continue;
    }
    delete character;
    */


    //Menu Test

    /*Menu *main_menu = new Menu();
    main_menu->addTitle("Main Menu");
    main_menu->addSubText("AWWAWDAWDSADSA");
    main_menu->addOption("skibidi toilet", 1, sex);
    main_menu->play();
    if (main_menu->player_input == 1) Utility::typeText("meowoewdowodw");*/

    //Dialogue Test

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

    skibidi.addLine("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA", "CONTINUE2");
    skibidi.getLineByID("CONTINUE2")->addOption("ok can we go back I wanna edge you", "CONTINUE");
    skibidi.getLastLine()->addOption("poop porn", "INTRO1",1);

    skibidi.play("INTRO1");*/

    delete player;

    return 0;
}
