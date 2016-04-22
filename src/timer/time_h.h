#ifndef RNJ_TIMER_TIME_H_H
#define RNJ_TIMER_TIME_H_H

#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#include "defines.h"
#include "log.h"
#include "error.h"

struct {
    uint32_t startTime; /* ����� ������ ������� */
} Timer;

void InitTimer(void);
void TimerStart(void); /* ��������� ������ */
int TimerGetTicks(void); /* �������� ������� ����� ������� �������� � �������� ������� ������� */
int TimerDelay(int); /* ��������� �������� ��������� �� ��������� ����� ���������� � ������� ����������� FPS */
int TimerDelayForFPS(int); /* ��������� �������� ��������� ��� ������� ����� FPS � ������� ����������� FPS */

#endif

