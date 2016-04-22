#ifndef RNJ_SCREEN_ALLEGRO5_H
#define RNJ_SCREEN_ALLEGRO5_H

#include "allegro5/allegro.h"
#include "allegro5/allegro_windows.h"

#include "app.h"
#include "log.h"
#include "error.h"
#include "defines.h"

struct {
    int width; /* Высота окна */
    int height; /* Ширина окна */
    ALLEGRO_DISPLAY *window; /* Указатель на окно */
    HWND hwnd;
} Screen;

void ScreenInit(int, int, const char *, bool); /* Инициализация окна */
void ScreenDestroy(void); /* Деинициализация окна */
void ScreenCursorShow(void); /* Показать курсор */
void ScreenCursorHide(void); /* Скрыть курсор */

#endif

