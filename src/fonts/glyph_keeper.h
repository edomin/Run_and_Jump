#ifndef RNJ_FONTS_GLYPH_KEEPER
#define RNJ_FONTS_GLYPH_KEEPER

#include <string.h>
#ifdef PLATFORM_WIN32
    #define ALLEGRO_NO_MAGIC_MAIN
#endif
#define GLYPH_TARGET GLYPH_TARGET_ALLEGRO
#include "glyph-keeper/glyph.h"

#include "log.h"
#include "error.h"
#include "defines.h"

typedef struct {
    GLYPH_REND *rend;
    GLYPH_FACE *face;
} Font;

struct {
    int    fontsCount;
    Font * font;
    char **name;
} Fonts;

bool FontsInit(int);            /* Инициализация */
int FontsLoadFont(char *, int); /* Загрузка шрифта */
void FontsDestroyFont(int);     /* уничтожение шрифта */
void FontsQuit(void);           /* завершаем работу менеджера шрифтов */


#endif
