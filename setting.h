#ifndef SETTING_H
#define SETTING_H
#include "inventory.h"
#include <iostream>
#include <vector>

typedef unsigned int uint;

namespace Setting
{
    inline int typing_speed = 50;
    static int inventory_item_name_offset = 2;
    static int inventory_item_info_offset = inventory_item_name_offset + 2;
    
    inline const uint amount_of_settings = 1;
    
    void resetSettings();
    void changeTypingSpeedPreset();
};


#endif