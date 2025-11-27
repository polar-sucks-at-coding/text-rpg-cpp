#include "inventory.h"
#include "item.h"

void Inventory::addItem(Item* _item)
{
    //if (_item->name == "Health Potion") items.push_back(new Health_Potion); return; (my stupid ass thought this was necessary)

    items.push_back(_item);
}

Inventory::~Inventory()
{
    for (Item* item : items)
    {
        delete item;
    }
}