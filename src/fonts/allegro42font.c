#include "fonts/allegro42font.h"

bool FontsInit(int fonts)
{
    LogWrite("Initializing Font Manager", 0, MT_INFO, NULL);
    Fonts.fontsCount = 0; /* устанавливаем количество загруженных шрифтов в 0 */

    Fonts.font = malloc(sizeof(ALFONT_FONT *) * fonts);
    if (Fonts.font == NULL)
        ErrorGive("Can not allocate memory for Fonts", 1);
    Fonts.name = malloc(sizeof(char *) * fonts);

    LogWrite("Reporting Allegro Font version", 1, MT_INFO, ALFONT_VERSION_STR);

    if (alfont_init() == ALFONT_OK)
        LogWrite("AllegroFont initialized", 1, MT_INFO, NULL);
    else
        ErrorGive("Unable initialize AllegroFont", 1);

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
    Fonts.font[Fonts.fontsCount - 1] = NULL;/* обнуляем указатель на шрифт */

    Fonts.font[Fonts.fontsCount - 1] = alfont_load_font((const char *)filename);
    if (Fonts.font[Fonts.fontsCount - 1] != NULL)
        LogWrite("Font loaded", 0, MT_INFO, NULL);
    else
        ErrorGive("Unable to load font", 1);

    alfont_set_language(Fonts.font[Fonts.fontsCount - 1], "english");
    alfont_set_convert(Fonts.font[Fonts.fontsCount - 1], TYPE_WIDECHAR);
    alfont_set_char_extra_spacing(Fonts.font[Fonts.fontsCount - 1], 0);
    alfont_text_mode(-1); /* Не знаю, зачем эта строчка */
    alfont_set_font_background(Fonts.font[Fonts.fontsCount - 1], FALSE);
    if (alfont_set_font_size(Fonts.font[Fonts.fontsCount - 1], size) == ALFONT_OK)
        LogWrite("Font size set", 0, MT_INFO, NULL);
    else
        LogWrite("Unable to set font size", 0, MT_WARNING, NULL);

    return Fonts.fontsCount - 1;
}

void FontsDestroyFont(int num)
{
    alfont_destroy_font(Fonts.font[num]);
    free(Fonts.name[num]);
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
    alfont_exit();
    LogWrite("Font Manager destroyed", 0, MT_INFO, NULL);
}
