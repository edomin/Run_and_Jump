#ifndef RNJ_SPRITES_ALLEGRO5_IMAGE_H
#define RNJ_SPRITES_ALLEGRO5_IMAGE_H

#include <stdlib.h>
#include <string.h>

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"

#include "app.h"
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
    ALLEGRO_BITMAP *texture; /* Картинка спрайта */
    Rect *clip; /* Максимальное число кадров анимации */
    int clipsCount; /* Количество кадров анимации */
    char *name; /* Имя спрайта (имя файла или строка для текстового спрайта) */
    int width; /* Ширина кадра спрайта */
    int height; /* Высота кадра спрайта */
    /* Значения для текстовых спрайтов */
    ALLEGRO_USTR *text; /* Текст */
    int fontNum; /* Номер шрифта */
    int textR; /* Красный компонент */
    int textG; /* Зеленый компонент */
    int textB; /* Синий компонент */
    int wrapLength; /* Длина строки для многострочного текста (не будет работать) */
} *Sprite;

struct {
    int spritesCount;
    //SDL_Surface *loadedImage; /* временная поверхность для загруженных изображений */
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

