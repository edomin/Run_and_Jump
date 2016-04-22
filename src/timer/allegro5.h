#ifndef RNJ_TIMER_ALLEGRO5_H
#define RNJ_TIMER_ALLEGRO5_H

#include <stdlib.h>
#include "allegro5/allegro.h"

#include "defines.h"
#include "log.h"
#include "error.h"

struct {
    double startTime; /* ����� ������ ������� */
} Timer;

void InitTimer(void);
void TimerStart(void); /* ��������� ������ */
int TimerGetTicks(void); /* �������� ������� ����� ������� �������� � �������� ������� ������� */
int TimerDelay(int); /* ��������� �������� ��������� �� ��������� ����� ���������� � ������� ����������� FPS */
int TimerDelayForFPS(int); /* ��������� �������� ��������� ��� ������� ����� FPS � ������� ����������� FPS */

#endif
