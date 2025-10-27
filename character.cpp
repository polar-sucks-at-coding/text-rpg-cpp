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
    if (this->gender == Male)
    {
        this->pronoun1 = "he";
        this->pronoun2 = "him";
        this->pronoun3 = "his";
    }
    else if (this->gender == Female)
    {
        this->pronoun1 = "she";
        this->pronoun2 = "her";
        this->pronoun3 = pronoun2;
    }
    else if (this->gender == Neutral)
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