#ifndef RNJ_SCREEN_ALLEGRO42_H
#define RNJ_SCREEN_ALLEGRO42_H

#include "allegro42/allegro.h"
#include "allegro42/winalleg.h"

#include "app.h"
#include "log.h"
#include "error.h"
#include "defines.h"

struct {
    int     width;  /* Высота окна */
    int     height; /* Ширина окна */
    HWND    hwnd;
} Screen;

void ScreenInit(int, int, const char *, bool);  /* Инициализация окна */
void ScreenDestroy(void);                       /* Деинициализация окна */
void ScreenCursorShow(void);                    /* Показать курсор */
void ScreenCursorHide(void);                    /* Скрыть курсор */

#endif


