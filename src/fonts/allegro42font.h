#ifndef RNJ_FONTS_ALLEGRO42_FONT_H
#define RNJ_FONTS_ALLEGRO42_FONT_H

#include <string.h>
#ifdef PLATFORM_WIN32
    #define ALLEGRO_NO_MAGIC_MAIN
#endif
#include "allegro42/alfont.h"

#include "log.h"
#include "error.h"
#include "defines.h"

struct {
    int             fontsCount;
    ALFONT_FONT **  font;
    char **         name;
} Fonts;

bool FontsInit(int);            /* Инициализация */
int FontsLoadFont(char *, int); /* Загрузка шрифта */
void FontsDestroyFont(int);     /* уничтожение шрифта */
void FontsQuit(void);           /* завершаем работу менеджера шрифтов */


#endif


