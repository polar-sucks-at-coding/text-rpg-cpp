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

enum EnemyType
{
    ShitPisser
};


class Character
{
public: 
Gender gender;
uint HP;
uint maxHP;
std::string name;
std::string pronoun1;
std::string pronoun2;
std::string pronoun3;

public:
Character();
void assignGender(Gender gender_param);
void assignPronouns();
/*
void assignBaseStats();
*/
void reportStats();
void reportPronouns();
void reportName();
};


class Enemy : Character
{
    
};

class NPC : Character
{
    
};

static Character* player;

#endif