#ifndef SETTING_H
#define SETTING_H
#include <iostream>
#include <vector>

typedef unsigned int uint;

namespace Setting
{
    inline int typing_speed = 50;
    
    inline const uint amount_of_settings = 1;
    
    void resetSettings();
    void changeTypingSpeedPreset();
};


#endif