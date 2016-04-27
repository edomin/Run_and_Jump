#include "fonts/sdl2_ttf.h"

bool FontsInit(int fonts)
{
    SDL_version ctVersion;
    const SDL_version *dllVersion;

    LogWrite("Initializing Font Manager", 0, MT_INFO, NULL);

    SDL_TTF_VERSION(&ctVersion);
    LogWrite("Checking SDL_ttf compile-time version", 1, MT_INFO, NULL);
    LogWrite2("Major:", 2, MT_INFO, ctVersion.major);
    LogWrite2("Minor:", 2, MT_INFO, ctVersion.minor);
    LogWrite2("Patch:", 2, MT_INFO, ctVersion.patch);

    dllVersion = TTF_Linked_Version();
    LogWrite("Checking SDL_ttf dll version", 1, MT_INFO, NULL);
    LogWrite2("Major:", 2, MT_INFO, dllVersion->major);
    LogWrite2("Minor:", 2, MT_INFO, dllVersion->minor);
    LogWrite2("Patch:", 2, MT_INFO, dllVersion->patch);

    Fonts.fontsCount = 0; /* устанавливаем количество загруженных шрифтов в 0 */

    Fonts.font = malloc(sizeof(TTF_Font *) * fonts);
    if (Fonts.font == NULL)
        ErrorGive("Can not allocate memory for Fonts", 1);
    Fonts.name = malloc(sizeof(char *) * fonts);

    if(TTF_Init() == TTF_INIT_ERROR)
    {
        ErrorGive("Can not initialize true type font API", 1);
        return false;
    }
    LogWrite("True type font API initialized", 1, MT_INFO, NULL);
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

    Fonts.font[Fonts.fontsCount - 1] = TTF_OpenFont(filename, size);
    LogWrite("Font loaded", 0, MT_INFO, NULL);
    return Fonts.fontsCount - 1;
}

void FontsDestroyFont(int num)
{
    TTF_CloseFont( Fonts.font[num] );
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
    TTF_Quit();
    LogWrite("TTF engine deinitialized", 1, MT_INFO, NULL);
    LogWrite("Font Manager destroyed", 0, MT_INFO, NULL);
}

