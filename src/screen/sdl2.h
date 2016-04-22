#ifndef RNJ_SCREEN_SDL2_H
#define RNJ_SCREEN_SDL2_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_syswm.h"
#include "bool.h"

#include "log.h"
#include "error.h"
#include "defines.h"

struct {
    int width; /* ������ ���� */
    int height; /* ������ ���� */
    SDL_Window *window; /* ��������� �� ���� */
    #ifdef PLATFORM_WIN32
    HWND hwnd;
    #endif
} Screen;

void ScreenInit(int, int, const char *, bool); /* ������������� ���� */
void ScreenDestroy(void); /* ��������������� ���� */
void ScreenCursorShow(void); /* �������� ������ */
void ScreenCursorHide(void); /* ������ ������ */

#endif

