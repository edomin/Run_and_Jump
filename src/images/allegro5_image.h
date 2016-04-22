#ifndef RNJ_IMAGES_ALLEGRO5_IMAGE_H
#define RNJ_IMAGES_ALLEGRO5_IMAGE_H

#include "log.h"
#include "error.h"
#include "defines.h"

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"

struct bitmap {
    int width;
    int height;
    int bpp;
    ALLEGRO_BITMAP *data;
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



