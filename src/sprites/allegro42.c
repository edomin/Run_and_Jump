#include "sprites/allegro42.h"

void SpritesInit(int sprites)
{
    LogWrite("Initializing Sprite Manager", 0, MT_INFO, NULL);
    /* устанавливаем количество загруженных спрайтов в 0 */
    Sprites.spritesCount = 0;
    Sprite = malloc(sizeof(struct sprite) * sprites);
    if (Sprite == NULL)
        ErrorGive("Can not allocate memory for Sprites", 1);
    LogWrite("Reporting loadpng for Allegro 4.2 library version:", 0, MT_INFO,
             LOADPNG_VERSIONSTR);
    register_png_datafile_object(DAT_ID('P','N','G',' '));
    register_png_file_type();
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
    Sprite[Sprites.spritesCount].name = malloc(sizeof(char) * (strlen(filename) + 1));
    Sprite[Sprites.spritesCount].name = strcpy(Sprite[Sprites.spritesCount].name,
                                               (const char *)filename);
    LogWrite("Creating sprite", 0, MT_INFO, Sprite[Sprites.spritesCount].name);
    /* Увеличиваем кол-во спрайтов на 1 */
    Sprites.spritesCount += 1;
    /* Текст спрайта (для текстовых спрайтов) */
    Sprite[Sprites.spritesCount - 1].text = NULL;
    /* Загружаем файл */
    /* обнуляем поверхность спрайта */
    Sprite[Sprites.spritesCount - 1].texture = NULL;
    Sprite[Sprites.spritesCount - 1].texture = load_bitmap((const char*)filename,
                                                           NULL);

    if (Sprite[Sprites.spritesCount - 1].texture != NULL)
        LogWrite("Image loaded", 1, MT_INFO, NULL);
    else
        ErrorGive("Can not load image", 1);

    Sprite[Sprites.spritesCount - 1].width = Sprite[Sprites.spritesCount - 1].texture->w;
    Sprite[Sprites.spritesCount - 1].height = Sprite[Sprites.spritesCount - 1].texture->h;

    /* устанавливаем число кадров для спрайта */
    Sprite[Sprites.spritesCount - 1].clip = malloc(sizeof(Rect) * clips);
    /* разбиваем спрайтшит на кадры */
    for (i = 0; i <= clips - 1; i++)
    {
        Sprite[Sprites.spritesCount - 1].clip[i].x = i * Sprite[Sprites.spritesCount - 1].width / clips;
        Sprite[Sprites.spritesCount - 1].clip[i].y = 0;
        Sprite[Sprites.spritesCount - 1].clip[i].w = Sprite[Sprites.spritesCount - 1].width / clips;
        Sprite[Sprites.spritesCount - 1].clip[i].h = Sprite[Sprites.spritesCount - 1].height;
    }
    Sprite[Sprites.spritesCount - 1].clipsCount = clips;
    LogWrite("Sprite Created", 0, MT_INFO, NULL);
    return Sprites.spritesCount - 1;
}

int SpritesCreateText(char *text, int fontnum, int text_r, int text_g,
                      int text_b, int wrapLength)
{
    Sprite[Sprites.spritesCount].name = malloc(sizeof(char) * (strlen(text) + 1));
    Sprite[Sprites.spritesCount].name = strcpy(Sprite[Sprites.spritesCount].name,
                                               (const char *)text);
    LogWrite("Dummying text sprite", 0, MT_INFO,
             Sprite[Sprites.spritesCount].name);

    Sprites.spritesCount += 1; /* Увеличиваем кол-во спрайтов на 1 */

    Sprite[Sprites.spritesCount - 1].text = text;
    Sprite[Sprites.spritesCount - 1].fontNum = fontnum;
    Sprite[Sprites.spritesCount - 1].textR = text_r;
    Sprite[Sprites.spritesCount - 1].textG = text_g;
    Sprite[Sprites.spritesCount - 1].textB = text_b;
    Sprite[Sprites.spritesCount - 1].wrapLength = wrapLength;

    #if defined(LFONTS_ALLEGRO42_FONT)
    Sprite[Sprites.spritesCount - 1].width = alfont_text_length(Fonts.font[fontnum],
                                                                (const char *)Sprite[Sprites.spritesCount - 1].text);
    Sprite[Sprites.spritesCount - 1].height = alfont_get_font_height(Fonts.font[fontnum]);
    #else
    Sprite[Sprites.spritesCount - 1].width = gk_text_width_utf8 (Fonts.font[fontnum].rend,
                                                                 Sprite[Sprites.spritesCount - 1].text);
    Sprite[Sprites.spritesCount - 1].height = gk_text_height_utf8 (Fonts.font[fontnum].rend,
                                                                   Sprite[Sprites.spritesCount - 1].text);
    #endif
    /* обнуляем поверхность спрайта */
    Sprite[Sprites.spritesCount - 1].texture = NULL;

    /* устанавливаем число кадров для спрайта - для текста 1 кадр */
    Sprite[Sprites.spritesCount - 1].clip = malloc(sizeof(Rect) * 1);
    /* разбиваем спрайтшит на кадры */
    Sprite[Sprites.spritesCount - 1].clip[0].x = 0;
    Sprite[Sprites.spritesCount - 1].clip[0].y = 0;
    Sprite[Sprites.spritesCount - 1].clip[0].w = Sprite[Sprites.spritesCount - 1].width;
    Sprite[Sprites.spritesCount - 1].clip[0].h = Sprite[Sprites.spritesCount - 1].height;

    Sprite[Sprites.spritesCount - 1].clipsCount = 1;

    LogWrite("Text sprite dummied", 0, MT_INFO, NULL);

    return Sprites.spritesCount - 1;
}

void SpritesChangeText(int num, char *text, int fontnum, int text_r, int text_g, int text_b, int wrapLength)
{
    Sprite[num].text = text;
    Sprite[num].fontNum = fontnum;
    Sprite[num].textR = text_r;
    Sprite[num].textG = text_g;
    Sprite[num].textB = text_b;
    Sprite[num].wrapLength = wrapLength;

    #if defined(LFONTS_ALLEGRO42_FONT)
    Sprite[num].width = alfont_text_length(Fonts.font[fontnum],
                                           (const char *)Sprite[num].text);
    Sprite[num].height = alfont_get_font_height(Fonts.font[fontnum]);
    #else
    Sprite[num].width = gk_text_width_utf8(Fonts.font[fontnum].rend,
                                           Sprite[num].text);
    Sprite[num].height = gk_text_height_utf8(Fonts.font[fontnum].rend,
                                             Sprite[num].text);
    #endif
    /* обнуляем поверхность спрайта */
    Sprite[num].texture = NULL;
    /* разбиваем спрайтшит на кадры */
    Sprite[num].clip[0].x = 0;
    Sprite[num].clip[0].y = 0;
    Sprite[num].clip[0].w = Sprite[num].width;
    Sprite[num].clip[0].h = Sprite[num].height;

    Sprite[num].clipsCount = 1;
}

void SpritesBlitSprite(int num, int clip, int x, int y, int width, int height,
                       int centerX, int centerY, double angle, int a, int flip)
{
    if (Sprite[num].text == NULL)
    {
        if (Sprite[num].texture != NULL)
        {
            set_clip_rect(
              Draw.renderer,
              x,
              y,
              x + Sprite[num].clip[clip].w,
              y + Sprite[num].clip[clip].h
            );
            set_alpha_blender();
            draw_trans_sprite(Draw.renderer, Sprite[num].texture,
                              x - Sprite[num].clip[clip].x,
                              y - Sprite[num].clip[clip].y);
            set_clip_rect(
              Draw.renderer,
              0,
              0,
              Draw.renderer->w,
              Draw.renderer->h
            );
        }
    }
    else
    {
        #if defined(LFONTS_ALLEGRO42_FONT)
        set_alpha_blender();
        alfont_textout(
          Draw.renderer,
          Fonts.font[Sprite[num].fontNum],
          Sprite[num].text,
          x,
          y,
          makecol(Sprite[num].textR, Sprite[num].textG, Sprite[num].textB)
        );
        #else
        gk_rend_set_text_color_rgb(Fonts.font[Sprite[num].fontNum].rend,
                                   Sprite[num].textR, Sprite[num].textG,
                                   Sprite[num].textB);
        gk_render_line_utf8(Draw.renderer, Fonts.font[Sprite[num].fontNum].rend,
                            Sprite[num].text, x, y);
        #endif
    }
}

void SpritesDestroySprite(int num)
{
    if (Sprite[num].texture != NULL)
    {
        destroy_bitmap(Sprite[num].texture);
    }
    if (Sprite[num].name != NULL)
    {
        free(Sprite[num].name);
    }
    free(Sprite[num].clip);
}


