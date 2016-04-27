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

    Sprite[Sprites.spritesCount - 1].width =  alfont_text_length(Fonts.font[fontnum],
                                                                 (const char *)Sprite[Sprites.spritesCount - 1].text);
    Sprite[Sprites.spritesCount - 1].height = alfont_get_font_height(Fonts.font[fontnum]);
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

    Sprite[num].width =  alfont_text_length(Fonts.font[fontnum],
                                            (const char *)Sprite[Sprites.spritesCount - 1].text);
    Sprite[num].height = alfont_get_font_height(Fonts.font[fontnum]);
    /* обнуляем поверхность спрайта */
    Sprite[num].texture = NULL;
    /* разбиваем спрайтшит на кадры */
    Sprite[num].clip[0].x = 0;
    Sprite[num].clip[0].y = 0;
    Sprite[num].clip[0].w = Sprite[Sprites.spritesCount - 1].width;
    Sprite[num].clip[0].h = Sprite[Sprites.spritesCount - 1].height;

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
              Sprite[num].texture,
              Sprite[num].clip[clip].x,
              Sprite[num].clip[clip].y,
              Sprite[num].clip[clip].x + Sprite[num].clip[clip].w,
              Sprite[num].clip[clip].y + Sprite[num].clip[clip].w
            );
            if ((width == Sprite[num].width) && (height == Sprite[num].height) && (angle == 0) && (flip == DRAW_FLIP_NONE))
            {
                set_alpha_blender();
                draw_trans_sprite(Draw.renderer, Sprite[num].texture, x, y);
            }
            else
            {
                set_trans_blender(0xFF, 0xFF, 0xFF, 255);
                switch (flip)
                {
                    case DRAW_FLIP_HORIZONTAL:
                        pivot_scaled_sprite_v_flip(Draw.renderer,
                                                   Sprite[num].texture, x, y,
                                                   centerX, centerY,
                                                   ftofix(128 - angle * 0.711111),
                                                   ftofix(width / Sprite[Sprites.spritesCount - 1].width));
                        break;
                    case DRAW_FLIP_VERTICAL:
                        pivot_scaled_sprite_v_flip(Draw.renderer,
                                                   Sprite[num].texture, x, y,
                                                   centerX, centerY,
                                                   ftofix(0 - angle * 0.711111),
                                                   ftofix(width / Sprite[Sprites.spritesCount - 1].width));
                        break;
                    case DRAW_FLIP_BOTH:
                        pivot_scaled_sprite(Draw.renderer, Sprite[num].texture,
                                            x, y, centerX, centerY,
                                            ftofix(128 - angle * 0.711111),
                                            ftofix(width / Sprite[Sprites.spritesCount - 1].width));
                        break;
                    default:
                        pivot_scaled_sprite(Draw.renderer, Sprite[num].texture,
                                            x, y, centerX, centerY,
                                            ftofix(0 - angle * 0.711111),
                                            ftofix(width / Sprite[Sprites.spritesCount - 1].width));
                        break;
                }
            }
        }
    }
    else
    {
        set_alpha_blender();
        alfont_textout(
          Draw.renderer,
          Fonts.font[Sprite[num].fontNum],
          Sprite[num].text,
          x,
          y,
          makecol(Sprite[num].textR, Sprite[num].textG, Sprite[num].textB)
        );
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


