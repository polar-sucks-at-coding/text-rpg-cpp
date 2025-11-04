#include <pthread.h>
#include <string>
#include <unistd.h>
#include "character.h"
#include "utility.h"

Character::Character()
{
    this->HP = this->maxHP;
}

void Character::assignGender(Gender gender_param)
{   
    this->gender = gender_param;
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

void Character::reportName()
{
    Utility::typeText(this->name, 0);
}

void Character::reportPronouns()
{
    Utility::typeText(this->pronoun1, 0);
    Utility::typeText("/", 0);
    Utility::typeText(this->pronoun2, 0);
    Utility::typeText("/", 0);
    Utility::typeText(this->pronoun3, 1);
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

    Utility::typeText("Name: ", 0);
    this->reportName();
    std::cout << "\n";

    Utility::typeText("Pronouns: ", 0);
    this->reportPronouns();
}

/*
void Character::assignBaseStats()
{

}
*/