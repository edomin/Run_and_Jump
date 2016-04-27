#include "input/dummy.h"

void InputInit(void)
{
    return;
}

void InputQuit(void)
{
    return;
}

bool InputKeyPress(signed int key)
{
    return false;
}

bool InputKeyRelease(signed int key)
{
    return false;
}

bool InputKeyPressed(signed int key)
{
    return false;
}

void InputKeystatesRefresh(void)
{
    return;
}

void InputMouseRefresh(void)
{
    return;
}

void InputControllersRefresh(void)
{
    return;
}

bool InputControllerButtonPress(int controllerNum, uint8_t button)
{
    return false;
}

bool InputControllerButtonRelease(int controllerNum, uint8_t button)
{
    return false;
}

bool InputControllerButtonPressed(int controllerNum, uint8_t button)
{
    return false;
}

int16_t InputControllerGetAxis(int controllerNum, int axis)
{
    return 0;
}
