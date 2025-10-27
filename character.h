#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>

typedef unsigned int uint;

static uint amount_of_stats = 6;

enum Gender
{
    Male,
    Female,
    Neutral,
    Inanimate
};

enum Type
{
    Player,
    Enemy,
    NPC //etc
};

class Character
{
public: 
std::string type;
Gender gender;
uint HP;
uint maxHP;
std::string name;
std::string pronoun1;
std::string pronoun2;
std::string pronoun3;

public:
Character(Type type);
Character(Type type, Gender gender);
void assignPronouns();
/*
void assignBaseStats();
*/
void reportStats();


};

static Character* player;

#endif