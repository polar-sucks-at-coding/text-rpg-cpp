#include <cstddef>
#include <ostream>
#include <pthread.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <thread>
#include "character.h"
#include "classless.h"
#include "setting.h"
#include "utility.h"
#include "choice.h"
#include "menu.h"
#include "event.h"

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
        else 
        {
            assignTextAndType("Menu name doesn't exist.");
        }
    }

    void Menu::choiceCreator()
    {
        Utility::makeSpace();

        for (uint i = 1; i < this->amount_of_choices + 1; i++)
        {
            Choice* choice = new Choice(this->name, 1, i);
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
            main_character->reportStats();
            this->choiceCreator();

            stat_choice = Utility::getPlayerIntChoice();

            if (stat_choice == 8)
            {
                player_is_done = 1;
            }
            else if (stat_choice == 7)
            {
                main_character->assignBaseStats();
                points_left = 10;
            }
            else 
            {
                if (stat_choice == 1 || 2 || 3 || 4 || 5 || 6)
                {
                    this->assignTextAndType("How many points would you like to add to this stat?");

                    number_choice = Utility::getPlayerIntChoice();
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
            assignTextAndType("Pick what you want to decide about your character.");
            Utility::doubleSpace();

            this->choiceCreator();

            player_choice = Utility::getPlayerChoice();

            if (player_choice == "1")
            {
                Menu* menu = new Menu("gender_picker");

                gender_choice = most_recent_input;

                main_character->gender = gender_choice;
                main_character->assignPronouns();

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
            player_choice = Utility::getPlayerChoice();

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
        this->amount_of_choices = 3;

        bool go_back_to_main = 1;
            
        while (1)
        {
            this->assignTextAndType("Main Menu");
            Utility::doubleSpace();
            std::string player_choice = Menu::createChoicesAndGetPlayerChoice();

            if (player_choice == "1")
            {
                Menu* main_character_creator = new Menu("main_character_creator");
                break;
            }

            else if (player_choice == "3")
            {
                changeSettings();
            }
            else 
            {
                Utility::notImplemented();
            }
            //Event* event = new Event("intro");
        }
    }

    void Menu::assignTextAndType(std::string text_param)
    {
        this->text = text_param;
        for (std::size_t i = 0; i < this->text.size(); i++)
        {
            std::cout << this->text[i] << std::flush;

            std::this_thread::sleep_for(std::chrono::milliseconds(Setting::typing_speed->value));
        }
    }

    std::string Menu::createChoicesAndGetPlayerChoice()
    {
        this->choiceCreator();

        return Utility::getPlayerChoice();
    }