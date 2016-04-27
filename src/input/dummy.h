#ifndef RNJ_INPUT_DUMMY_H
#define RNJ_INPUT_DUMMY_H

#include BOOLLIB
#include <stdint.h>

struct {
    bool currentKeystate[513]; /* Текущее состояние клавиатуры */
    bool previousKeystate[513];
    bool currentMouseLeft; /* Текущее состояние левой клавиши мыши */
    bool currentMouseMiddle; /* Текущее состояние средней клавиши мыши */
    bool currentMouseRight; /* Текущее состояние правой клавиши мыши */
    bool previousMouseLeft; /* Предыдущее состояние левой клавиши мыши */
    bool previousMouseMiddle; /* Предыдущее состояние средней клавиши мыши */
    bool previousMouseRight; /* Предыдущее состояние правой клавиши мыши */
} Input;
//
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
//
#endif
