#pragma once
#include <string>

class Character;

class Item
{
    public:
    bool destroyed_on_use = true;
    std::string name;
    virtual void use(Character *_character);
    Item()
    {
        this->name = "Default Item";
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
        this->destroyed_on_use = false;
        this->name = "Health Potion";
    };
};


