#ifndef RNJ_IMAGES_SDL2_IMAGE_H
#define RNJ_IMAGES_SDL2_IMAGE_H

#include "log.h"
#include "error.h"
#include "defines.h"

#include "SDL2/SDL.h"
#include "SDL2/SDL_surface.h"
#include "SDL2/SDL_image.h"

struct bitmap {
    int width;
    int height;
    int bpp;
    SDL_Surface* data;
} *Bitmap;

struct {
    int imagesCount;
} Images;

void ImagesInit(int);/* Инициализация */
void ImagesQuit(void); /* завершаем работу манеджера изображений */
int ImagesCreateBitmap(int, int, int); /* создание изображения */
void ImagesSaveBitmap(int, char *);
void ImagesSetPixel(int, int, int, int, int ,int, int);
void ImagesDestroyBitmap(int);
#endif


