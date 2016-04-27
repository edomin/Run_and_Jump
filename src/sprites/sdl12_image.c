#include "sprites/sdl12_image.h"

void SpritesInit(int sprites)
{
    SDL_version ctVersion;
    const SDL_version *dllVersion;

    LogWrite("Initializing Sprite Manager", 0, MT_INFO, NULL);

    #ifndef CC_KOS
    SDL_IMAGE_VERSION(&ctVersion);
    LogWrite("Checking SDL_image compile-time version", 1, MT_INFO, NULL);
    LogWrite2("Major:", 2, MT_INFO, ctVersion.major);
    LogWrite2("Minor:", 2, MT_INFO, ctVersion.minor);
    LogWrite2("Patch:", 2, MT_INFO, ctVersion.patch);

    dllVersion = IMG_Linked_Version();
    LogWrite("Checking SDL_image linked version", 1, MT_INFO, NULL);
    LogWrite2("Major:", 2, MT_INFO, dllVersion->major);
    LogWrite2("Minor:", 2, MT_INFO, dllVersion->minor);
    LogWrite2("Patch:", 2, MT_INFO, dllVersion->patch);
    #endif

    /* устанавливаем количество загруженных спрайтов в 0 */
    Sprites.spritesCount = 0;
    Sprite = malloc(sizeof(struct sprite) * sprites);
    if (Sprite == NULL)
        ErrorGive("Can not allocate memory for Sprites", 1);
    LogWrite("Sprite Manager initialized", 0, MT_INFO, NULL);
}

void SpritesQuit(void)
{
    int i;
    LogWrite("Destroying Sprite Manager.", 0, MT_INFO, NULL);
    for (i = 0; i < Sprites.spritesCount; i++)
    {
        LogWrite("Destroying sprite", 1, MT_INFO, Sprite[i].name);
        SpritesDestroySprite(i);
    }
    free(Sprite);
    LogWrite("Sprite Manager Destroyed.", 0, MT_INFO, NULL);
}

int SpritesCreateSprite(char *filename, int clips)
{
    int i;
    int w;
    int h;
    Sprite[Sprites.spritesCount].name = malloc(sizeof(char) * (strlen(filename) + 1));
    Sprite[Sprites.spritesCount].name = strcpy(Sprite[Sprites.spritesCount].name,
                                               (const char *)filename);
    LogWrite("Creating sprite", 0, MT_INFO, Sprite[Sprites.spritesCount].name);
    /* Увеличиваем кол-во спрайтов на 1 */
    Sprites.spritesCount += 1;
    /* Загружаем файл */
    Sprites.loadedImage = NULL;/* обнуляем временную поверхность */
    /* грузим картинку из файла во временную поверхность */
    Sprites.loadedImage = IMG_Load(filename);

    if (Sprites.loadedImage != NULL)
        LogWrite("Image loaded", 1, MT_INFO, NULL);
    else
        ErrorGive("Can not load image", 1);

    w = Sprites.loadedImage->w;
    h = Sprites.loadedImage->h;

    Sprite[Sprites.spritesCount - 1].width = w;
    Sprite[Sprites.spritesCount - 1].height = h;
    /* обнуляем поверхность спрайта */
    Sprites.tempImage = SDL_CreateRGBSurface(SDL_SWSURFACE, w, h, 32,
                                             0x00FF0000, 0x0000FF00, 0x000000FF,
                                             0xFF000000);
    Sprite[Sprites.spritesCount - 1].texture = SDL_ConvertSurface(Sprites.loadedImage, Sprites.tempImage->format, 0);
    SDL_FreeSurface(Sprites.loadedImage);/* освобождаем временную поверхность */
    SDL_FreeSurface(Sprites.tempImage); /* освобождаем временную поверхность */

//    Sprite[Sprites.spritesCount - 1].texture = SDL_DisplayFormat(Sprites.loadedImage);

    if (Sprite[Sprites.spritesCount - 1].texture != NULL)
        LogWrite("Texture created", 1, MT_INFO, NULL);
    else
        ErrorGive("Can not create texture", 1);

    /* устанавливаем число кадров для спрайта */
    Sprite[Sprites.spritesCount - 1].clip = malloc(sizeof(SDL_Rect) * clips);
    /* разбиваем спрайтшит на кадры */
    for (i = 0; i <= clips - 1; i++)
    {
        Sprite[Sprites.spritesCount - 1].clip[i].x = i * w / clips;
        Sprite[Sprites.spritesCount - 1].clip[i].y = 0;
        Sprite[Sprites.spritesCount - 1].clip[i].w = w / clips;
        Sprite[Sprites.spritesCount - 1].clip[i].h = h;
    }
    Sprite[Sprites.spritesCount - 1].clipsCount = clips;
    LogWrite("Sprite Created", 0, MT_INFO, NULL);
    return Sprites.spritesCount - 1;
}

int SpritesCreateText(char *text, int fontnum, int text_r, int text_g,
                      int text_b, int wrapLength)
{
    SDL_Color textcolor;
    int w;
    int h;
    Sprite[Sprites.spritesCount].name = malloc(sizeof(char) * (strlen(text) + 1));
    Sprite[Sprites.spritesCount].name = strcpy(Sprite[Sprites.spritesCount].name,
                                               (const char *)text);
    LogWrite("Creating text sprite", 0, MT_INFO,
             Sprite[Sprites.spritesCount].name);

    Sprites.spritesCount += 1; /* Увеличиваем кол-во спрайтов на 1 */

    #ifndef LFONTS_DUMMY
    Sprites.loadedImage = NULL;

    /* Переводим текст на поверхность спрайта */
    textcolor.r = text_r;
    textcolor.g = text_g;
    textcolor.b = text_b;
    textcolor.unused = 255;

//    if (wrapLength <= WRAP_NOWRAP)
        Sprites.loadedImage = TTF_RenderUTF8_Blended(Fonts.font[fontnum], text,
                                                     textcolor);
//    else
//        Sprites.loadedImage = TTF_RenderUTF8_Blended_Wrapped(Fonts.font[fontnum], text, textcolor, wrapLength);

    if (Sprites.loadedImage != NULL)
        LogWrite("Text surface created", 1, MT_INFO, NULL);
    else
        ErrorGive("Can not create text surface", 1);

    w = Sprites.loadedImage->w;
    h = Sprites.loadedImage->h;

    Sprite[Sprites.spritesCount - 1].width = w;
    Sprite[Sprites.spritesCount - 1].height = h;

    /* обнуляем поверхность спрайта */
    Sprite[Sprites.spritesCount - 1].texture = NULL;
    Sprite[Sprites.spritesCount - 1].texture = Sprites.loadedImage;

    Sprites.loadedImage = NULL;

    if (Sprite[Sprites.spritesCount-1].texture != NULL)
        LogWrite("Text texture created", 1, MT_INFO, NULL);
    else
        ErrorGive("Can not create text texture", 1);

    SDL_FreeSurface(Sprites.loadedImage);/* освобождаем временную поверхность */

    /* устанавливаем число кадров для спрайта - для текста 1 кадр */
    Sprite[Sprites.spritesCount - 1].clip = malloc(sizeof(SDL_Rect) * 1);
    /* разбиваем спрайтшит на кадры */

    Sprite[Sprites.spritesCount - 1].clip[0].x = 0;
    Sprite[Sprites.spritesCount - 1].clip[0].y = 0;
    Sprite[Sprites.spritesCount - 1].clip[0].w = w;
    Sprite[Sprites.spritesCount - 1].clip[0].h = h;

    Sprite[Sprites.spritesCount - 1].clipsCount = 1;

    #endif

    LogWrite("Text sprite created", 0, MT_INFO, NULL);

    return Sprites.spritesCount - 1;
}

void SpritesChangeText(int num, char *text, int fontnum, int text_r, int text_g,
                       int text_b, int wrapLength)
{
    #ifndef LFONTS_DUMMY
    SDL_Color textcolor;
    int w;
    int h;
    textcolor.r = text_r;
    textcolor.g = text_g;
    textcolor.b = text_b;
    textcolor.unused = 255;

//    if (wrapLength <= WRAP_NOWRAP)
//    {
        Sprites.loadedImage = TTF_RenderUTF8_Blended(Fonts.font[fontnum], text,
                                                     textcolor);
//    }
//    else
//    {
//        Sprites.loadedImage = TTF_RenderUTF8_Blended_Wrapped(Fonts.font[fontnum], text, textcolor, wrapLength);
//    }

    w = Sprites.loadedImage->w;
    h = Sprites.loadedImage->h;

    Sprite[num].width = w;
    Sprite[num].height = h;

    SDL_FreeSurface(Sprite[num].texture);
    Sprite[num].texture = NULL;/* обнуляем поверхность спрайта */
    Sprite[num].texture = Sprites.loadedImage;

    Sprites.loadedImage = NULL;

    /* устанавливаем число кадров для спрайта - для текста 1 кадр */
    /* Уже установлено */
    /* разбиваем спрайтшит на кадры */

    Sprite[num].clip[0].x = 0;
    Sprite[num].clip[0].y = 0;
    Sprite[num].clip[0].w = w;
    Sprite[num].clip[0].h = h;

    Sprite[num].clipsCount = 1;
    #endif
}

void SpritesBlitSprite(int num, int clip, int x, int y, int width, int height,
                       int centerX, int centerY, double angle, int a, int flip)
{
    /* сдвиг спрайта */
    SDL_Rect offset;
//    SDL_Point point;

    /* Get offsets */
    offset.x = x;
    offset.y = y;
    offset.w = width;
    offset.h = height;

//    SDL_SetTextureAlphaMod(Sprite[num].texture, a);

//    if(angle == 0.0)
//    {
//        SDL_RenderCopy(Draw.renderer, Sprite[num].texture, &Sprite[num].clip[clip], &offset);
//    }
//    else
//    {
//        point.x = centerX;
//        point.y = centerY;
//        SDL_RenderCopyEx(Draw.renderer, Sprite[num].texture, &Sprite[num].clip[clip], &offset, -angle, &point, flip);
//    }
    SDL_BlitSurface(Sprite[num].texture, &Sprite[num].clip[clip], Draw.renderer,
                    &offset);
}

void SpritesDestroySprite(int num)
{
    SDL_FreeSurface(Sprite[num].texture);
    if (Sprite[num].name != NULL)
    {
        free(Sprite[num].name);
    }
    free(Sprite[num].clip);
}

