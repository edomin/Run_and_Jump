#ifndef RNJ_FONTS_ALLEGRO42_FONT_H
#define RNJ_FONTS_ALLEGRO42_FONT_H

#include <string.h>
#include "allegro42/alfont.h"

#include "log.h"
#include "error.h"
#include "defines.h"

struct {
    int fontsCount;
    ALFONT_FONT **font;
    char **name;
} Fonts;

bool FontsInit(int);/* ������������� */
int FontsLoadFont(char *, int);/* �������� ������ */
void FontsDestroyFont(int); /* ����������� ������ */
void FontsQuit(void); /* ��������� ������ ��������� ������� */


#endif


