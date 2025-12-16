#pragma once
#include <string>
#include "item.h"

typedef unsigned int uint;

class Equipment : public Item
{
    public:
    Equipment();
    bool equipped = false;
    bool checkIfEquipped();
};

class Armor : public Equipment
{
    public:
    int defense;
};

namespace Armors
{
    class Fart_Coat : public Armor
    {
        public:
        Fart_Coat(){
            this->name = "Fart Coat";
            this->defense = 2;
            this->symbol = 'c';
            this->info = "Covers you with a heroic odor.";
            this->x_size = 2;
            this->y_size = 2;
        }
    };
}  


class Weapon : public Equipment
{
    public:
    int damage;
};

namespace Weapons
{
    class Fart_Sword: public Weapon
    {
        public:
        Fart_Sword(){
            this->damage = 2;
            this->name = "Fart Sword";
            this->symbol = 's';
            this->info = "Poisons your enemies.";
            this->x_size = 3;
        }
    };
}

