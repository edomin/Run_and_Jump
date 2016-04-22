#ifndef RNJ_SCREEN_ALLEGRO42_H
#define RNJ_SCREEN_ALLEGRO42_H

#include "allegro42/allegro.h"
//#include "allegro42/allegro_windows.h"

#include "app.h"
#include "log.h"
#include "error.h"
#include "defines.h"

struct {
    int width; /* ������ ���� */
    int height; /* ������ ���� */
//    ALLEGRO_DISPLAY *window; /* ��������� �� ���� */
    HWND hwnd;
} Screen;

void ScreenInit(int, int, const char *, bool); /* ������������� ���� */
void ScreenDestroy(void); /* ��������������� ���� */
void ScreenCursorShow(void); /* �������� ������ */
void ScreenCursorHide(void); /* ������ ������ */

#endif


