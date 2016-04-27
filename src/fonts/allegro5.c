#include "fonts/allegro5.h"

bool FontsInit(int fonts)
{
    uint32_t version;
    LogWrite("Initializing Font Manager", 0, MT_INFO, NULL);
    Fonts.fontsCount = 0; /* устанавливаем количество загруженных шрифтов в 0 */

    Fonts.font = malloc(sizeof(ALLEGRO_FONT *) * fonts);
    if (Fonts.font == NULL)
        ErrorGive("Can not allocate memory for Fonts", 1);
    Fonts.name = malloc(sizeof(char *) * fonts);

    al_init_font_addon();
    LogWrite("Allegro Font addon initialized", 1, MT_INFO, NULL);

    version = al_get_allegro_font_version();
    LogWrite("Checking Allegro Font Addon compile-time version", 1,
             MT_INFO, NULL);
    LogWrite2("Major:", 2, MT_INFO, version >> 24);
    LogWrite2("Minor:", 2, MT_INFO, (version >> 16) & 255);
    LogWrite2("Revision:", 2, MT_INFO, (version >> 8) & 255);
    LogWrite2("Release:", 2, MT_INFO, version & 255);

    if (al_init_ttf_addon())
    {
        LogWrite("Allegro TTF addon initialized", 1, MT_INFO, NULL);
    }
    else
    {
        ErrorGive("Can not initialize TTF addon", 1);
    }

    version = al_get_allegro_ttf_version();
    LogWrite("Checking Allegro TTF Addon compile-time version", 1, MT_INFO,
             NULL);
    LogWrite2("Major:", 2, MT_INFO, version >> 24);
    LogWrite2("Minor:", 2, MT_INFO, (version >> 16) & 255);
    LogWrite2("Revision:", 2, MT_INFO, (version >> 8) & 255);
    LogWrite2("Release:", 2, MT_INFO, version & 255);

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

    Fonts.font[Fonts.fontsCount - 1] = al_load_font(filename, size, 0);
    LogWrite("Font loaded", 0, MT_INFO, NULL);
    return Fonts.fontsCount - 1;
}

void FontsDestroyFont(int num)
{
    al_destroy_font(Fonts.font[num]);
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
    al_shutdown_ttf_addon();
    LogWrite("Allegro TTF addon deinitialized", 1, MT_INFO, NULL);
    al_shutdown_font_addon();
    LogWrite("Allegro Font addon deinitialized", 1, MT_INFO, NULL);
    LogWrite("Font Manager destroyed", 0, MT_INFO, NULL);
}

