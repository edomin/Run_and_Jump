#ifndef RNJ_SPRITES_DUMMY_H
#define RNJ_SPRITES_DUMMY_H

#include <stdlib.h>
#include <string.h>

#include "app.h"
#include "draw.h"
#include "fonts.h"
#include "error.h"
#include "log.h"
#include "defines.h"

typedef struct rect {
    int x;
    int y;
    int w;
    int h;
} Rect;

struct sprite {
    int     texture;    /* Картинка спрайта */
    Rect *  clip;       /* Максимальное число кадров анимации */
    int     clipsCount; /* Количество кадров анимации */
    char *  name;       /* Имя спрайта (имя файла или строка для текстового спрайта) */
    int     width;
    int     height;
} *Sprite;

struct {
    int spritesCount;
} Sprites;

/* Инициализация */
void SpritesInit(int);
/* Создание спрайта */
int SpritesCreateSprite(char *, int);
/* Создание текстового спрайта */
int SpritesCreateText(char *, int, int, int, int, int);
/* Измененяет текста на существующем текстовом спрайте и возвращает его номер */
void SpritesChangeText(int, char *, int, int, int, int, int);
/* Вывод спрайта */
void SpritesBlitSprite(int, int, int, int, int, int, int, int, double, int,
                       int);
/* уничтожение спрайта */
void SpritesDestroySprite(int);
/* завершаем работу манеджера спрайтов */
void SpritesQuit(void);

#endif


