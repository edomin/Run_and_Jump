#ifndef RNJ_TIMER_SDL2_H
#define RNJ_TIMER_SDL2_H

#include <stdlib.h>
#include <SDL2/SDL.h>

#include "defines.h"
#include "log.h"
#include "error.h"

struct {
    Uint32 startTime; /* ����� ������ ������� */
} Timer;

void InitTimer(void);
void TimerStart(void); /* ��������� ������ */
int TimerGetTicks(void); /* �������� ������� ����� ������� �������� � �������� ������� ������� */
int TimerDelay(int); /* ��������� �������� ��������� �� ��������� ����� ���������� � ������� ����������� FPS */
int TimerDelayForFPS(int); /* ��������� �������� ��������� ��� ������� ����� FPS � ������� ����������� FPS */

#endif
