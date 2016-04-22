#include "input/sdl12.h"

void InputInit(void)
{
//    int nJoysticks;
//    int i;
//    int j;
    LogWrite("Initializing Input Subsystem", 0, MT_INFO, NULL);
    LogWrite("Initializing Keyboard State", 1, MT_INFO, NULL);
    Input.currentKeystate = SDL_GetKeyState(NULL);
    if (Input.currentKeystate != NULL)
    {
    	LogWrite("Keyboard State initialized", 1, MT_INFO, NULL);
    }
    else
    {
    	ErrorGive("Can not initialize Keyboard State", 1);
    }
//    LogWrite("Initializing Controller's support", 1, MT_INFO, NULL);
//    if(SDL_InitSubSystem(SDL_INIT_JOYSTICK | SDL_INIT_GAMECONTROLLER) == 0)
//    {
//    	LogWrite("Controller's support initialized", 1, MT_INFO, NULL);
//    }
//    else
//    {
//    	ErrorGive("Can not initialize Controller's support", 1);
//    }

//    if (SDL_GameControllerAddMappingsFromFile("gamecontrollerdb.txt") != -1)
//        LogWrite("Controller mappings added", 1, MT_INFO, NULL);
//    else
//        LogWrite("Can not add controller mappings", 1, MT_WARNING, NULL);
//
//    nJoysticks = SDL_NumJoysticks();
//    if(nJoysticks < 1)
//        LogWrite("Connected controllers not found", 1, MT_INFO, NULL);
//    Input.controllersCount = 0;
//
//    for (i = 0; i < nJoysticks; i++)
//    {
//        if (SDL_IsGameController(i))
//        {
//            Input.controllersCount++;
//            LogWrite("Controller found:", 1, MT_INFO, (char *)SDL_GameControllerNameForIndex(i));
//        }
//    }
//    if (Input.controllersCount > 0)
//    {
//        Input.controller = malloc(sizeof(SDL_GameController *) * Input.controllersCount);
//    }
//    for(i = 0; i < Input.controllersCount; i++)
//    {
//        Input.controller[i] = SDL_GameControllerOpen(i);
//        if(Input.controller[i] == NULL)
//            LogWrite("Can not open controller for use", 1, MT_WARNING, NULL);
//    }
//    if (Input.controllersCount > 0)
//    {
//        Input.currentControllerState = malloc(sizeof(ControllerState) * Input.controllersCount);
//        Input.previousControllerState = malloc(sizeof(ControllerState) * Input.controllersCount);
//        Input.controllerAxis = malloc(sizeof(ControllerAxes) * Input.controllersCount);
//    }
//
//    for (j = 0; j < Input.controllersCount; j++)
//    {
//        for (i = 0; i < 16; i++)
//        {
//            Input.currentControllerState[j][i] = 0;
//            Input.previousControllerState[j][i] = 0;
//        }
//    }

    Input.currentMouseLeft = false;
    Input.currentMouseMiddle = false;
    Input.currentMouseRight = false;

    LogWrite("Input subsystem initialized", 0, MT_INFO, NULL);
}

void InputQuit(void)
{
//    int i;
//    for (i = 0; i < Input.controllersCount; i++)
//    {
//         SDL_GameControllerClose(Input.controller[i]);
//         Input.controller[i] = NULL;
//    }
//    if (Input.controllersCount > 0)
//    {
//        free(Input.controller);
//        free(Input.currentControllerState);
//        free(Input.previousControllerState);
//        free(Input.controllerAxis);
//    }
    LogWrite("Input subsystem destroyed", 0, MT_INFO, NULL);
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

void InputKeystatesRefresh(void)
{
    int i;
    for (i = 0; i < RNJ_KEYS_COUNT; i++)
    {
        Input.previousKeystate[i] = (Uint8) Input.currentKeystate[i];
    }
    SDL_PumpEvents();
}

void InputMouseRefresh(void)
{
    Uint32 mouseState;
    Input.previousMouseLeft = Input.currentMouseLeft;
    Input.previousMouseMiddle = Input.currentMouseMiddle;
    Input.previousMouseRight = Input.currentMouseRight;

    mouseState = SDL_GetMouseState(&App.mouseX, &App.mouseY);
    if ((mouseState & 1) > 0)
    {
        Input.currentMouseLeft = true;
    }
    else
    {
        Input.currentMouseLeft = false;
    }
    if ((mouseState & 2) > 0)
    {
        Input.currentMouseMiddle = true;
    }
    else
    {
        Input.currentMouseMiddle = false;
    }
    if ((mouseState & 4) > 0)
    {
        Input.currentMouseRight = true;
    }
    else
    {
        Input.currentMouseRight = false;
    }
}

void InputControllersRefresh(void)
{
//    int i;
//    int j;
//    for (j = 0; j < Input.controllersCount; j++)
//    {
//        for (i = 0; i < 16; i++)
//        {
//            Input.previousControllerState[j][i] = Input.currentControllerState[j][i];
//        }
//    }
//
//    SDL_GameControllerUpdate();
//    for (j = 0; j < Input.controllersCount; j++)
//    {
//        for (i = 0; i < 16; i++)
//        {
//            if (SDL_GameControllerGetButton(Input.controller[j], i) == 1)
//            {
//                Input.currentControllerState[j][i] = 1;
//            }
//            else
//            {
//                Input.currentControllerState[j][i] = 0;
//            }
//        }
//        for (i = 0; i < 7; i++)
//        {
//            Input.controllerAxis[j][i] = SDL_GameControllerGetAxis(Input.controller[j], i);
//        }
//    }
}

bool InputControllerButtonPress(int controllerNum, Uint8 button)
{
//    if (Input.controllersCount > controllerNum)
//    {
//        if ((Input.currentControllerState[controllerNum][button]) &&
//            !(Input.previousControllerState[controllerNum][button]))
//        {
//            return true;
//        }
//        else
//        {
//            return false;
//        }
//    }
//    else
//    {
//        return false;
//    }
    return false;
}

bool InputControllerButtonRelease(int controllerNum, Uint8 button)
{
//    if (Input.controllersCount > controllerNum)
//    {
//        if (!(Input.currentControllerState[controllerNum][button]) &&
//            (Input.previousControllerState[controllerNum][button]))
//        {
//            return true;
//        }
//        else
//        {
//            return false;
//        }
//    }
//    else
//    {
//        return false;
//    }
    return false;
}

bool InputControllerButtonPressed(int controllerNum, Uint8 button)
{
//    if (Input.controllersCount > controllerNum)
//    {
//        if (Input.currentControllerState[controllerNum][button])
//        {
//            return true;
//        }
//        else
//        {
//            return false;
//        }
//    }
//    else
//    {
//        return false;
//    }
    return false;
}

Sint16 InputControllerGetAxis(int controllerNum, int axis)
{
//    if (Input.controllersCount > controllerNum)
//    {
//        return Input.controllerAxis[controllerNum][axis];
//    }
//    else
//    {
//        return 0;
//    }
    return 0;
}

