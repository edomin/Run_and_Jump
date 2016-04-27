#ifndef RNJ_INPUT_SDL2_H
#define RNJ_INPUT_SDL2_H

#include <stdlib.h>

#include BOOLLIB
#include "SDL2/SDL.h"
#include "SDL2/SDL_gamecontroller.h"

#include "log.h"
#include "error.h"
#include "app.h"
#include "defines.h"

typedef Uint8 ControllerState[16];
typedef Sint16 ControllerAxes[7];

struct {
    const Uint8 *currentKeystate; /* Текущее состояние клавиатуры */
    Uint8 previousKeystate[513]; /* Предыдущее состояние клавиатуры */
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
    SDL_GameController **controller;
} Input;

void InputInit(void); /* Инициализация ввода */
void InputQuit(void);
void InputKeystatesRefresh(void); /* Обновление состояния клавиатуры */
bool InputKeyPress(signed int); /* Проверка нажатия клавиши */
bool InputKeyRelease(signed int); /* Проверка отпускания клавиши */
bool InputKeyPressed(signed int); /* Проверка зажатия клавиши */
void InputMouseRefresh(void); /* Обновления состояния мыши */
void InputControllersRefresh(void); /* Обновить информацию о состоянии контроллеров */
bool InputControllerButtonPress(int, Uint8); /* Проверка нажатия кнопки */
bool InputControllerButtonRelease(int, Uint8); /* Проверка отпускания кнопки */
bool InputControllerButtonPressed(int, Uint8); /* Проверка зажатия кнопки */
Sint16 InputControllerGetAxis(int, int); /* Получения значения оси */

#endif
