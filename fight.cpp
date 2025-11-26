#include "fight.h"
#include "utility.h"
#include "character.h"

Fight::~Fight()
{
    if (delete_teams_on_destruct)
    {
        for (Fight_Team* team : teams)
        {
            delete team;
        }
    }
}

void Fight_Team::addFighter(Character* _character)
{
    fighters.push_back(_character);
}

Character* Fight_Team::returnFighterByName(const std::string& _name)
{
    if (fighters.empty()) {Utility::typeText("This team is empty."); return nullptr;}
    for (Character* fighter : fighters)
    {
        if (!fighter) continue;
        if (fighter->name == _name) return fighter;
    }

    Utility::typeText("Couldn't find the fighter you're looking for.");
    return nullptr;
}

void Fight::addTeam(const std::string& _name)
{
    teams.push_back(new Fight_Team(_name));
}

Fight_Team* Fight::returnTeamByName(const std::string& _name)
{
    if (teams.empty()) {Utility::typeText("No teams to return."); return nullptr;}

    for (Fight_Team* team : teams)
    {
        if(!team) continue;
        if(team->name == _name) return team;
    }

    Utility::typeText("Couldn't find the team you're looking for."); 
    return nullptr;
}