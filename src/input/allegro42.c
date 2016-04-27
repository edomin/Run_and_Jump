#include "input/allegro42.h"

void InputInit(void)
{
    int i;
    int j;
    int k;
    int nMouseButtons;
    LogWrite("Initializing Input Subsystem", 0, MT_INFO, NULL);
    LogWrite("Installing keyboard interrupt handler", 1, MT_INFO, NULL);
    if (install_keyboard() == 0)
    {
        LogWrite("Keyboard interrupt handler installed", 2, MT_INFO, NULL);
    }
    else
    {
        ErrorGive("Unable to install keyboard interrupt handler", 2);
    }

    for (i = 0; i < RNJ_KEYS_COUNT; i++)
    {
        Input.currentKeystate[i] = false;
    }
    LogWrite("Keystates initialized", 1, MT_INFO, NULL);

    LogWrite("Installing mouse handler", 1, MT_INFO, NULL);
    nMouseButtons = install_mouse();
    if (nMouseButtons >= 0)
    {
        if (nMouseButtons > 0)
        {
            LogWrite("Mouse handler installed", 2, MT_INFO, NULL);
            LogWrite2("Mouse buttons found:", 2, MT_INFO, nMouseButtons);
        }
        else
        {
            LogWrite("Mouse handler already installed", 2, MT_WARNING, NULL);
        }
    }
    else
    {
        ErrorGive("Unable to install mouse handler", 2);
    }
    Input.currentMouseLeft = false;
    Input.currentMouseMiddle = false;
    Input.currentMouseRight = false;
    LogWrite("Mouse button states initialized", 1, MT_INFO, NULL);

    LogWrite("Installing joystick handler", 1, MT_INFO, NULL);
    if (install_joystick(JOY_TYPE_AUTODETECT) == 0)
    {
        LogWrite("Joystick handler installed", 2, MT_INFO, NULL);
    }
    else
    {
        ErrorGive("Unable to install joystick handler", 2);
    }

    Input.controllersCount = num_joysticks;
    LogWrite2("Controllers found", 1, MT_INFO, Input.controllersCount);
    Input.controller = malloc(sizeof(Controller) * Input.controllersCount);
    if (Input.controller == NULL)
    {
        ErrorGive("Unable to allocate memory for Controllers", 1);
    }
    if (Input.controllersCount > 0)
    {
        LogWrite("Creating structures of controllers for buttons and axes", 1,
                 MT_INFO, NULL);
        for (i = 0; i < Input.controllersCount; i++)
        {
            int nAxes;
            Input.controller[i].nButtons = joy[i].num_buttons;
            Input.controller[i].currentButtonsState = malloc(sizeof(int) * Input.controller[i].nButtons);
            if (Input.controller[i].currentButtonsState == NULL)
            {
                ErrorGive("Unable to allocate memory for current state of controller buttons", 2);
            }
            Input.controller[i].previousButtonsState = malloc(sizeof(int) * Input.controller[i].nButtons);
            if (Input.controller[i].currentButtonsState == NULL)
            {
                ErrorGive("Unable to allocate memory for previous state of controller buttons", 2);
            }
            for (j = 0; j < Input.controller[i].nButtons; j++)
            {
                Input.controller[i].currentButtonsState[j] = false;
            }
            /* Считаем количество осей на всех стиках */
            nAxes = 0;
            for (j = 0; j < joy[i].num_sticks; j++)
            {
                nAxes += joy[i].stick[j].num_axis;
            }
            Input.controller[i].nAxes = nAxes;
            Input.controller[i].axis = malloc(sizeof(Axis) * Input.controller[i].nAxes);
            if (Input.controller[i].axis == NULL)
            {
                ErrorGive("Unable to allocate memory controller axes state", 2);
            }
            /* А теперь заново проходимся по стикам и записываем, на каком стике
               расположена каждая ось */
            nAxes = 0;
            for (j = 0; j < joy[i].num_sticks; j++)
            {
                for (k = 0; k < joy[i].stick[j].num_axis; k++)
                {
                    Input.controller[i].axis[nAxes].stickNum = j;
                    Input.controller[i].axis[nAxes].axisNum = k;
                    nAxes += 1;
                }
            }
            LogWrite2("Done for controller:", 2, MT_INFO, i);
        }
        LogWrite("Reporting Controllers' specification", 1, MT_INFO, NULL);
        for (i = 0; i < Input.controllersCount; i++)
        {
            LogWrite2("No.", 2, MT_INFO, i);
            LogWrite("Checking controller's sticks/D-Pads", 3, MT_INFO, NULL);
            if (joy[i].num_sticks > 0)
            {
                LogWrite2("Sticks/D-Pads found:", 3, MT_INFO,
                          joy[i].num_sticks);
                for (j = 0; j < joy[i].num_sticks; j++)
                {
                    LogWrite2("No.", 4, MT_INFO, j);
                    LogWrite("Stick/D-Pad name:", 5, MT_INFO,
                             (char *)(joy[i].stick[j].name));
                    LogWrite2("Axes found:", 5, MT_INFO,
                              joy[i].stick[j].num_axis);
                    for (k = 0; k < joy[i].stick[j].num_axis; k++)
                    {
                        LogWrite2("No.", 6, MT_INFO, k);
                        LogWrite("Axis name:", 7, MT_INFO,
                                 (char *)(joy[i].stick[j].axis[k].name));
                    }
                }
            }
            LogWrite2("Buttons found:", 3, MT_INFO, joy[i].num_buttons);
            for (j = 0; j < joy[i].num_buttons; j++)
            {
                LogWrite2("No.", 4, MT_INFO, j);
                LogWrite("Button name:", 5, MT_INFO,
                         (char *)(joy[i].button[j].name));
            }
        }
    }
    else
    {
        Input.controller = NULL;
    }

    LogWrite("Input subsystem initialized", 0, MT_INFO, NULL);
}

void InputQuit(void)
{
    LogWrite("Destroying input subsystem", 0, MT_INFO, NULL);
    LogWrite("Input subsystem destroyed", 0, MT_INFO, NULL);
}

void InputKeystatesRefresh(void)
{
    int i;
    if (keyboard_needs_poll())
        poll_keyboard();
    for (i = 0; i < RNJ_KEYS_COUNT; i++)
    {
        Input.previousKeystate[i] = Input.currentKeystate[i];
        Input.currentKeystate[i] = key[i];
    }
}

bool InputKeyPress(signed int key)
{
    if ((Input.currentKeystate[key]) &&
        !(Input.previousKeystate[key]))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool InputKeyRelease(signed int key)
{
    if (!(Input.currentKeystate[key]) &&
        (Input.previousKeystate[key]))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool InputKeyPressed(signed int key)
{
    if (Input.currentKeystate [key])
    {
        return true;
    }
    else
    {
        return false;
    }
}

void InputMouseRefresh(void)
{
    if (mouse_needs_poll())
        poll_mouse();
    App.mouseX = mouse_x;
    App.mouseY = mouse_y;

    Input.previousMouseLeft = Input.currentMouseLeft;
    Input.previousMouseMiddle = Input.currentMouseMiddle;
    Input.previousMouseRight = Input.currentMouseRight;

    if (mouse_b & 1)
        Input.currentMouseLeft = true;
    else
        Input.currentMouseLeft = false;
    if (mouse_b & 2)
        Input.currentMouseRight = true;
    else
        Input.currentMouseRight = false;
    if (mouse_b & 3)
        Input.currentMouseMiddle = true;
    else
        Input.currentMouseMiddle = false;
}

void InputControllersRefresh(void)
{
    int i;
    int j;
    poll_joystick();
    if (Input.controllersCount > 0)
    {
        for (i = 0; i < Input.controllersCount; i++)
        {
            for (j = 0; j < Input.controller[i].nButtons; j++)
            {
                Input.controller[i].previousButtonsState[j] = Input.controller[i].currentButtonsState[j];
            }
        }
    }
}

bool InputControllerButtonPress(int controllerNum, uint8_t button)
{
    if (Input.controllersCount > controllerNum)
    {
        if ((Input.controller[controllerNum].currentButtonsState[button]) &&
            !(Input.controller[controllerNum].previousButtonsState[button]))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool InputControllerButtonRelease(int controllerNum, uint8_t button)
{
    if (Input.controllersCount > controllerNum)
    {
        if (!(Input.controller[controllerNum].currentButtonsState[button]) &&
            (Input.controller[controllerNum].previousButtonsState[button]))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool InputControllerButtonPressed(int controllerNum, uint8_t button)
{
    if (Input.controllersCount > controllerNum)
    {
        if (Input.controller[controllerNum].currentButtonsState[button])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

int16_t InputControllerGetAxis(int controllerNum, int axis)
{
    int stickNum;
    int axisNum;
    stickNum = Input.controller[controllerNum].axis[axis].stickNum;
    axisNum = Input.controller[controllerNum].axis[axis].axisNum;
    if (Input.controllersCount > controllerNum)
    {
        return joy[controllerNum].stick[stickNum].axis[axisNum].pos;
    }
    else
    {
        return 0;
    }
}
