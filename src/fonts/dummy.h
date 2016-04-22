#ifndef RNJ_FONTS_DUMMY_H
#define RNJ_FONTS_DUMMY_H

#include <string.h>
#include "bool.h"

#include "log.h"
#include "error.h"
#include "defines.h"

//struct {
//    int fontsCount;
//    TTF_Font **font;
//    char **name;
//} Fonts;

bool FontsInit(int);/* Инициализация */
int FontsLoadFont(char *, int);/* Загрузка шрифта */
void FontsDestroyFont(int); /* уничтожение шрифта */
void FontsQuit(void); /* завершаем работу менеджера шрифтов */


#endif



