#include "fight.h"
#include "utility.h"
#include "character.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <memory>

int Fight::returnFighterCount()
{
    int total = 0;
    for (Fight_Team* team : teams)
    {
        if (!team) continue;
        total += team->fighters.size();
    }
    return total;
}

void Fight::play()
{ 
    makeTurnOrder();

    for (int i = 0; i <= fighters_in_order.size(); i++)
    {
        fighterTakeTurn(fighters_in_order[i]);
    }
}

void Fight::fighterTakeTurn(Character* _fighter)
{
    if (_fighter->player_controlled)
    {
        
    }
}

void Fight::makeTurnOrder()
{
    int meow = 3;

    for (Fight_Team* team : teams)
    {
        for (Character* fighter : team->fighters)
        {
            fighter->speedRoll(meow); //meow is a placeholder value, actual game will use some stat
            this->fighters_in_order.push_back(fighter);
        }
    }

    if (this->fighters_in_order.size() <= 1)
    {
        Utility::typeText("Less than or equal to 1 fighter(s). Can't make turn order");
        return;
    }
    /*for (size_t n = fighters_in_order.size(); n > 1; --n) 
    {
        bool swapped = false;
        for (size_t i = 0; i + 1 < n; ++i) 
        {
            if (fighters_in_order[i]->fight_speed < fighters_in_order[i + 1]->fight_speed) 
            {
                std::swap(fighters_in_order[i], fighters_in_order[i + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }*/

    bool sorted = false;
    while(!sorted) 
    {
        sorted = true;
        
        for (int i = 0; i < fighters_in_order.size(); i++) 
        {
            Character* temporaryf1 = fighters_in_order[i];
            
            Character* temporaryf2 = nullptr;
            int second_value = 99999;
            if ((i+1) < fighters_in_order.size()) 
            {
                temporaryf2 = fighters_in_order[i+1];
                second_value = temporaryf2->fight_speed;
            }
            
            if (temporaryf2 != nullptr) second_value = temporaryf2->fight_speed;
            else break;
            
            if (temporaryf1->fight_speed < second_value) 
            {
                sorted = false;
                fighters_in_order[i] = temporaryf2;
                fighters_in_order[i+1] = temporaryf1;
            }
        }
    }
}

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
            if (f->is_essential)
            {
                f->resetSpeedToDefault();
                continue;
            } 
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