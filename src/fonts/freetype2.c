#include "fonts/freetype2.h"

bool FontsInit(int fonts)
{
    LogWrite("Initializing Font Manager", 0, MT_INFO, NULL);
    Fonts.fontsCount = 0; /* устанавливаем количество загруженных шрифтов в 0 */

    Fonts.font = malloc(sizeof(TTF_Font *) * fonts);
    if (Fonts.font == NULL)
         ErrorGive("Can not allocate memory for Fonts", 1);
    Fonts.name = malloc(sizeof(char *) * fonts);
    if (Fonts.name == NULL)
         ErrorGive("Can not allocate memory for Font names", 1);

    LogWrite("Font Manager initialized", 0, MT_INFO, NULL);
    return true;
}

int FontsLoadFont(char *filename, int size)
{
    FT_Error error;
    GLuint cellW;
    GLuint cellH;
    int maxBearing;
    int minHang;

    error = NULL;
    error = FT_Init_FreeType(&Fonts.library);
    if (error)
    {
        //FreeType error:%X", error
    }

    Fonts.name[Fonts.fontsCount] = malloc(sizeof(char) * (strlen(filename) + 1));
    Fonts.name[Fonts.fontsCount] = strcpy(Fonts.name[Fonts.fontsCount], (const char *)filename);
    Fonts.fontsCount += 1; /* Увеличиваем кол-во шрифтов на 1 */

    Fonts.font[Fonts.fontsCount - 1].face = NULL;
    error = FT_New_Face(Fonts.library, filename, 0, &Fonts.font[Fonts.fontsCount - 1].face);
    if (error == FT_Err_Unknown_File_Format)
    {
        //the font file could be opened and read, but it appears
        //that its font format is unsupported
    }
    else if (error)
    {
        //another error code means that the font file could not
        //be opened or read, or that it is broken...
    }

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

