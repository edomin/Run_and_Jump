#include "fonts/glyph_keeper.h"

bool FontsInit(int fonts)
{
    LogWrite("Initializing Font Manager", 0, MT_INFO, NULL);
    Fonts.fontsCount = 0; /* устанавливаем количество загруженных шрифтов в 0 */

    Fonts.font = malloc(sizeof(Font) * fonts);
    if (Fonts.font == NULL)
        ErrorGive("Can not allocate memory for Fonts", 1);
    Fonts.name = malloc(sizeof(char *) * fonts);

    LogWrite("Reporting Glyph Keeper version", 1, MT_INFO, GK_VERSION_STR);

    gk_set_font_path("./");

    LogWrite("Font Manager initialized", 0, MT_INFO, NULL);
    return true;
}

int FontsLoadFont(char *filename, int size)
{
    Fonts.name[Fonts.fontsCount] = malloc(sizeof(char) * (strlen(filename) + 1));
    Fonts.name[Fonts.fontsCount] = strcpy(Fonts.name[Fonts.fontsCount],
                                          (const char *)filename);
    Fonts.fontsCount += 1; /* Увеличиваем кол-во шрифтов на 1 */
    /* Загружаем файл */
    LogWrite("Loading font", 0, MT_INFO, Fonts.name[Fonts.fontsCount - 1]);
    Fonts.font[Fonts.fontsCount - 1].face = gk_load_face_from_file(filename, 0);
    if (!Fonts.font[Fonts.fontsCount - 1].face != 0)
        LogWrite("Font loaded", 1, MT_INFO, NULL);
    else
        ErrorGive("Unable to load font", 1);

    LogWrite("Creating renderer object for font", 0, MT_INFO, NULL);
    Fonts.font[Fonts.fontsCount - 1].rend = gk_create_renderer(Fonts.font[Fonts.fontsCount - 1].face, 0);
    if (!Fonts.font[Fonts.fontsCount - 1].rend != 0)
        LogWrite("Renderer object created", 1, MT_INFO, NULL);
    else
        ErrorGive("Unable to create font renderer object", 1);

    gk_rend_set_hinting_off(Fonts.font[Fonts.fontsCount - 1].rend); /* Установка режима хинтинга */

    LogWrite("Setting pixel sizes for font", 0, MT_INFO, Fonts.name[Fonts.fontsCount - 1]);
    if (gk_rend_set_size_pixels(Fonts.font[Fonts.fontsCount - 1].rend, size, size) == 1)
        LogWrite("Pixel sizes for font set", 1, MT_INFO, NULL);
    else
        ErrorGive("Unable to set pixel sizes for font", 1);

    return Fonts.fontsCount - 1;
}

void FontsDestroyFont(int num)
{
    ;
}

void FontsQuit(void)
{
    int i;
    LogWrite("Destroying Font Manager", 0, MT_INFO, NULL);
    for (i = 0; i < Fonts.fontsCount; i++)
    {
        LogWrite("Destroying Font", 1, MT_INFO, Fonts.name[i]);
        FontsDestroyFont(i);
    }
    free(Fonts.font);
    LogWrite("Font Manager destroyed", 0, MT_INFO, NULL);
}
