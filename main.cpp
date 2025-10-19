#include <pthread.h>
#include <string>
#include <unistd.h>
#include "menu.h"
#include "utility.h"

void createMainMenu()
{
Menu* main_menu = new Menu("main_menu");
}

int main()
{
    Utility::clearHistory();
    createMainMenu();
    
    return 0;
}
