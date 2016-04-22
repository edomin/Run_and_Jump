#ifndef RNJ_TIMER_SDL12_H
#define RNJ_TIMER_SDL12_H

#include <stdlib.h>
#include <SDL/SDL.h>

#include "defines.h"
#include "log.h"
#include "error.h"

struct {
    Uint32 startTime; /* Время начала отсчета */
} Timer;

void InitTimer(void);
void TimerStart(void); /* Запустить таймер */
int TimerGetTicks(void); /* Получить разницу между текущим временем и временем запуска таймера */
int TimerDelay(int); /* Выполнить задержку приложния на указанное число милисекунд и вернуть фактический FPS */
int TimerDelayForFPS(int); /* Выполнить задержку приложния для нужного числа FPS и вернуть фактический FPS */

#endif

