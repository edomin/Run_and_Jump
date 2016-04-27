#ifndef RNJ_SCREEN_SDL2_H
#define RNJ_SCREEN_SDL2_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_syswm.h"
#include "bool.h"

#include "log.h"
#include "error.h"
#include "defines.h"

struct {
    int         width;  /* Высота окна */
    int         height; /* Ширина окна */
    SDL_Window *window; /* Указатель на окно */
    #ifdef PLATFORM_WIN32
    HWND        hwnd;
    #endif
} Screen;

void ScreenInit(int, int, const char *, bool);  /* Инициализация окна */
void ScreenDestroy(void);                       /* Деинициализация окна */
void ScreenCursorShow(void);                    /* Показать курсор */
void ScreenCursorHide(void);                    /* Скрыть курсор */

#endif

