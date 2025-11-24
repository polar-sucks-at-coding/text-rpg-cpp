#pragma once
#include "item.h"
#include <vector>

class Item;

class Inventory
{
    public:
    std::vector<Item*> items;
    void addItem(Item* _item);
    ~Inventory();
};