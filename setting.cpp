#include "setting.h"

const int default_typing_speed = 50;

void Setting::resetSettings()
{
    Setting::typing_speed = default_typing_speed;
}