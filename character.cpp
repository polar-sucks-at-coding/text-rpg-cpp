#include <pthread.h>
#include <string>
#include <unistd.h>
#include "character.h"
#include "utility.h"
#include "item.h"
#include "inventory.h"

typedef unsigned int uint;

void Character::addAbility(Ability* _abl)
{
    abilities.push_back(_abl);
}

Character::~Character()
{
    delete this->inventory;
}

Character::Character(const std::string& _name, uint _max_HP, GenderPreset _gender_enum)
{
    this->name = _name;
    this->max_HP = _max_HP;
    this->HP = _max_HP;
    this->gender_enum = _gender_enum;
    this->inventory = new Inventory();
    this->assignPronouns();
    this->assignGenderString();
}

void Character::returnToMaxHP()
{
    this->HP = this->max_HP;
}

void Character::reduceHP(int _amount)
{
    if ((this->HP - _amount) < 0) this->HP = 0; return;
    this->HP -= _amount;
}

void Character::restoreHP(int _amount)
{
    if ((_amount + this->HP) > this->max_HP){
        returnToMaxHP(); Utility::typeText("HP restored to max."); return;
    } 
    this->HP += _amount;
    Utility::typeText("HP restored by ", 0);
    Utility::typeText(std::to_string(_amount));
    Utility::typeText("HP restored to: ", 0);
    Utility::typeText(std::to_string(this->HP));
}

void Character::assignGenderString()
{   
    switch(this->gender_enum)
    {
        case Male: this->gender = "male"; break;
        case Female: this->gender = "female"; break;
        case Neutral: this->gender = "neutral"; break;
        case Inanimate: this->gender = "inanimate"; break;
    }
}

void Character::assignPronouns()
{
    switch (gender_enum)
    {
        case Male:
        {
            this->pronoun1 = "he";
            this->pronoun2 = "him";
            this->pronoun3 = "his";
        }
        break;
        case Female:
        {
            this->pronoun1 = "she";
            this->pronoun2 = "her";
            this->pronoun3 = this->pronoun2;
        }
        break;
        case Neutral:
        {
            this->pronoun1 = "they";
            this->pronoun2 = "them";
            this->pronoun3 = "their";
        }
        break;
        case Inanimate:
        {
            this->pronoun1 = "it";
            this->pronoun2 = pronoun1;
            this->pronoun3 = "its";
        }
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
    Utility::typeText("Max HP: ", 0);
    Utility::typeText(std::to_string(this->max_HP));

    Utility::typeText("Gender: ", 0);
    this->reportGender();
    std::cout << "\n";

    Utility::typeText("Name: ", 0);
    this->reportName();
    std::cout << "\n";

    Utility::typeText("Pronouns: ", 0);
    this->reportPronouns();
}

void Character::reportGender()
{
    Utility::typeText(this->gender, 0);
}

/*
void Character::assignBaseStats()
{

}
*/