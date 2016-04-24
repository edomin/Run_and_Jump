#include "sprites/allegro42.h"

void SpritesInit(int sprites)
{
    LogWrite("Initializing Sprite Manager", 0, MT_INFO, NULL);
    Sprites.spritesCount = 0; /* устанавливаем количество загруженных спрайтов в 0 */
    Sprite = malloc(sizeof(struct sprite) * sprites);
    if (Sprite == NULL)
        ErrorGive("Can not allocate memory for Sprites", 1);
	LogWrite("Reporting loadpng for Allegro 4.2 library version:", 0, MT_INFO, LOADPNG_VERSIONSTR);
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
//    al_shutdown_image_addon();
    LogWrite("Sprite Manager Destroyed.", 0, MT_INFO, NULL);
}

int SpritesCreateSprite(char *filename, int clips)
{
    int i;
    Sprite[Sprites.spritesCount].name = malloc(sizeof(char) * (strlen(filename) + 1));
    Sprite[Sprites.spritesCount].name = strcpy(Sprite[Sprites.spritesCount].name, (const char *)filename);
    LogWrite("Creating sprite", 0, MT_INFO, Sprite[Sprites.spritesCount].name);
    Sprites.spritesCount += 1; /* Увеличиваем кол-во спрайтов на 1 */
//    Sprite[Sprites.spritesCount - 1].text = NULL; /* Текст спрайта (для текстовых спрайтов) */
    /* Загружаем файл */
    Sprite[Sprites.spritesCount - 1].texture = NULL;/* обнуляем поверхность спрайта */

	Sprite[Sprites.spritesCount - 1].texture = load_bitmap((const char*)filename, NULL);

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

int SpritesCreateText(char *text, int fontnum, int text_r, int text_g, int text_b, int wrapLength)
{
//    Sprite[Sprites.spritesCount].name = malloc(sizeof(char) * (strlen(text) + 1));
//    Sprite[Sprites.spritesCount].name = strcpy(Sprite[Sprites.spritesCount].name, (const char *)text);
//    LogWrite("Dummying text sprite", 0, MT_INFO, Sprite[Sprites.spritesCount].name);
//
//    Sprites.spritesCount += 1; /* Увеличиваем кол-во спрайтов на 1 */
//
//	Sprite[Sprites.spritesCount - 1].text = al_ustr_new((const char *)text);
//	Sprite[Sprites.spritesCount - 1].fontNum = fontnum;
//	Sprite[Sprites.spritesCount - 1].textR = text_r;
//	Sprite[Sprites.spritesCount - 1].textG = text_g;
//	Sprite[Sprites.spritesCount - 1].textB = text_b;
//	Sprite[Sprites.spritesCount - 1].wrapLength = wrapLength;
//
//    Sprite[Sprites.spritesCount - 1].width =  al_get_ustr_width((const ALLEGRO_FONT *)Fonts.font[fontnum], Sprite[Sprites.spritesCount - 1].text);
//    Sprite[Sprites.spritesCount - 1].height = al_get_font_ascent((const ALLEGRO_FONT *)Fonts.font[fontnum]);
//
//    Sprite[Sprites.spritesCount - 1].texture = NULL;/* обнуляем поверхность спрайта */
//
//    /* устанавливаем число кадров для спрайта - для текста 1 кадр */
//    Sprite[Sprites.spritesCount - 1].clip = malloc(sizeof(Rect) * 1);
//    /* разбиваем спрайтшит на кадры */
//
//    Sprite[Sprites.spritesCount - 1].clip[0].x = 0;
//    Sprite[Sprites.spritesCount - 1].clip[0].y = 0;
//    Sprite[Sprites.spritesCount - 1].clip[0].w = Sprite[Sprites.spritesCount - 1].width;
//    Sprite[Sprites.spritesCount - 1].clip[0].h = Sprite[Sprites.spritesCount - 1].height;
//
//    Sprite[Sprites.spritesCount - 1].clipsCount = 1;
//
//    LogWrite("Text sprite dummied", 0, MT_INFO, NULL);
//
//    return Sprites.spritesCount - 1;
}

void SpritesChangeText(int num, char *text, int fontnum, int text_r, int text_g, int text_b, int wrapLength)
{
//	Sprite[num].text = al_ustr_new((const char *)text);
//	Sprite[num].fontNum = fontnum;
//	Sprite[num].textR = text_r;
//	Sprite[num].textG = text_g;
//	Sprite[num].textB = text_b;
//	Sprite[num].wrapLength = wrapLength;
//
//    Sprite[num].width =  al_get_text_width((const ALLEGRO_FONT *)Fonts.font[fontnum], (const char *)text);
//    Sprite[Sprites.spritesCount - 1].height = al_get_font_ascent((const ALLEGRO_FONT *)Fonts.font[fontnum]);
//
//    Sprite[num].texture = NULL;/* обнуляем поверхность спрайта */
//
//    /* разбиваем спрайтшит на кадры */
//
//    Sprite[num].clip[0].x = 0;
//    Sprite[num].clip[0].y = 0;
//    Sprite[num].clip[0].w = Sprite[Sprites.spritesCount - 1].width;
//    Sprite[num].clip[0].h = Sprite[Sprites.spritesCount - 1].height;
//
//    Sprite[num].clipsCount = 1;
}

void SpritesBlitSprite(int num, int clip, int x, int y, int width, int height, int centerX, int centerY, double angle, int a, int flip)
{
//	if (Sprite[num].text == NULL)
//	{
		if (Sprite[num].texture != NULL)
		{
			set_clip_rect(
			  Sprite[num].texture,
			  Sprite[num].clip[clip].x,
			  Sprite[num].clip[clip].y,
			  Sprite[num].clip[clip].x + Sprite[num].clip[clip].w,
			  Sprite[num].clip[clip].y + Sprite[num].clip[clip].w
			);
			switch (flip)
			{
				case DRAW_FLIP_HORIZONTAL:
					pivot_scaled_sprite_v_flip(Draw.renderer, Sprite[num].texture, x, y, centerX, centerY, ftofix(128 - angle * 0.711111), ftofix(width / Sprite[Sprites.spritesCount - 1].width));
					break;
				case DRAW_FLIP_VERTICAL:
					pivot_scaled_sprite_v_flip(Draw.renderer, Sprite[num].texture, x, y, centerX, centerY, ftofix(0 - angle * 0.711111), ftofix(width / Sprite[Sprites.spritesCount - 1].width));
					break;
				case DRAW_FLIP_BOTH:
					pivot_scaled_sprite(Draw.renderer, Sprite[num].texture, x, y, centerX, centerY, ftofix(128 - angle * 0.711111), ftofix(width / Sprite[Sprites.spritesCount - 1].width));
					break;
				default:
					pivot_scaled_sprite(Draw.renderer, Sprite[num].texture, x, y, centerX, centerY, ftofix(0 - angle * 0.711111), ftofix(width / Sprite[Sprites.spritesCount - 1].width));
					break;
			}

		}
//	}
//	else
//	{
//		al_draw_ustr(Fonts.font[Sprite[num].fontNum],
//		  al_map_rgba(Sprite[num].textR * a / 255, Sprite[num].textG * a / 255, Sprite[num].textB * a / 255, 255 * a / 255),
//		  x,
//		  y,
//		  ALLEGRO_ALIGN_INTEGER,
//		  (const ALLEGRO_USTR *)Sprite[num].text);
//	}
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


