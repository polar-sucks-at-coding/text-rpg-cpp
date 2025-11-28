#pragma once
#include <vector>
#include <string>
#include "character.h"

class Fight_Team
{
    public:
    std::string name;
    std::vector<Character*> fighters;
    bool fighters_temporary; //if true, the fighters will be deleted when the fight is

    Fight_Team(const std::string& _name, const bool &_fighters_temp = 1): 
    name{_name},
    fighters_temporary{_fighters_temp}
    {}
    ;
    ~Fight_Team();
    void addFighter(Character* _character);
    void removeFighter(Character* _character);
    Character* returnFighterByName(const std::string& _name);

};

class Fight
{
    public:
    bool teams_temporary;
    std::vector<Fight_Team*> teams;
    void createTeam(const std::string& _team_name);
    Fight_Team* returnTeamByName(const std::string& _name);
    
    Fight(const bool &_teams_temp = 1) :
    teams_temporary{_teams_temp}
    {}
    ;
    ~Fight();
};