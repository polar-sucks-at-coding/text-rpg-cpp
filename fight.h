#pragma once
#include <vector>
#include <string>
#include "character.h"

class Fight_Team
{
    public:
    std::string name;
    std::vector<Character*> fighters;

    Fight_Team(const std::string& _name): 
    name{_name}
    {}
    ;

    void addFighter(Character* _character);
    void removeFighter(Character* _character);
    Character* returnFighterByName(const std::string& _name);

};

class Fight
{
    public:
    bool delete_teams_on_destruct;
    std::vector<Fight_Team*> teams;
    void addTeam(const std::string& _team_name);
    Fight_Team* returnTeamByName(const std::string& _name);
    
    Fight(bool _del_team_des = 1) :
    delete_teams_on_destruct(_del_team_des)
    {}
    ;
    ~Fight();
};