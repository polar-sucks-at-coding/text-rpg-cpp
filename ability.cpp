#include "ability.h"
#include "character.h"
#include "utility.h"
#include <vector>

typedef Character C;

void Ability::addSingletarget(C* _t)
{
    targets.push_back(_t);
}

Ability::~Ability()
{
    removeAllTargets();
}
void Ability::removeAllTargets()
{
    targets.clear();
}

void Ability::use(Character* _user)
{
    Utility::typeText("Im the default ability yeawdwadwadasdsa");
}

void Ability::addTargetVector(const std::vector<Character*> &_targs)
{
    if (_targs.size() == 0) {Utility::typeText("No targets provided in arguments"); return;}

    if ((_targs.size() + targets.size()) > this->max_targets) {Utility::typeText("Too many targets"); return;}

    for (int i = 0; i < _targs.size(); i++) 
    {
      if (_targs[i] == nullptr) {Utility::typeText("Vector is fucked"); return;}
      
      targets.push_back(_targs[i]);      
    }
}

void Fart::use(Character* _user)
{
    for (Character* targ : targets)
    {
        Utility::typeText(_user->name, 0);
        Utility::typeText(" farts on ", 0);
        Utility::typeText(targ->name, 0);
        Utility::typeText("!");
    }
    removeAllTargets();
}

void Abilities::Shit::use(Character* _usr)
{
    Utility::typeText(_usr->name, 0);
    Utility::typeText(" sharts all over ", 0);

    int i = 1;
    for (C* t : targets)
    {

        Utility::typeText(t->name, 0);
        if (i <  targets.size()) 
        {
            Utility::typeText(", ", 0);
            i++;
        }
    }
    Utility::typeText(".");

    //There must be a better way to do this but I can't figure it out so for now we go thru the vector twice
    for (C* t : targets)
    {
        t->reduceHP(10);
    }
    removeAllTargets();
}

void Abilities::Piss::use(C* _usr)
{
    Utility::typeText(_usr->name, 0);
    Utility::typeText(" makes flowers grow on ", 0);

    int i = 1;
    for (C* t : targets)
    {
        

        Utility::typeText(t->name, 0);
        if (i < targets.size()) 
        {
            Utility::typeText(", ", 0); 
            i++; 
        }
        
    }
    Utility::typeText(".");

    //There must be a better way to do this but I can't figure it out so for now we go thru the vector twice
    for (C* t : targets)
    {
        t->restoreHP(10);
    }
    removeAllTargets();
    
}