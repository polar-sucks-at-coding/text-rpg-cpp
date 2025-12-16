#pragma once
#include <charconv>
#include <cstddef>
#include <string>
#include <vector>

typedef unsigned int uint;

class Character;



class Item
{
    public:
    uint x_size = 1;
    uint y_size = 1;
    std::vector<uint> cells_taken_up;
    std::string info = "Placeholder Info";
    char symbol;
    bool destroyed_on_use = true;
    std::string name;
    virtual void use(Character *_character);
    Item()
    {
        this->name = "Default Item";
        this->symbol = 'd';
    };
    ~Item();
    
};

namespace Items
{
    class Health_Potion : public Item
    {
        public:
        int HP_to_restore = 10;
        void use (Character* _character);
        Health_Potion()
        {
            this->name = "Health Potion";
            this->symbol = '+';
            this->info = "Restores 10 HP";
        };
    };
}




