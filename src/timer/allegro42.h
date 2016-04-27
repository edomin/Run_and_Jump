#ifndef RNJ_TIMER_ALLEGRO42_H
#define RNJ_TIMER_ALLEGRO42_H

#include <stdlib.h>
#include "allegro42/allegro.h"

#include "defines.h"
#include "log.h"
#include "error.h"

struct {
    uint32_t startTime; /* Время начала отсчета */
    uint32_t ms;        /* Время с начала инициализации таймера */
} Timer;

void InitTimer(void);
void TimerStart(void);      /* Запустить таймер */
int TimerGetTicks(void);    /* Получить разницу между текущим временем и
                               временем запуска таймера */
int TimerDelay(int);        /* Выполнить задержку приложния на указанное число
                               милисекунд и вернуть фактический FPS */
int TimerDelayForFPS(int);  /* Выполнить задержку приложния для нужного числа
                               FPS и вернуть фактический FPS */

#endif
