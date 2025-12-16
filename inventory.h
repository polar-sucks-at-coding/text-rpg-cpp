#pragma once
#include "equipment.h"
#include "item.h"
#include <vector>

typedef unsigned int uint;

class Inventory
{
    public:
    uint cols = 10;
    uint rows = 10;
    size_t cell_amount = cols * rows;
    std::vector<Item*> items;
    std::vector<Equipment*> equipment_vtr;
    std::vector<uint> full_cells;
    bool cellEmpty(uint _cell);
    bool cellExists(uint _cell);
    Item* returnCellItem(uint _cell);
    Item* returnItemFiller(uint _cell);
    size_t returnIndexFromCell(uint _cell);
    void addItem(Item* _item); //This returns a bool to check if adding the item was successful or not.
    void showUI();
    // void createSlots();
    Inventory();
    ~Inventory();
};