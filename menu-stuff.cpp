#include <cstddef>
#include <ostream>
#include <pthread.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <thread>
#include "header.h"

    Menu::Menu(std::string name_param)
    {
        this->name = name_param;

        if (name == "main_menu")
        {
            this->mainMenu();
        }
        else if (name == "main_character_creator")
        {
            this->mainCharacterCreator();
        }
        else if (name == "gender_picker")
        {
            this->genderPicker();
        }
        else if (name == "stat_selection")
        {
            this->statSelection();
        }
        else if (name == "settings")
        {
            this->settingsMenu();
        }
        else 
        {
            assignTextAndType("Menu name doesn't exist.");
        }
    }

    void Menu::settingsMenu()
    {
        assignTextAndType("Settings");
        Utility::doubleSpace();
        this->amount_of_choices = Setting::amount_of_settings + 2;
        bool player_is_done = 0;
        while (player_is_done == 0)
        {
            this->choiceCreator();
            int player_choice = getPlayerIntChoice(0);
            if (player_choice == 1)
            {
                Setting::typing_speed->value =  101 - slider(1, 100);
            }
            else if (player_choice == amount_of_choices - 1)
            {
                Setting::resetSettings();
            }
            else if (player_choice == amount_of_choices)
            {
                player_is_done = 1;
            }
        }

    }

    void Menu::choiceCreator()
    {
        Utility::makeSpace();

        for (uint i = 1; i < this->amount_of_choices + 1; i++)
        {
            Choice* choice = new Choice(this->name, i);
        }   
    }

    std::string Menu::getPlayerChoice(bool clear_history = 1)
    {
        std::string player_decision;
        Utility::makeSpace();
        std::cin >> player_decision;
        Utility::makeSpace();

        if (clear_history == 1)
        {
            Utility::clearHistory();
        }
        

        return player_decision;
    }

    uint Menu::getPlayerIntChoice(bool clear_history = 1)
    {
        uint player_decision;
        Utility::makeSpace();
        std::cin >> player_decision;
        Utility::makeSpace();

        if (clear_history == 1)
        {
            Utility::clearHistory();
        }

        return player_decision;
    }

    void Menu::statReporter(Character* character)
    {
        uint STR;
        uint DEX;
        uint CON;
        uint INT;
        uint WIS;
        uint CHA;
        if (character->type == "main")
        {
            assignTextAndType("Current stats:");
            Utility::doubleSpace();

            assignTextAndType("STR: " );
            std::cout << main_character->STR;
            Utility::makeSpace();
            assignTextAndType("DEX: ");
            std::cout << main_character->DEX;
            Utility::makeSpace();
            assignTextAndType("CON: ");
            std::cout << main_character->CON;
            Utility::makeSpace();
            assignTextAndType("INT: ");
            std::cout << main_character->INT;
            Utility::makeSpace();
            assignTextAndType("WIS: ");
            std::cout << main_character->WIS;
            Utility::makeSpace();
            assignTextAndType("CHA: ");
            std::cout << main_character->CHA;
            Utility::doubleSpace();
        }
        else 
        {
            assignTextAndType("Character type not found in stat reporter.");
        }
    }

    void Menu::statSelection()
    {
        this->amount_of_choices = 6;


        this->choiceCreator();

        uint stat_choice; 
        uint number_choice;
        uint points_left = 10;

        bool player_is_done = 0;

        while (player_is_done == 0)
        {
            this->amount_of_choices = 8;
            Utility::makeSpace();
            this->assignTextAndType("Choose your starting stats. You have ");
            std::cout << points_left;
            this->assignTextAndType(" points left to distribute as you wish.");
            Utility::doubleSpace();

            this->name = "short_stat_selection";
            this->statReporter(main_character);
            this->choiceCreator();

            stat_choice = getPlayerIntChoice();

            if (stat_choice == 8)
            {
                player_is_done = 1;
            }
            else if (stat_choice == 7)
            {
                main_character->baseStatAssigner();
                points_left = 10;
            }
            else 
            {
                if (stat_choice == 1 || 2 || 3 || 4 || 5 || 6)
                {
                    this->assignTextAndType("How many points would you like to add to this stat?");

                    number_choice = getPlayerIntChoice();
                    if (number_choice > points_left)
                    {
                        this->assignTextAndType("You don't have enough points.");
                    }
                    else 
                    {
                        if (stat_choice == 1)
                        {
                            main_character->STR += number_choice;
                        }
                        else if (stat_choice == 2)
                        {
                            main_character->DEX += number_choice;
                        }
                        else if (stat_choice == 3)
                        {
                            main_character->CON += number_choice;
                        }
                        else if (stat_choice == 4)
                        {
                            main_character->INT += number_choice;
                        }
                        else if (stat_choice == 5)
                        {
                            main_character->WIS += number_choice;
                        }
                        else if (stat_choice == 6)
                        {
                            main_character->CHA += number_choice;
                        }
                    
                        points_left -= number_choice;
                    }
                    Utility::makeSpace();
                }
                else if (stat_choice != 8 || 7)
                {
                    this->assignTextAndType("Invalid stat.");
                }
            }
        }
    }

    void Menu::mainCharacterCreator()
    {    
        main_character = new Character("main", "neutral");

        this->amount_of_choices = 3;

        assignTextAndType("Character Creator");
        Utility::doubleSpace();

        std::string player_choice;

        bool player_is_done = 0;
        std::string gender_choice;

        while (player_is_done == 0)
        {
            assignTextAndType("Gender: ");
            assignTextAndType(main_character->gender);
            Utility::doubleSpace();
            this->text = "Pick what you want to decide about your character.";
            typeMenuText();
            Utility::doubleSpace();

            this->choiceCreator();

            player_choice = getPlayerChoice();

            if (player_choice == "1")
            {
                Menu* menu = new Menu("gender_picker");

                gender_choice = most_recent_input;

                main_character->gender = gender_choice;
                main_character->pronounAssigner();

            }
            else if (player_choice == "2")
            {
                Menu* menu = new Menu("stat_selection");

            }
            else if (player_choice == "3")
            {
                player_is_done = 1;
            }
            else
            {
                std::cout << "Invalid character creator choice.";
            }
        }


        assignTextAndType("Character created!");
        Utility::makeSpace();
    }

    void Menu::genderPicker()
    {
        this->amount_of_choices = 3;

        assignTextAndType("Which gender do you want to be?");
        Utility::doubleSpace();

        this->choiceCreator();

        std::string player_choice; 

        bool is_done = 0;

        while (is_done == 0)
        {
            player_choice = getPlayerChoice();

            if (player_choice == "1")
            {
                most_recent_input = "male";
                is_done = 1;
            }
            else if (player_choice == "2")
            {
                most_recent_input = "female";
                is_done = 1;
            }
            else if (player_choice == "3")
            {
                most_recent_input = "neutral";
                is_done = 1;
            }
            else 
            {
                std::cout << "Invalid gender input";
                Utility::makeSpace();
            }
        }
    }

    void Menu::mainMenu()
    {
        this->assignTextAndType("Main Menu");
        Utility::doubleSpace();


        this->amount_of_choices = 3;
        this->choiceCreator();

        std::string player_choice = getPlayerChoice();
            
        if (player_choice == "1")
        {
            Menu* main_character_creator = new Menu("main_character_creator");
        }

        else if (player_choice == "3")
        {
            Menu* settings = new Menu("settings");
        }
            
        else 
        {
            Utility::notImplemented();
        }
    }

    void Menu::typeMenuText()
    {
        for (std::size_t i = 0; i < this->text.size(); i++)
        {
            std::cout << this->text[i] << std::flush;

            std::this_thread::sleep_for(std::chrono::milliseconds(Utility::getTypingSpeed()));
        }
    }

    void Menu::assignTextAndType(std::string text)
    {
        this->text = text;
        typeMenuText();
    }

    uint Menu::slider(uint min_value, uint max_value)
    {
        assignTextAndType("Assign a number ");
        assignTextAndType(std::to_string(min_value));
        assignTextAndType(" through ");
        assignTextAndType(std::to_string(max_value));
        assignTextAndType(" this value.");
        Utility::makeSpace();
        
        uint value;

        std::cin >> value;
        return value;
        
    }