#include <filesystem>
#include <ostream>
#include <string>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <thread>

typedef unsigned int uint;

void makeSpace()
{
    std::cout << std::endl;
}

void doubleSpace()
{
    std::cout << "\n\n";
}

void notImplemented()
{
    std::cout << "This isnt implemented yet\n";
}

void clearHistory()
{

}

static std::string most_recent_input;

static uint typing_speed = 30; //it's actually the delay between each individual letter, but yk




struct Character
{
    std::string type;
    uint HP;
    uint mana;
    uint STR;
    uint DEX;
    uint CON;
    uint INT;
    uint WIS;
    uint CHA;
    std::string gender;
    std::string name;
    std::string pronoun1;
    std::string pronoun2;
    std::string pronoun3;

    public: Character(std::string type_param, std::string gender_param)
    {
        this->type = type_param;
        this->gender = gender_param;

        this->pronounAssigner();
        this->baseStatAssigner();
    
    }

    void baseStatAssigner()
    {
        if (this->type == "main")
        {
            this->STR = this->DEX = this->CON = this->INT = this->WIS = this->CHA = 5;
        }
    }

    void pronounAssigner()
    {
        if (this->gender == "male")
        {
            this->pronoun1 = "he";
            this->pronoun2 = "him";
            this->pronoun3 = "his";
        }
        else if (this->gender == "female")
        {
            this->pronoun1 = "she";
            this->pronoun2 = "her";
            this->pronoun3 = pronoun2;
        }
        else if (this->gender == "neutral")
        {
            this->pronoun1 = "they";
            this->pronoun2 = "them";
            this->pronoun3 = "their";
        }
        else 
        {
            this->pronoun1 = "it";
            this->pronoun2 = pronoun1;
            this->pronoun3 = "its";
        }
    }

};

static Character* main_character;

struct Event
{
    std::string name;
    
    public: Event(std::string name_param)
    {
        this->name = name_param;
        

    }
};

struct CombatAbility
{
    uint id;
    std::string name;

    public: CombatAbility(uint id_param)
    {
        this->id = id_param;
    }
};

struct Choice
{
    bool available;
    std::string text;

    public: Choice(std::string name_of_menu_param, uint choice_number)
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
            else if (choice_number == 7)
            {
                this->assignText("Finish.");
            }
        }

        this->typeNumberOfChoice(choice_number);
        this->typeText();
    }

    void typeNumberOfChoice(uint choice_number)
    {
        std::cout << choice_number;
        std::this_thread::sleep_for(std::chrono::milliseconds(typing_speed));
        std::cout << " )";
        std::this_thread::sleep_for(std::chrono::milliseconds(typing_speed));
    }

    void typeText()
    {
        for (std::size_t i = 0; i < this->text.size(); i++)
        {
            std::cout << this->text[i] << std::flush;

            std::this_thread::sleep_for(std::chrono::milliseconds(typing_speed));
        }
        
        makeSpace();
    }

    void assignText(std::string text_param)
    {
        this->text = text_param;
    }
};



struct Menu
{
    std::string text;
    std::string name;
    uint amount_of_choices;


    public:Menu(std::string name_param)
    {
        this->name = name_param;

        if (this->name == "main_menu")
        {
            this->mainMenu();
        }
        else if (this->name == "main_character_creator")
        {
            this->mainCharacterCreator();
        }
        else if (this->name == "gender_picker")
        {
            this->genderPicker();
        }
        else if (this->name == "stat_selection")
        {
            this->statSelection();
        }
        else
        {
            std::cout << "Menu name doesn't exist.";
        }
    }

    void choiceCreator()
    {
        assignTextAndType("Choose.");
        makeSpace();

        for (uint i = 1; i < this->amount_of_choices + 1; i++)
        {
            Choice* choice = new Choice(this->name, i);
        }   
    }

    std::string getPlayerChoice()
    {
        std::string player_decision;
        makeSpace();
        std::cin >> player_decision;
        makeSpace();

        clearHistory();

        return player_decision;
    }

    void statSelection()
    {
        this->amount_of_choices = 7;

        assignTextAndType("Choose your stats");
        doubleSpace();

        assignTextAndType("Current stats:");
        makeSpace();

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

        this->choiceCreator();

        std::string stat_choice; 
        uint number_choice;

        bool player_is_done = 0;

        while (player_is_done == 0)
        {
            stat_choice = getPlayerChoice();

            if (stat_choice == "7")
            {
                player_is_done = 1;
            }
            else 
            {
                if (stat_choice == "1" || "2" || "3" || "4" || "5" || "6")
                {
                    assignTextAndType("How high would you like this stat to be?");
                    makeSpace();
                    if (stat_choice == "1")
                    {
                        main_character->STR = number_choice;
                    }
                }
                else if (stat_choice != "7")
                {
                    assignTextAndType("Invalid stat.");
                }
            }
        }
    }

    public:void mainCharacterCreator() //2
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

    void genderPicker() //3
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

    void mainMenu() //1
    {
        std::cout << "Main Menu";
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

    void typeMenuText()
    {
        for (std::size_t i = 0; i < this->text.size(); i++)
        {
            std::cout << this->text[i] << std::flush;

            std::this_thread::sleep_for(std::chrono::milliseconds(typing_speed));
        }
    }

    void assignTextAndType(std::string text)
    {
        this->text = text;
        typeMenuText();
    }
    
};

void mainMenuCreator()
{
    Menu* main_menu = new Menu("main_menu");
}

int main()
    {
        mainMenuCreator();
    
        return 0;
    }
