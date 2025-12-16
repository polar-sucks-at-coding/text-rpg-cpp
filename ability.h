#pragma once
#include <string>
#include <vector>


class Character;


class Ability
{
    public:
    std::string name;
    std::vector<Character*> targets;
    int max_targets; // amount of characters the ability can target
    virtual void use(Character* _usr);
    void addTargetVector(const std::vector<Character*> &_targs);
    void addSingletarget(Character* _t);
    void removeAllTargets();
    ~Ability();

    Ability()
    {
        this->name = "Default Ability";
        this->max_targets = 1;
    }

};

class Fart : public Ability
{
    public:
    void use(Character* _c);
    Fart()
    {
        this->name = "Fart";
        this->max_targets = 3;
    }
};

namespace Abilities
{
    class Shit : public Ability
    {
        public:
        void use(Character* _c);
        Shit()
        {
            this->name = "Shit";
            this->max_targets = 5;
        }
    };

    class Piss : public Ability
    {
        public:
        void use(Character* _c);
        Piss()
        {
            this->name = "Piss";
            this->max_targets = 5;
        }
    };
}

