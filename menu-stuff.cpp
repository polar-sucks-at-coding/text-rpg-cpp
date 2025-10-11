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

        if (valid_menu_list.find(this->name) != std::string::npos)
        {
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
        }
        else
        {
            std::cout << "Menu name doesn't exist.";
        }
    }

    void Menu::choiceCreator()
    {
        makeSpace();

        for (uint i = 1; i < this->amount_of_choices + 1; i++)
        {
            Choice* choice = new Choice(this->name, i);
        }   
    }

    std::string Menu::getPlayerChoice()
    {
        std::string player_decision;
        makeSpace();
        std::cin >> player_decision;
        makeSpace();

        clearHistory();

        return player_decision;
    }

    uint Menu::getPlayerIntChoice()
    {
        uint player_decision;
        makeSpace();
        std::cin >> player_decision;
        makeSpace();

        clearHistory();

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
            doubleSpace();

            assignTextAndType("STR: " );
            std::cout << main_character->STR;
            makeSpace();
            assignTextAndType("DEX: ");
            std::cout << main_character->DEX;
            makeSpace();
            assignTextAndType("CON: ");
            std::cout << main_character->CON;
            makeSpace();
            assignTextAndType("INT: ");
            std::cout << main_character->INT;
            makeSpace();
            assignTextAndType("WIS: ");
            std::cout << main_character->WIS;
            makeSpace();
            assignTextAndType("CHA: ");
            std::cout << main_character->CHA;
            doubleSpace();
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

        std::string stat_choice; 
        uint number_choice;
        uint points_left = 10;

        bool player_is_done = 0;

        while (player_is_done == 0)
        {
            this->amount_of_choices = 8;
            makeSpace();
            assignTextAndType("Choose your stats. You have ");
            std::cout << points_left;
            assignTextAndType(" points left to distribute as you wish.");
            doubleSpace();

            this->name = "short_stat_selection";
            this->statReporter(main_character);
            this->choiceCreator();

            stat_choice = getPlayerChoice();

            if (stat_choice == "8")
            {
                player_is_done = 1;
            }
            else if (stat_choice == "7")
            {
                main_character->baseStatAssigner();
                points_left = 10;
            }
            else 
            {
                if (stat_choice == "1" || "2" || "3" || "4" || "5" || "6")
                {
                    assignTextAndType("How many points would you like to add to this stat?");

                    number_choice = getPlayerIntChoice();
                    if (number_choice > points_left)
                    {
                        assignTextAndType("You don't have enough points.");
                    }
                    else 
                    {
                        if (stat_choice == "1")
                        {
                            main_character->STR += number_choice;
                        }
                        else if (stat_choice == "2")
                        {
                            main_character->DEX += number_choice;
                        }
                        else if (stat_choice == "3")
                        {
                            main_character->CON += number_choice;
                        }
                        else if (stat_choice == "4")
                        {
                            main_character->INT += number_choice;
                        }
                        else if (stat_choice == "5")
                        {
                            main_character->WIS += number_choice;
                        }
                        else if (stat_choice == "6")
                        {
                            main_character->CHA += number_choice;
                        }
                    
                        points_left -= number_choice;
                    }
                    makeSpace();
                }
                else if (stat_choice != "8" || "7")
                {
                    assignTextAndType("Invalid stat.");
                }
            }
        }
    }

    void Menu::mainCharacterCreator() //2
    {
        main_character = new Character("main", "neutral");

        this->amount_of_choices = 3;

        assignTextAndType("Character Creator");
        doubleSpace();

        std::string player_choice;

        bool player_is_done = 0;
        std::string gender_choice;

        while (player_is_done == 0)
        {
            assignTextAndType("Gender: ");
            std::cout << main_character->gender;
            makeSpace();
            this->text = "Pick what you want to decide about your character.";
            typeMenuText();
            doubleSpace();

            this->choiceCreator();

            player_choice = getPlayerChoice();

            if (player_choice == "1")
            {
                Menu* menu = new Menu("gender_picker");

                gender_choice = most_recent_input;

                main_character->gender = gender_choice;
                main_character->pronounAssigner();

                std::cout << "Gender: " << gender_choice;
                doubleSpace();
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
        makeSpace();
    }

    void Menu::genderPicker() //3
    {
        this->amount_of_choices = 3;

        assignTextAndType("Which gender do you want to be?");
        doubleSpace();

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
                makeSpace();
            }
        }
    }

    void Menu::mainMenu() //1
    {
        assignTextAndType("Main Menu");
        doubleSpace();


        this->amount_of_choices = 3;
        this->choiceCreator();
            
        if (getPlayerChoice() == "1")
        {
            Menu* main_character_creator = new Menu("main_character_creator");
        }
            
        else 
        {
            notImplemented();
        }
    }

    void Menu::typeMenuText()
    {
        for (std::size_t i = 0; i < this->text.size(); i++)
        {
            std::cout << this->text[i] << std::flush;

            std::this_thread::sleep_for(std::chrono::milliseconds(typing_speed));
        }
    }

    void Menu::assignTextAndType(std::string text)
    {
        this->text = text;
        typeMenuText();
    }