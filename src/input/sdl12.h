#ifndef RNJ_INPUT_SDL12_H
#define RNJ_INPUT_SDL12_H

#include <stdlib.h>

#include BOOLLIB
#include "SDL/SDL.h"
//#include "SDL/SDL_gamecontroller.h"

#include "log.h"
#include "error.h"
#include "app.h"
#include "defines.h"

typedef Uint8 ControllerState[16];
typedef Sint16 ControllerAxes[7];

struct {
    const Uint8 *currentKeystate; /* ������� ��������� ���������� */
    Uint8 previousKeystate[RNJ_KEYS_COUNT]; /* ���������� ��������� ���������� */
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

