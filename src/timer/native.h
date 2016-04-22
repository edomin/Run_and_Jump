#ifndef RNJ_TIMER_NATIVE_H
#define RNJ_TIMER_NATIVE_H

/* � ������ ������ ������ ������ ��� KolibriOS */

#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <math.h>

#include "defines.h"
#include "log.h"
#include "error.h"

struct {
    uint32_t startTime; /* ����� ������ ������� */
} Timer;

uint32_t kolibrios_GetTicks(void);
void kolibrios_Delay(uint32_t ms);

void InitTimer(void);
void TimerStart(void); /* ��������� ������ */
int TimerGetTicks(void); /* �������� ������� ����� ������� �������� � �������� ������� ������� */
int TimerDelay(int); /* ��������� �������� ��������� �� ��������� ����� ���������� � ������� ����������� FPS */
int TimerDelayForFPS(int); /* ��������� �������� ��������� ��� ������� ����� FPS � ������� ����������� FPS */

#endif


