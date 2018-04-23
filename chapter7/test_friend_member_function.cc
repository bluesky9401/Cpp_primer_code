#include <iostream>
#include "Screen.h"

int main()
{
    WindowMgr manage_screen;
    manage_screen.clear(WindowMgr::ScreenIndex(1));
    return 0;
}
