#ifndef RNJ_TIMER_TIME_H_H
#define RNJ_TIMER_TIME_H_H

#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#include "defines.h"
#include "log.h"
#include "error.h"

struct {
    uint32_t startTime; /* Время начала отсчета */
} Timer;

void InitTimer(void);
void TimerStart(void); /* Запустить таймер */
int TimerGetTicks(void); /* Получить разницу между текущим временем и временем запуска таймера */
int TimerDelay(int); /* Выполнить задержку приложния на указанное число милисекунд и вернуть фактический FPS */
int TimerDelayForFPS(int); /* Выполнить задержку приложния для нужного числа FPS и вернуть фактический FPS */

#endif

