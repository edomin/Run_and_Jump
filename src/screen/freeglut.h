#ifndef RNJ_SCREEN_FREEGLUT_H
#define RNJ_SCREEN_FREEGLUT_H

#include "bool.h"
#include "GL/freeglut.h"
#include "GL/gl.h"
#include "GL/glu.h"

struct {
    int width; /* Высота окна */
    int height; /* Ширина окна */
    // SDL_Window *window; /* Указатель на окно */
    // HWND hwnd;
} Screen;

void ScreenInit(int, int, const char *, bool); /* Инициализация окна */
void ScreenDestroy(void); /* Деинициализация окна */
void ScreenCursorShow(void); /* Показать курсор */
void ScreenCursorHide(void); /* Скрыть курсор */

#endif

