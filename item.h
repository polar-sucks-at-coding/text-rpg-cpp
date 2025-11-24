#pragma once
#include <string>
#include "character.h"

class Character;

class Item
{
    public:
    bool destroyed_on_use;
    std::string name;
    virtual void use(Character *_character);
    Item()
    {
        this->name = "Default Item";
        this->destroyed_on_use = true;
    };
    ~Item();
    
};

class Health_Potion : public Item
{
    public:
    int HP_to_restore = 10;
    void use (Character* _character);
    Health_Potion()
    {
        this->name = "Health Potion";
    };
};


