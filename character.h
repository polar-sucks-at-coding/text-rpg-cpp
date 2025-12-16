#pragma once
#include "ability.h"
#include "menu.h"
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
class Item;
class Equipment;

class Character
{
    public: 
    bool is_essential = false; // as in shouldnt be deleted
    bool player_controlled = false;
    GenderPreset gender_enum;
    std::string gender;
    uint HP;
    uint max_HP;
    uint default_fight_speed;
    uint fight_speed; //for after adding random rolls in fights (and literally in fight.cpp)
    std::string name;
    std::string pronoun1;
    std::string pronoun2;
    std::string pronoun3;
    std::vector<Ability*> abilities;
    Inventory *inventory;
    std::vector<Equipment*> equipment;
    


    ~Character();
    Character(const std::string& _name = "Default Char Name", const uint &_max_HP = 1, GenderPreset _gender_enum = Inanimate);
    void assignGenderString();
    void assignPronouns();
    void reportGender();
    void assignGenderEnum();
    void addAbility(Ability* _abl);
    void reportStats();
    void reportPronouns();
    void reportName();
    void restoreHP(const int &_amount, const bool &_report = 1);
    void returnToMaxHP(const bool &_report = 1);
    void reduceHP(const int &_amount);
    Ability* returnAbilityByName(const std::string& _n);
    void useAbilityByName(const std::string& _n);
    void pickTargetForPlayer();
    void addItemToInv(Item *_item);
    void equipItem(Equipment* _equipment);
    void listEquipment();
    void resetSpeedToDefault();
    void speedRoll(const int& _amount); //adds or reduces in the range entered 
    void showInventoryUI();
    void accessInventory();
};

static Character* player;

namespace Characters
{
    class Shitpisser : public Character
    {
        public:
        Shitpisser()
        {
            this->name = "Shitpisser";
            abilities.push_back(new Abilities::Shit());
            abilities.push_back(new Abilities::Piss());
        }
    };
}
