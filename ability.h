#pragma once
#include <string>
#include <vector>
#include "character.h"

class Ability
{
    public:
    std::string name;
    std::vector<Character*> targets;
    int target_amount; // amount of characters the ability can target
    virtual void use(Character* _user);
    void addTarget(Character* _targ);
    void removeAllTargets();

    Ability()
    {
        this->name = "Default Ability";
        this->target_amount = 1;
    }

};

class Fart : public Ability
{
    public:
    void use(Character* _user);
    Fart()
    {
        this->name = "Fart";
        this->target_amount = 3;
    }
};