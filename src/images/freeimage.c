#include "images/freeimage.h"

void ImagesInit(int images)
{
    LogWrite("Initializing Image Manager", 0, MT_INFO, NULL);
    Images.imagesCount = 0;
    #ifdef FREEIMAGE_LIB
    FreeImage_Initialise();
    #endif /* FREEIMAGE_LIB */
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
    Bitmap[Images.imagesCount - 1].data = FreeImage_Allocate(width, height,
                                                             bpp, 0, 0, 0);
    if (Bitmap[Images.imagesCount - 1].data)
        LogWrite("Bitmap created", 0, MT_INFO, NULL);
    else
        ErrorGive("Can not create new Bitmap", 0);
    return Images.imagesCount - 1;
}

void ImagesSetPixel(int bitmapNum, int x, int y, int r, int g, int b, int a)
{
    RGBQUAD color;
    color.rgbRed = r;
    color.rgbGreen = g;
    color.rgbBlue = b;
    color.rgbReserved = a;
    if (!FreeImage_SetPixelColor(Bitmap[bitmapNum].data, x, y, &color))
        LogWrite("Can not set pixel", 0, MT_WARNING, NULL);
}

void ImagesSaveBitmap(int bitmapNum, char *filename)
{
    if(!FreeImage_Save(FIF_PNG, Bitmap[bitmapNum].data, filename, PNG_Z_DEFAULT_COMPRESSION))
        ErrorGive("Can not save bitmap to file", 0);
    else
        LogWrite("Bitmap saved to file", 0, MT_INFO, NULL);
}

void ImagesDestroyBitmap(int num)
{
    FreeImage_Unload(Bitmap[num].data);
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

    #ifdef FREEIMAGE_LIB
    FreeImage_DeInitialise();
    #endif /* FREEIMAGE_LIB */
    LogWrite("Image Manager Destroyed", 0, MT_INFO, NULL);
}

