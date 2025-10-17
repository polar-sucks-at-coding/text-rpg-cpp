#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>

typedef unsigned int uint;

class Character
{
    public: std::string type;
    uint HP;
    uint mana;
    uint STR;
    uint DEX;
    uint CON;
    uint INT;
    uint WIS;
    uint CHA;
    std::string gender;
    std::string name;
    std::string pronoun1;
    std::string pronoun2;
    std::string pronoun3;

    public:
    Character(std::string type_param, std::string gender_param);
    void assignBaseStats();
    void assignPronouns();
    void reportStats();
};

static Character* main_character;

#endif