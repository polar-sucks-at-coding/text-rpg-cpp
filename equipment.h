#pragma once
#include <string>

//just sitting here for now

class Equipment
{
    public:
    std::string name;

};

class Armor : public Equipment
{
    
};

class Fart_Coat : public Armor
{
    public:
    Fart_Coat()
    {
        this->name = "Fart Coat";
    }
};

class Weapon : public Equipment
{

};