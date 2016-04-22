#ifndef RNJ_INPUT_DIRECTINPUT7_H
#define RNJ_INPUT_DIRECTINPUT7_H

//#include <stdlib.h>

#include BOOLLIB
#define DINPUT_VERSION 0x0700
#include "windows.h"
#include "dx7sdk/dinput.h"

#include "log.h"
#include "error.h"
#include "app.h"
#include "defines.h"

//typedef Uint8 ControllerState[16];
//typedef Sint16 ControllerAxes[7];

struct {
//    const Uint8 *currentKeystate; /* ������� ��������� ���������� */
//    Uint8 previousKeystate[513]; /* ���������� ��������� ���������� */
//    bool currentMouseLeft; /* ������� ��������� ����� ������� ���� */
//    bool currentMouseMiddle; /* ������� ��������� ������� ������� ���� */
//    bool currentMouseRight; /* ������� ��������� ������ ������� ���� */
//    bool previousMouseLeft; /* ���������� ��������� ����� ������� ���� */
//    bool previousMouseMiddle; /* ���������� ��������� ������� ������� ���� */
//    bool previousMouseRight; /* ���������� ��������� ������ ������� ���� */
//    ControllerState *currentControllerState;
//    ControllerState *previousControllerState;
//    ControllerAxes *controllerAxis;
//    int controllersCount;
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

