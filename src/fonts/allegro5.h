#ifndef RNJ_FONTS_ALLEGRO5_H
#define RNJ_FONTS_ALLEGRO5_H

#include <string.h>
#include "allegro5/allegro.h"
#include "allegro5/allegro_ttf.h"
#include "allegro5/allegro_font.h"

#include "log.h"
#include "error.h"
#include "defines.h"

struct {
    int             fontsCount;
    ALLEGRO_FONT ** font;
    char **         name;
} Fonts;

bool FontsInit(int);            /* Инициализация */
int FontsLoadFont(char *, int); /* Загрузка шрифта */
void FontsDestroyFont(int);     /* уничтожение шрифта */
void FontsQuit(void);           /* завершаем работу менеджера шрифтов */


#endif

