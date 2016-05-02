#ifndef RNJ_FONTS_FREETYPE2_H
#define RNJ_FONTS_FREETYPE2_H

#include <string.h>
#include <ft2build.h>
#include FT_FREETYPE_H
#include "bool.h"

#include "log.h"
#include "error.h"
#include "defines.h"

typedef struct ttf_font {
    FT_Face face;
} TTF_Font;

struct {
    int fontsCount;
    TTF_Font **font;
    char **name;
    FT_Library library;

    FT_Glyph_Metrics metrics[256];
} Fonts;

bool FontsInit(int);/* Инициализация */
int FontsLoadFont(char *, int);/* Загрузка шрифта */
void FontsDestroyFont(int); /* уничтожение шрифта */
void FontsQuit(void); /* завершаем работу менеджера шрифтов */


#endif

