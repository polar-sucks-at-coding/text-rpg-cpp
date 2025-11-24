#include "item.h"
#include "character.h"
#include "utility.h"

Item::~Item() = default;

void Health_Potion::use(Character* _character)
{
    _character->restoreHP(this->HP_to_restore);
}

void Item::use(Character* _character)
{
    Utility::typeText("This item is just a template lol");
}