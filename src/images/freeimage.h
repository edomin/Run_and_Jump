#ifndef RNJ_IMAGES_FREEIMAGE_H
#define RNJ_IMAGES_FREEIMAGE_H

#include "log.h"
#include "error.h"
#include "defines.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include <FreeImage.h>

struct bitmap {
    int width;
    int height;
    int bpp;
    FIBITMAP* data;
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

