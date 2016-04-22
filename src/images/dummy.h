#ifndef RNJ_IMAGES_DUMMY_H
#define RNJ_IMAGES_DUMMY_H

#include "log.h"
#include "error.h"
#include "defines.h"

struct bitmap {
    int width;
    int height;
    int bpp;
    //ALLEGRO_BITMAP *data;
} *Bitmap;

struct {
    int imagesCount;
} Images;

void ImagesInit(int);/* ������������� */
void ImagesQuit(void); /* ��������� ������ ��������� ����������� */
int ImagesCreateBitmap(int, int, int); /* �������� ����������� */
void ImagesSaveBitmap(int, char *);
void ImagesSetPixel(int, int, int, int, int ,int, int);
void ImagesDestroyBitmap(int);
#endif




