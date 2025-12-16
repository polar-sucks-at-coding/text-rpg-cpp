#include "inventory.h"
#include "item.h"
#include "setting.h"
#include "utility.h"
#include <algorithm>
#include <cctype>
#include <cstddef>
#include <ctime>
#include <ios>
#include <ncurses.h>
#include <future>
#include <string>

typedef unsigned int uint;

void Inventory::showUI()
{
    initscr();              // start ncurses
    cbreak();               // disable line buffering
    noecho();               // don't echo typed chars
    keypad(stdscr, TRUE);   // enable function and arrow keys
    nodelay(stdscr, FALSE); // blocking getch (change to TRUE for non-blocking)
    //curs_set(0);            // hide cursor
    clear();

    move(0, 0);

    // Drawing all cells
    char char_to_add;
    bool empty;
    for (int i = 0; i < cell_amount; i++)
    {
        size_t y = i / cols;
        size_t x = i % cols;
        size_t cell_idx = x + y * cols;
        Item* cell_item = returnCellItem(cell_idx);

        move((int)y, (int)x);

        empty = true;

        if (cell_item != nullptr)
        {
            char_to_add = std::toupper(cell_item->symbol);
        }
        else if (!cellEmpty(cell_idx))
        {
            char_to_add = std::tolower(returnItemFiller(cell_idx)->symbol);
        }
        else char_to_add = '-';

        addch(char_to_add);
    }

    move (rows + 6, 0);
    printw("\nPress arrow keys (q to quit)\n");

    move(0,0);
    refresh();

    int ch; // short for character, not related to cx and cy
    int selected_cell = 0;

    // main loop
    while ((ch = getch()) != 'q')
    {
        switch (ch) {
            case KEY_UP:
                selected_cell -= cols;
                break;
            case KEY_DOWN:
            case 's':
                selected_cell += cols;
                break;
            case KEY_LEFT:
                selected_cell--;
                break;
            case KEY_RIGHT:
                selected_cell++;
                break;
        }

        if (selected_cell >= (int)cell_amount) selected_cell = 0;
        if (selected_cell < 0) selected_cell = (int)cell_amount - 1;

        // deleting old name and info
        move(Setting::inventory_item_name_offset + rows, 0);
        clrtoeol();
        move(Setting::inventory_item_info_offset + rows, 0);
        clrtoeol();

        if (!cellEmpty(selected_cell))
        {
            Item* held_item = returnItemFiller(selected_cell);
            if (held_item != nullptr)
            {
                move(Setting::inventory_item_name_offset + rows, 0);
                printw("Full slot occupied by: ");
                printw("%s", held_item->name.c_str());
            }
            else
            {
                held_item = returnCellItem(selected_cell);
                move(Setting::inventory_item_name_offset + rows, 0);
                printw("%s", held_item->name.c_str());

                move(Setting::inventory_item_info_offset + rows, 0);
                printw("%s", held_item->info.c_str());
            }
        }
        else 
        {
            move(Setting::inventory_item_name_offset + rows, 0);
            printw("Empty Slot");
        }

        move(selected_cell / cols, selected_cell % cols);

        refresh();
    }
    endwin();
}

size_t Inventory::returnIndexFromCell(uint _cell)
{
    int cx = _cell % cols;
    int cy = _cell / cols;
    int cidx = cx + cy * cols;
    return cidx;
}

Item* Inventory::returnItemFiller(uint _cell)
{
    for (Item* item : items)
    {
        for (size_t cell : item->cells_taken_up)
        {
            if (returnIndexFromCell(_cell) == item->cells_taken_up.front()) continue;
            if (returnIndexFromCell(_cell) == cell) return item;
        }
    }
    return nullptr;
}

Item* Inventory::returnCellItem(uint _cell)
{
    for (Item* item : items)
    {
        if (returnIndexFromCell(_cell) == item->cells_taken_up.front()) return item;
    }
    return nullptr;
}

bool Inventory::cellEmpty(uint _cell)
{
    for (size_t x = 0; x < full_cells.size(); x++)
    {
        if (_cell == full_cells[x]) { return false; }
    }
    return true;
}

void Inventory::addItem(Item* _item)
{
    uint item_size = _item->x_size * _item->y_size;
    size_t start;
    std::vector<uint> chosen_cells;
    bool fits = false;

    for (start = 0; start < cell_amount; ++start)
    {
        int sx = start % cols;
        int sy = start / cols;
        if (sx + _item->x_size > (int)cols) continue;
        if (sy + _item->y_size > (int)rows) continue;

        chosen_cells.clear();
        bool ok = true;
        for (uint dy = 0; dy < _item->y_size && ok; ++dy)
        {
            size_t row_start = start + dy * cols;

            for (uint dx = 0; dx < _item->x_size; ++dx)
            {
                size_t idx = row_start + dx;
                if (!cellEmpty((uint)idx)) { ok = false; break; }
                chosen_cells.push_back((uint)idx);
            }
        }
        if (ok) { fits = true; break; }
    }

    if (fits)
    {
        items.push_back(_item);
        _item->cells_taken_up.push_back((uint)start);

        for (uint cell : chosen_cells)
        {
            full_cells.push_back(cell);

            if (cell == (uint)start) continue;

            _item->cells_taken_up.push_back(cell);
        }
        return;
    }

    Utility::typeText("It don't fit");
}

Inventory::Inventory(){}

Inventory::~Inventory()
{
    for (Item* item : items)
    {
        delete item;
    }
}
