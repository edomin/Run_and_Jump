#ifndef RNJ_SCREEN_ALLEGRO42_H
#define RNJ_SCREEN_ALLEGRO42_H

#ifdef PLATFORM_WIN32
    #define ALLEGRO_NO_MAGIC_MAIN
#endif
#include "allegro42/allegro.h"
#ifdef PLATFORM_WIN32
    #include "allegro42/winalleg.h"
#endif

#include "app.h"
#include "log.h"
#include "error.h"
#include "defines.h"

struct {
    int     width;  /* Высота окна */
    int     height; /* Ширина окна */
    #ifdef PLATFORM_WIN32
    HWND    hwnd;
    #endif
} Screen;

void ScreenInit(int, int, const char *, bool);  /* Инициализация окна */
void ScreenDestroy(void);                       /* Деинициализация окна */
void ScreenCursorShow(void);                    /* Показать курсор */
void ScreenCursorHide(void);                    /* Скрыть курсор */

#endif


