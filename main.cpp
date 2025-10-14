#include <pthread.h>
#include <string>
#include <unistd.h>
#include "menu-header.h"
#include "utility-header.h"

/*struct Character //backup character struct
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
*/

void mainMenuCreator()
{
    Menu* main_menu = new Menu("main_menu");
}

int main()
    {
        Utility::clearHistory();
        mainMenuCreator();
        
        return 0;
    }
