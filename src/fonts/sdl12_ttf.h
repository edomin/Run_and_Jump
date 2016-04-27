#ifndef RNJ_FONTS_SDL12_TTF_H
#define RNJ_FONTS_SDL12_TTF_H

#include <string.h>
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "bool.h"

#include "log.h"
#include "error.h"
#include "defines.h"

struct {
    int         fontsCount;
    TTF_Font ** font;
    char **     name;
} Fonts;

bool FontsInit(int);            /* Инициализация */
int FontsLoadFont(char *, int); /* Загрузка шрифта */
void FontsDestroyFont(int);     /* уничтожение шрифта */
void FontsQuit(void);           /* завершаем работу менеджера шрифтов */


#endif


