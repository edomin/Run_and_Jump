#ifndef RNJ_INPUT_ALLEGRO5_H
#define RNJ_INPUT_ALLEGRO5_H

#include <stdlib.h>

#include BOOLLIB
#include "allegro5/allegro.h"

#include "log.h"
#include "error.h"
#include "app.h"
#include "defines.h"
#include "utils.h"

#define CONTROLLER_MAX_BUTTONS 16
#define CONTROLLER_MAX_AXES 7

typedef bool ControllerState[16];
typedef int16_t ControllerAxes[7];

struct {
    bool currentKeystate[KEYS_COUNT]; /* ������� ��������� ���������� */
    bool previousKeystate[KEYS_COUNT]; /* ���������� ��������� ���������� */
    ALLEGRO_EVENT_QUEUE *keyboardEQ;
    ALLEGRO_EVENT keyboardEvent;
    ALLEGRO_EVENT_QUEUE *mouseEQ;
    ALLEGRO_EVENT mouseEvent;
    ALLEGRO_EVENT_QUEUE *controllerEQ;
    ALLEGRO_EVENT controllerEvent;
    bool currentMouseLeft; /* ������� ��������� ����� ������� ���� */
    bool currentMouseMiddle; /* ������� ��������� ������� ������� ���� */
    bool currentMouseRight; /* ������� ��������� ������ ������� ���� */
    bool previousMouseLeft; /* ���������� ��������� ����� ������� ���� */
    bool previousMouseMiddle; /* ���������� ��������� ������� ������� ���� */
    bool previousMouseRight; /* ���������� ��������� ������ ������� ���� */
    ControllerState *currentControllerState;
    ControllerState *previousControllerState;
    ControllerAxes *controllerAxis;
    int controllersCount;
    ALLEGRO_JOYSTICK **controller;
} Input;

void InputInit(void); /* ������������� ����� */
void InputQuit(void);
void InputKeystatesRefresh(void); /* ���������� ��������� ���������� */
bool InputKeyPress(signed int); /* �������� ������� ������� */
bool InputKeyRelease(signed int); /* �������� ���������� ������� */
bool InputKeyPressed(signed int); /* �������� ������� ������� */
void InputMouseRefresh(void); /* ���������� ��������� ���� */
void InputControllersRefresh(void); /* �������� ���������� � ��������� ������������ */
bool InputControllerButtonPress(int, uint8_t); /* �������� ������� ������ */
bool InputControllerButtonRelease(int, uint8_t); /* �������� ���������� ������ */
bool InputControllerButtonPressed(int, uint8_t); /* �������� ������� ������ */
int16_t InputControllerGetAxis(int, int); /* ��������� �������� ��� */

int InputJoyToID(ALLEGRO_JOYSTICK *);
int InputStickAxisToAxisnum(int, int, int);

#endif
