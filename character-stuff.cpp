#include <pthread.h>
#include <string>
#include <unistd.h>
#include "character-header.h"

Character::Character(std::string type_param, std::string gender_param)
{
    this->type = type_param;
    this->gender = gender_param;

    this->pronounAssigner();
    this->baseStatAssigner();
}

void Character::baseStatAssigner()
{
    if (this->type == "main")
    {
        this->STR = this->DEX = this->CON = this->INT = this->WIS = this->CHA = 5;
    }
}

void Character::pronounAssigner()
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
