#pragma once
#include <string>

class Character;

class Item
{
    public:
    bool destroyed_on_use;
    std::string name;
    virtual void use(Character *_character);
    Item(bool _destroyed_on_use = true)
    {
        this->name = "Default Item";
        this->destroyed_on_use = _destroyed_on_use;
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


