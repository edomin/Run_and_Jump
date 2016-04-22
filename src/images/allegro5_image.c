#include "images/allegro5_image.h"

void ImagesInit(int images)
{
    LogWrite("Initializing Image Manager", 0, MT_INFO, NULL);
    Images.imagesCount = 0;

	/* Выделяем память для изображений */
    Bitmap = malloc(sizeof(struct bitmap) * images);
    if (Bitmap == NULL)
    {
        ErrorGive("Can not allocate memory for Bitmaps", 1);
    }
    LogWrite("Image Manager Initialized", 0, MT_INFO, NULL);
}

int ImagesCreateBitmap(int width, int height, int bpp)
{
    int bitmapFormat;
    LogWrite("Creating bitmap", 0, MT_INFO, NULL);
    Images.imagesCount += 1;

	/* Запоминаем текущий формат пикселя */
    bitmapFormat = al_get_new_bitmap_format();
    /* Выбираем формат для создаваемого изображения */
    if (bpp == 32)
    {
    	al_set_new_bitmap_format(ALLEGRO_PIXEL_FORMAT_ANY_32_WITH_ALPHA);
    }

    Bitmap[Images.imagesCount - 1].width = width;
    Bitmap[Images.imagesCount - 1].height = height;
    Bitmap[Images.imagesCount - 1].bpp = bpp;
    /* Создаем изображение */
    Bitmap[Images.imagesCount - 1].data = al_create_bitmap(width, height);
    if (Bitmap[Images.imagesCount - 1].data != NULL)
        LogWrite("Bitmap created", 0, MT_INFO, NULL);
    else
        ErrorGive("Can not create new Bitmap", 0);

	/* Возвращаем на место старый формат */
	al_set_new_bitmap_format(bitmapFormat);

    return Images.imagesCount - 1;
}

void ImagesSetPixel(int bitmapNum, int x, int y, int r, int g, int b, int a)
{
	//al_lock_bitmap(Bitmap[bitmapNum].data, ALLEGRO_PIXEL_FORMAT_ANY, 0);

	al_set_target_bitmap(Bitmap[bitmapNum].data);

	al_draw_pixel(x, Bitmap[bitmapNum].height - y, al_map_rgba(r * a / 255, g * a / 255, b * a / 255, 255 * a / 255));

	al_set_target_backbuffer(al_get_current_display());

	//al_unlock_bitmap(Bitmap[bitmapNum].data);
}

void ImagesSaveBitmap(int bitmapNum, char *filename)
{
	al_save_bitmap((const char *)filename, Bitmap[bitmapNum].data);
}

void ImagesDestroyBitmap(int num)
{
    al_destroy_bitmap(Bitmap[num].data);
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
