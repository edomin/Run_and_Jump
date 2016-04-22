#ifndef RNJ_INPUT_NATIVE_H
#define RNJ_INPUT_NATIVE_H

/* � ������ ������ ������ ������ ��� KolibriOS */

#include <stdlib.h>

#include BOOLLIB
//#include "SDL2/SDL.h"
//#include "SDL2/SDL_gamecontroller.h"

#include "log.h"
#include "error.h"
#include "app.h"
#include "defines.h"

//typedef Uint8 ControllerState[16];
//typedef Sint16 ControllerAxes[7];

struct {
    const Uint8 *currentKeystate; /* ������� ��������� ���������� */
    Uint8 previousKeystate[513]; /* ���������� ��������� ���������� */
    bool currentMouseLeft; /* ������� ��������� ����� ������� ���� */
    bool currentMouseMiddle; /* ������� ��������� ������� ������� ���� */
    bool currentMouseRight; /* ������� ��������� ������ ������� ���� */
    bool previousMouseLeft; /* ���������� ��������� ����� ������� ���� */
    bool previousMouseMiddle; /* ���������� ��������� ������� ������� ���� */
    bool previousMouseRight; /* ���������� ��������� ������ ������� ���� */
//    ControllerState *currentControllerState;
//    ControllerState *previousControllerState;
//    ControllerAxes *controllerAxis;
    int controllersCount;
//    SDL_GameController **controller;
    Uint8 *keyboardState;
} Input;

void InputInit(void); /* ������������� ����� */
void InputQuit(void);
void InputKeystatesRefresh(void); /* ���������� ��������� ���������� */
bool InputKeyPress(signed int); /* �������� ������� ������� */
bool InputKeyRelease(signed int); /* �������� ���������� ������� */
bool InputKeyPressed(signed int); /* �������� ������� ������� */
void InputMouseRefresh(void); /* ���������� ��������� ���� */
void InputControllersRefresh(void); /* �������� ���������� � ��������� ������������ */
bool InputControllerButtonPress(int, Uint8); /* �������� ������� ������ */
bool InputControllerButtonRelease(int, Uint8); /* �������� ���������� ������ */
bool InputControllerButtonPressed(int, Uint8); /* �������� ������� ������ */
Sint16 InputControllerGetAxis(int, int); /* ��������� �������� ��� */

#endif

