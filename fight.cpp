#include "fight.h"
#include "utility.h"
#include "character.h"

Fight::~Fight()
{
    if (teams_temporary)
    {
        for (Fight_Team* team : teams)
        {
            delete team;
        }
    }
}

Fight_Team::~Fight_Team()
{
    if (fighters_temporary)
    {
        for (Character* f : fighters)
        {
            if (f == player) continue;
            delete f;
        }
    }
}

void Fight_Team::addFighter(Character* _character)
{
    fighters.push_back(_character);
}

Character* Fight_Team::returnFighterByName(const std::string& _name)
{
    Character* fallback_fighter;
    if (fighters.empty()) {Utility::typeText("This team is empty."); return fallback_fighter;}
    for (Character* fighter : fighters)
    {
        if (!fighter) continue;
        if (fighter->name == _name) return fighter;
    }

    Utility::typeText("Couldn't find the fighter you're looking for.");
    return fallback_fighter;
}

void Fight::createTeam(const std::string& _name)
{
    teams.push_back(new Fight_Team(_name));
}

Fight_Team* Fight::returnTeamByName(const std::string& _name)
{
    Fight_Team* fallback_team;
    if (teams.empty()) {Utility::typeText("No teams to return."); return fallback_team;}

    for (Fight_Team* team : teams)
    {
        if(!team) continue;
        if(team->name == _name) return team;
    }

    Utility::typeText("Couldn't find the team you're looking for."); 
    return fallback_team;
}