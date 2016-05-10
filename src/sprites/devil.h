#ifndef RNJ_SPRITES_DEVIL_H
#define RNJ_SPRITES_DEVIL_H

#include <stdlib.h>
#include <string.h>
//#include <stddef.h>

#include "GL/gl.h"
#include "GL/glu.h"
#include "IL/il.h"

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
    GLuint *texture;    /* Картинка спрайта */
    Rect *clip;         /* Максимальное число кадров анимации */
    int clipsCount;     /* Количество кадров анимации */
    char *name;         /* Имя спрайта (имя файла или строка для текстового спрайта) */
    int width;
    int height;
    // GLuint bitmapWidth; /* Длина подогнанной под степень двойки текстуры */
    // GLuint bitmapHeight;/* Высота подогнанной под степень двойки текстуры */
} *Sprite;

struct {
    int spritesCount;
} Sprites;

void SpritesInit(int);/* Инициализация */
int SpritesCreateSprite(char *, int);/* Создание спрайта */
int SpritesCreateText(char *, int, int, int, int, int);/* Создание текстового спрайта */
void SpritesChangeText(int, char *, int, int, int, int, int);/* Измененяет текста на существующем текстовом спрайте */
                                                        /* и возвращает его номер */
void SpritesBlitSprite(int, int, int, int, int, int, int, int, double, int, int); /* Вывод спрайта */
void SpritesDestroySprite(int); /* уничтожение спрайта */
void SpritesQuit(void); /* завершаем работу манеджера спрайтов */

#endif
