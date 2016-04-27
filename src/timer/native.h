#ifndef RNJ_TIMER_NATIVE_H
#define RNJ_TIMER_NATIVE_H

/* В данный момент модуль только для KolibriOS */

#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <math.h>

#include "defines.h"
#include "log.h"
#include "error.h"

struct {
    uint32_t startTime; /* Время начала отсчета */
} Timer;

uint32_t kolibrios_GetTicks(void);
void kolibrios_Delay(uint32_t ms);

void InitTimer(void);
void TimerStart(void);      /* Запустить таймер */
int TimerGetTicks(void);    /* Получить разницу между текущим временем и
                               временем запуска таймера */
int TimerDelay(int);        /* Выполнить задержку приложния на указанное число
                               милисекунд и вернуть фактический FPS */
int TimerDelayForFPS(int);  /* Выполнить задержку приложния для нужного числа
                               FPS и вернуть фактический FPS */

#endif


