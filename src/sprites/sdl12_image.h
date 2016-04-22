#ifndef RNJ_SPRITES_SDL12_IMAGE_H
#define RNJ_SPRITES_SDL12_IMAGE_H

#include <stdlib.h>
#include <string.h>

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

#include "app.h"
#include "draw.h"
#include "fonts.h"
#include "error.h"
#include "log.h"
#include "defines.h"

struct sprite {
    SDL_Surface *texture; /* Картинка спрайта */
    SDL_Rect *clip; /* Максимальное число кадров анимации */
    int clipsCount; /* Количество кадров анимации */
    char *name; /* Имя спрайта (имя файла или строка для текстового спрайта) */
    int width;
    int height;
} *Sprite;

struct {
    int spritesCount;
    SDL_Surface *loadedImage; /* временная поверхность для загруженных изображений */
    SDL_Surface *tempImage;
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

