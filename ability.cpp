#include "ability.h"
#include "character.h"
#include "utility.h"

void Ability::removeAllTargets()
{
    targets.clear();
}

void Ability::use(Character* _user)
{
    Utility::typeText("Im the default ability yeawdwadwadasdsa");
}

void Ability::addTarget(Character* _targ)
{
    if (targets.size() >= this->target_amount) {Utility::typeText("This ability can't target any more characters"); return;}
    targets.push_back(_targ);
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