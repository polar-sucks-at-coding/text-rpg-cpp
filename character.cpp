#include <pthread.h>
#include <string>
#include <unistd.h>
#include "character.h"
#include "utility.h"

Character::Character(Type type) : Character(type, Inanimate)
{
    this->type = type;
    this->assignPronouns();
    //this->assignBaseStats();
}

Character::Character(Type type, Gender gender)
{
    this->type = type;
    this->gender = gender;
    this->assignPronouns();
}

void Character::assignPronouns()
{
    switch(gender)
    {
        case Male:
        this->pronoun1 = "he";
        this->pronoun2 = "him";
        this->pronoun3 = "his";
        break;

        case Female:
        this->pronoun1 = "she";
        this->pronoun2 = "her";
        this->pronoun3 = pronoun2;
        break;
        
        case Neutral:
        this->pronoun1 = "they";
        this->pronoun2 = "them";
        this->pronoun3 = "their";
        break;

        case Inanimate:
        this->pronoun1 = "it";
        this->pronoun2 = pronoun1;
        this->pronoun3 = "its";
        break;

    }
}

void Character::reportStats()
{
    Utility::typeText("Gender: ", 0);
    switch (this->gender)
    {
        case Male: Utility::typeText("Male"); break;
        case Female: Utility::typeText("Female"); break;
        case Neutral: Utility::typeText("Neutral"); break; 
        case Inanimate: Utility::typeText("Inanimate"); break;
    }
}

/*
void Character::assignBaseStats()
{

}
*/