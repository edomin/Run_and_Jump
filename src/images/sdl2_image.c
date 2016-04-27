#include "images/sdl2_image.h"

void ImagesInit(int images)
{
    LogWrite("Initializing Image Manager", 0, MT_INFO, NULL);
    Images.imagesCount = 0;

    Bitmap = malloc(sizeof(struct bitmap) * images);
    if (Bitmap == NULL)
    {
        ErrorGive("Can not allocate memory for Bitmaps", 1);
    }
    LogWrite("Image Manager Initialized", 0, MT_INFO, NULL);
}

int ImagesCreateBitmap(int width, int height, int bpp)
{
    LogWrite("Creating bitmap", 0, MT_INFO, NULL);
    Images.imagesCount += 1;
    Bitmap[Images.imagesCount - 1].width = width;
    Bitmap[Images.imagesCount - 1].height = height;
    Bitmap[Images.imagesCount - 1].bpp = bpp;
    Bitmap[Images.imagesCount - 1].data = SDL_CreateRGBSurface(0, width, height,
                                                               bpp, 0, 0, 0, 0);
    if (Bitmap[Images.imagesCount - 1].data != NULL)
        LogWrite("Bitmap created", 0, MT_INFO, NULL);
    else
        ErrorGive("Can not create new Bitmap", 0);
    return Images.imagesCount - 1;
}

void ImagesSetPixel(int bitmapNum, int x, int y, int r, int g, int b, int a)
{
    Uint32 *pixels;
    Uint32 pixel;

    //If the surface must be locked
    if(SDL_MUSTLOCK(Bitmap[bitmapNum].data))
    {
        //Lock the surface
        SDL_LockSurface(Bitmap[bitmapNum].data);
    }

    pixel = (Uint8)b + ((Uint8)g << 8) + ((Uint8)r << 16) + ((Uint8)a << 24);

    pixels = (Uint32 *)Bitmap[bitmapNum].data->pixels;
    pixels[((Bitmap[bitmapNum].data->h - y) * Bitmap[bitmapNum].data->w) + x] = pixel;

    if(SDL_MUSTLOCK(Bitmap[bitmapNum].data))
    {
        //Lock the surface
        SDL_UnlockSurface(Bitmap[bitmapNum].data);
    }
}

void ImagesSaveBitmap(int bitmapNum, char *filename)
{
    IMG_SavePNG(Bitmap[bitmapNum].data, (const char *)filename);
}

void ImagesDestroyBitmap(int num)
{
    SDL_FreeSurface(Bitmap[num].data);
    LogWrite("Bitmap unloaded", 0, MT_INFO, NULL);
}

void ImagesQuit()
{
    int i;
    LogWrite("Destroying Image Manager", 0, MT_INFO, NULL);
    for (i = 0; i < Images.imagesCount; i++)
    {
        LogWrite("Destroying bitmap", 1, MT_INFO, NULL);
        ImagesDestroyBitmap(i);
    }
    free(Bitmap);
    LogWrite("Image Manager Destroyed", 0, MT_INFO, NULL);
}


