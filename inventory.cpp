#include "inventory.h"
#include "item.h"

void Inventory::addItem(Item* _item)
{
    if (_item->name == "Health Potion") items.push_back(new Health_Potion); return;
}

Inventory::~Inventory()
{
    for (Item* item : items)
    {
        delete item;
    }
}