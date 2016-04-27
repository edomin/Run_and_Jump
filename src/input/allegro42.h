#ifndef RNJ_INPUT_ALLEGRO42_H
#define RNJ_INPUT_ALLEGRO42_H

#include <stdlib.h>

#include BOOLLIB
#define ALLEGRO_NO_MAGIC_MAIN
#include "allegro42/allegro.h"

#include "log.h"
#include "error.h"
#include "app.h"
#include "defines.h"
#include "utils.h"

typedef struct {
    int     stickNum;
    int     axisNum;
    int16_t pos;
} Axis;

typedef struct {
    bool *currentButtonsState;
    bool *previousButtonsState;
    int   nButtons;
    Axis *axis;
    int   nAxes;
} Controller;

struct {
    bool currentKeystate[RNJ_KEYS_COUNT]; /* Текущее состояние клавиатуры */
    bool previousKeystate[RNJ_KEYS_COUNT]; /* Предыдущее состояние клавиатуры */
    bool currentMouseLeft; /* Текущее состояние левой клавиши мыши */
    bool currentMouseMiddle; /* Текущее состояние средней клавиши мыши */
    bool currentMouseRight; /* Текущее состояние правой клавиши мыши */
    bool previousMouseLeft; /* Предыдущее состояние левой клавиши мыши */
    bool previousMouseMiddle; /* Предыдущее состояние средней клавиши мыши */
    bool previousMouseRight; /* Предыдущее состояние правой клавиши мыши */
    Controller *controller;
    int controllersCount;
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

//int InputJoyToID(ALLEGRO_JOYSTICK *);
//int InputStickAxisToAxisnum(int, int, int);

#endif

