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
    bool currentKeystate[KEYS_COUNT]; /* Текущее состояние клавиатуры */
    bool previousKeystate[KEYS_COUNT]; /* Предыдущее состояние клавиатуры */
    ALLEGRO_EVENT_QUEUE *keyboardEQ;
    ALLEGRO_EVENT keyboardEvent;
    ALLEGRO_EVENT_QUEUE *mouseEQ;
    ALLEGRO_EVENT mouseEvent;
    ALLEGRO_EVENT_QUEUE *controllerEQ;
    ALLEGRO_EVENT controllerEvent;
    bool currentMouseLeft; /* Текущее состояние левой клавиши мыши */
    bool currentMouseMiddle; /* Текущее состояние средней клавиши мыши */
    bool currentMouseRight; /* Текущее состояние правой клавиши мыши */
    bool previousMouseLeft; /* Предыдущее состояние левой клавиши мыши */
    bool previousMouseMiddle; /* Предыдущее состояние средней клавиши мыши */
    bool previousMouseRight; /* Предыдущее состояние правой клавиши мыши */
    ControllerState *currentControllerState;
    ControllerState *previousControllerState;
    ControllerAxes *controllerAxis;
    int controllersCount;
    ALLEGRO_JOYSTICK **controller;
} Input;

void InputInit(void); /* Инициализация ввода */
void InputQuit(void);
void InputKeystatesRefresh(void); /* Обновление состояния клавиатуры */
bool InputKeyPress(signed int); /* Проверка нажатия клавиши */
bool InputKeyRelease(signed int); /* Проверка отпускания клавиши */
bool InputKeyPressed(signed int); /* Проверка зажатия клавиши */
void InputMouseRefresh(void); /* Обновления состояния мыши */
void InputControllersRefresh(void); /* Обновить информацию о состоянии контроллеров */
bool InputControllerButtonPress(int, uint8_t); /* Проверка нажатия кнопки */
bool InputControllerButtonRelease(int, uint8_t); /* Проверка отпускания кнопки */
bool InputControllerButtonPressed(int, uint8_t); /* Проверка зажатия кнопки */
int16_t InputControllerGetAxis(int, int); /* Получения значения оси */

int InputJoyToID(ALLEGRO_JOYSTICK *);
int InputStickAxisToAxisnum(int, int, int);

#endif
