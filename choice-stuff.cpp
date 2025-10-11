#include <ostream>
#include <pthread.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <thread>
#include "header.h"

    bool available;
    std::string text;

    Choice::Choice(std::string name_of_menu_param, uint choice_number)
    {

        if (name_of_menu_param == "main_menu")
        {
            if (choice_number == 1)
            {
                this->assignText("New Game");
            }
            else if (choice_number == 2)
            {
                this->assignText("Load Game");
            }
            else if (choice_number == 3)
            {
                this->assignText("Settings");
            }
        }

        else if (name_of_menu_param == "main_character_creator")
        {
            if (choice_number == 1)
            {
                this->assignText("Gender");
            }
            else if (choice_number == 2)
            {
                this->assignText("Stats");
            }
            else if (choice_number == 3)
            {
                this->assignText("Finish");
            }
        }

        else if (name_of_menu_param == "gender_picker")
        {
            if (choice_number == 1)
            {
                this->assignText("Male (he/him/his)");
            } 
            else if (choice_number == 2)
            {
                this->assignText("Female (she/her)");
            }
            else if (choice_number == 3)
            {
                this->assignText("Neutral (they/them/their)");
            }
        }
        
        else if (name_of_menu_param == "short_stat_selection")
        {
            if (choice_number == 1)
            {
                this->assignText("Strength");
            }
            else if (choice_number == 2)
            {
                this->assignText("Dexterity");
            }
            else if (choice_number == 3)
            {
                this->assignText("Constitution");
            }
            else if (choice_number == 4)
            {
                this->assignText("Intelligence");
            }
            else if (choice_number == 5)
            {
                this->assignText("Wisdom");
            }
            else if (choice_number == 6)
            {
                this->assignText("Charisma");
            }
            else if (choice_number == 7)
            {
                this->assignText("Reset changes");
            }
            else if (choice_number == 8)
            {
                this->assignText("Finish");
            }
        }
        else if (name_of_menu_param == "stat_selection")
        {
            if (choice_number == 1)
            {
                this->assignText("Strength (This determines how much damage heavy weapons like two-handed weapons or maces will deal, along with helping you use physical strength to get out of situations.)");
            }
            else if (choice_number == 2)
            {
                this->assignText("Dexterity (This determines how likely you are to hit your enemy with a weapon, as well as determining how nimble you are. Will help you get out of situations by running or sneaking.)");
            }
            else if (choice_number == 3)
            {
                this->assignText("Constitution (This determines how much max HP you have, as well as letting you endure physical pain better in situations where you have to grit your teeth.)");
            }
            else if (choice_number == 4)
            {
                this->assignText("Intelligence (This determines how effective your spells are, along with making you overall more intelligent and letting you figure out puzzles or make plans faster than others.)");
            }
            else if (choice_number == 5)
            {
                this->assignText("Wisdom (This determines how much max mana you have, and also determines how much insight you have into things that aren't common knowledge.)");
            }
            else if (choice_number == 6)
            {
                this->assignText("Charisma (This determines how easily you can convince others, intimidate them, or lie to them and get away with it.)");
            }
        }

        this->typeNumberOfChoice(choice_number);
        this->typeText();
    };

    void Choice::typeNumberOfChoice(uint choice_number)
    {
        std::cout << choice_number;
        std::this_thread::sleep_for(std::chrono::milliseconds(typing_speed));
        std::cout << ") ";
        std::this_thread::sleep_for(std::chrono::milliseconds(typing_speed));
    }

    void Choice::typeText()
    {
        for (std::size_t i = 0; i < this->text.size(); i++)
        {
            std::cout << this->text[i] << std::flush;

            std::this_thread::sleep_for(std::chrono::milliseconds(typing_speed));
        }
        
        makeSpace();
    }

    void Choice::assignText(std::string text_param)
    {
        this->text = text_param;
    }