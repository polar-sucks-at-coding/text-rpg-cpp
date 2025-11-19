#include "setting.h"
#include "utility.h"

const int default_typing_speed = 50;

typedef unsigned int uint;

void Setting::resetSettings()
{
    Setting::typing_speed = default_typing_speed;
}

void Setting::changeTypingSpeedPreset()
{
    Setting::typing_speed = 101 - Utility::slider(1, 100);
}