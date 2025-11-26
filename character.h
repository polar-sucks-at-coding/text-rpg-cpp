#pragma once
#include <string>
#include <vector>

typedef unsigned int uint;

enum GenderPreset
{
    Male,
    Female,
    Neutral,
    Inanimate
};

class Inventory;
class Ability;

class Character
{
    public: 
    GenderPreset gender_enum = Inanimate;
    std::string gender;
    uint HP;
    uint max_HP;
    std::string name;
    std::string pronoun1;
    std::string pronoun2;
    std::string pronoun3;
    std::vector<Ability*> abilities;
    Inventory *inventory;

    ~Character();
    Character(const std::string& _name = "Default Char Name", uint _max_HP = 1, GenderPreset _gender_enum = Inanimate);
    void assignGenderString();
    void assignPronouns();
    void reportGender();
    void assignGenderEnum();
    void addAbility(Ability* _abl);
    void reportStats();
    void reportPronouns();
    void reportName();
    void restoreHP(int _amount);
    void returnToMaxHP();
    void reduceHP(int _amount);
};

static Character* player;