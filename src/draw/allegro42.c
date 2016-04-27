#include "draw/allegro42.h"

void DrawInit(int driver, int filtering)
{
    LogWrite("Initializing Draw Subsystem", 0, MT_INFO, NULL);
    DrawRound = malloc(sizeof(struct drawStep) * RNJ_DRAW_ROUND_LENGTH);
    if (DrawRound == NULL)
        ErrorGive("Can not allocate memory for DrawRound", 1);
    Draw.roundLength = 0;
    Draw.renderer = create_bitmap(SCREEN_W, SCREEN_H);
    if (Draw.renderer == NULL)
        ErrorGive("Can not create backbuffer", 0);
    else
        LogWrite("Backbuffer created", 0, MT_INFO, NULL);
    LogWrite("Draw subsystem initialized", 0, MT_INFO, NULL);
}

void DrawDestroy(void)
{
    free(DrawRound);
    destroy_bitmap(Draw.renderer);
    LogWrite("Draw subsystem Destroyed", 0, MT_INFO, NULL);
}

void DrawAddSprite(int spriteNum, int clipNum, int x, int y)
{
    Draw.roundLength += 1;
    DrawRound[Draw.roundLength - 1].spriteNum = spriteNum;
    DrawRound[Draw.roundLength - 1].clipNum = clipNum;
    DrawRound[Draw.roundLength - 1].x = x;
    DrawRound[Draw.roundLength - 1].y = y;
    DrawRound[Draw.roundLength - 1].width = Sprite[spriteNum].clip[clipNum].w;
    DrawRound[Draw.roundLength - 1].height = Sprite[spriteNum].clip[clipNum].h;
    DrawRound[Draw.roundLength - 1].centerX = 0;
    DrawRound[Draw.roundLength - 1].centerY = 0;
    DrawRound[Draw.roundLength - 1].angle = 0.0;
    DrawRound[Draw.roundLength - 1].a = 255;
    DrawRound[Draw.roundLength - 1].flip = 0;
}

void DrawAddSpriteSized(int spriteNum, int clipNum, int x, int y, int width,
                        int height)
{
    if (width == 0)
    {
        width = Sprite[spriteNum].clip[clipNum].w;
    }
    if (height == 0)
    {
        height = Sprite[spriteNum].clip[clipNum].h;
    }

    Draw.roundLength += 1;
    DrawRound[Draw.roundLength - 1].spriteNum = spriteNum;
    DrawRound[Draw.roundLength - 1].clipNum = clipNum;
    DrawRound[Draw.roundLength - 1].x = x;
    DrawRound[Draw.roundLength - 1].y = y;
    DrawRound[Draw.roundLength - 1].width = width;
    DrawRound[Draw.roundLength - 1].height = height;
    DrawRound[Draw.roundLength - 1].centerX = 0;
    DrawRound[Draw.roundLength - 1].centerY = 0;
    DrawRound[Draw.roundLength - 1].angle = 0.0;
    DrawRound[Draw.roundLength - 1].a = 255;
    DrawRound[Draw.roundLength - 1].flip = 0;
}

void DrawAddSpriteAngled(int spriteNum, int clipNum, int x, int y, int centerX,
                         int centerY, double angle)
{
    Draw.roundLength += 1;
    DrawRound[Draw.roundLength - 1].spriteNum = spriteNum;
    DrawRound[Draw.roundLength - 1].clipNum = clipNum;
    DrawRound[Draw.roundLength - 1].x = x;
    DrawRound[Draw.roundLength - 1].y = y;
    DrawRound[Draw.roundLength - 1].width = Sprite[spriteNum].clip[clipNum].w;
    DrawRound[Draw.roundLength - 1].height = Sprite[spriteNum].clip[clipNum].h;
    DrawRound[Draw.roundLength - 1].centerX = centerX;
    DrawRound[Draw.roundLength - 1].centerY = centerY;
    DrawRound[Draw.roundLength - 1].angle = angle;
    DrawRound[Draw.roundLength - 1].a = 255;
    DrawRound[Draw.roundLength - 1].flip = 0;
}

void DrawAddSpriteAlpha(int spriteNum, int clipNum, int x, int y, int a)
{
    Draw.roundLength += 1;
    DrawRound[Draw.roundLength - 1].spriteNum = spriteNum;
    DrawRound[Draw.roundLength - 1].clipNum = clipNum;
    DrawRound[Draw.roundLength - 1].x = x;
    DrawRound[Draw.roundLength - 1].y = y;
    DrawRound[Draw.roundLength - 1].width = Sprite[spriteNum].clip[clipNum].w;
    DrawRound[Draw.roundLength - 1].height = Sprite[spriteNum].clip[clipNum].h;
    DrawRound[Draw.roundLength - 1].centerX = 0;
    DrawRound[Draw.roundLength - 1].centerY = 0;
    DrawRound[Draw.roundLength - 1].angle = 0.0;
    DrawRound[Draw.roundLength - 1].a = a;
    DrawRound[Draw.roundLength - 1].flip = 0;
}

void DrawAddSpriteGeneral(int spriteNum, int clipNum, int x, int y, int width,
                          int height, int centerX, int centerY, double angle,
                          int a, int flip)
{
    if (width == 0)
    {
        width = Sprite[spriteNum].clip[clipNum].w;
    }
    if (height == 0)
    {
        height = Sprite[spriteNum].clip[clipNum].h;
    }

    Draw.roundLength += 1;
    DrawRound[Draw.roundLength - 1].spriteNum = spriteNum;
    DrawRound[Draw.roundLength - 1].clipNum = clipNum;
    DrawRound[Draw.roundLength - 1].x = x;
    DrawRound[Draw.roundLength - 1].y = y;
    DrawRound[Draw.roundLength - 1].width = width;
    DrawRound[Draw.roundLength - 1].height = height;
    DrawRound[Draw.roundLength - 1].centerX = centerX;
    DrawRound[Draw.roundLength - 1].centerY = centerY;
    DrawRound[Draw.roundLength - 1].angle = angle;
    DrawRound[Draw.roundLength - 1].a = a;
    DrawRound[Draw.roundLength - 1].flip = flip;
}

void DrawAddPoint(int x, int y, int r, int g, int b, int a)
{
    Draw.roundLength += 1;
    DrawRound[Draw.roundLength - 1].spriteNum = RNJ_SPRITE_NUM_POINT;
    DrawRound[Draw.roundLength - 1].clipNum = 0;
    DrawRound[Draw.roundLength - 1].x = x;
    DrawRound[Draw.roundLength - 1].y = y;
    DrawRound[Draw.roundLength - 1].width = 0;
    DrawRound[Draw.roundLength - 1].height = 0;
    DrawRound[Draw.roundLength - 1].r = r;
    DrawRound[Draw.roundLength - 1].g = g;
    DrawRound[Draw.roundLength - 1].b = b;
    DrawRound[Draw.roundLength - 1].a = a;
    DrawRound[Draw.roundLength - 1].flip = 0;
}

void DrawAddLine(int x1, int y1, int x2, int y2, int r, int g, int b, int a)
{
    Draw.roundLength += 1;
    DrawRound[Draw.roundLength - 1].spriteNum = RNJ_SPRITE_NUM_LINE;
    DrawRound[Draw.roundLength - 1].clipNum = 0;
    DrawRound[Draw.roundLength - 1].x = x1;
    DrawRound[Draw.roundLength - 1].y = y1;
    DrawRound[Draw.roundLength - 1].width = x2;
    DrawRound[Draw.roundLength - 1].height = y2;
    DrawRound[Draw.roundLength - 1].r = r;
    DrawRound[Draw.roundLength - 1].g = g;
    DrawRound[Draw.roundLength - 1].b = b;
    DrawRound[Draw.roundLength - 1].a = a;
    DrawRound[Draw.roundLength - 1].flip = 0;
}

void DrawAddRect(int x, int y, int width, int height, int r, int g, int b,
                 int a)
{
    Draw.roundLength += 1;
    DrawRound[Draw.roundLength - 1].spriteNum = RNJ_SPRITE_NUM_RECT;
    DrawRound[Draw.roundLength - 1].clipNum = 0;
    DrawRound[Draw.roundLength - 1].x = x;
    DrawRound[Draw.roundLength - 1].y = y;
    DrawRound[Draw.roundLength - 1].width = x + width;
    DrawRound[Draw.roundLength - 1].height = y + height;
    DrawRound[Draw.roundLength - 1].r = r;
    DrawRound[Draw.roundLength - 1].g = g;
    DrawRound[Draw.roundLength - 1].b = b;
    DrawRound[Draw.roundLength - 1].a = a;
    DrawRound[Draw.roundLength - 1].flip = 0;
}

void DrawAddFilledRect(int x, int y, int width, int height, int r, int g, int b,
                       int a)
{
    Draw.roundLength += 1;
    DrawRound[Draw.roundLength - 1].spriteNum = RNJ_SPRITE_NUM_FILLED_RECT;
    DrawRound[Draw.roundLength - 1].clipNum = 0;
    DrawRound[Draw.roundLength - 1].x = x;
    DrawRound[Draw.roundLength - 1].y = y;
    DrawRound[Draw.roundLength - 1].width = x + width;
    DrawRound[Draw.roundLength - 1].height = y + height;
    DrawRound[Draw.roundLength - 1].r = r;
    DrawRound[Draw.roundLength - 1].g = g;
    DrawRound[Draw.roundLength - 1].b = b;
    DrawRound[Draw.roundLength - 1].a = a;
    DrawRound[Draw.roundLength - 1].flip = 0;
}

void DrawAddFill(int r, int g, int b, int a)
{
    Draw.roundLength += 1;
    DrawRound[Draw.roundLength - 1].spriteNum = RNJ_SPRITE_NUM_FILL;
    DrawRound[Draw.roundLength - 1].clipNum = 0;
    DrawRound[Draw.roundLength - 1].r = r;
    DrawRound[Draw.roundLength - 1].g = g;
    DrawRound[Draw.roundLength - 1].b = b;
    DrawRound[Draw.roundLength - 1].a = a;
    DrawRound[Draw.roundLength - 1].flip = 0;
}

int DrawOutput(void)
{
    int i;
    int roundLength;
    /* Блитинг всех элементов из очереди */
    for (i = 0; i <= Draw.roundLength - 1; i++)
    {
        switch (DrawRound[i].spriteNum)
        {
            case (RNJ_SPRITE_NUM_POINT):
            {
                putpixel(Draw.renderer, DrawRound[i].x, DrawRound[i].y,
                         makeacol32(DrawRound[i].r, DrawRound[i].g, DrawRound[i].b, DrawRound[i].a));
                break;
            }
            case (RNJ_SPRITE_NUM_LINE):
            {
                line(Draw.renderer, DrawRound[i].x, DrawRound[i].y,
                     DrawRound[i].width, DrawRound[i].height,
                     makeacol32(DrawRound[i].r, DrawRound[i].g, DrawRound[i].b, DrawRound[i].a));
                break;
            }
            case (RNJ_SPRITE_NUM_RECT):
            {
                rect(Draw.renderer, DrawRound[i].x, DrawRound[i].y,
                     DrawRound[i].width, DrawRound[i].height,
                     makeacol32(DrawRound[i].r, DrawRound[i].g, DrawRound[i].b, DrawRound[i].a));
                break;
            }
            case (RNJ_SPRITE_NUM_FILLED_RECT):
            {
                rectfill(Draw.renderer, DrawRound[i].x, DrawRound[i].y,
                         DrawRound[i].width, DrawRound[i].height,
                         makeacol32(DrawRound[i].r, DrawRound[i].g, DrawRound[i].b, DrawRound[i].a));
                break;
            }
            case (RNJ_SPRITE_NUM_FILL):
            {
                clear_to_color(Draw.renderer,
                               makeacol32(DrawRound[i].r, DrawRound[i].g, DrawRound[i].b, DrawRound[i].a));
                break;
            }
            default:
            {
                SpritesBlitSprite(DrawRound[i].spriteNum, DrawRound[i].clipNum,
                                  DrawRound[i].x, DrawRound[i].y,
                                  DrawRound[i].width, DrawRound[i].height,
                                  DrawRound[i].centerX, DrawRound[i].centerY,
                                  DrawRound[i].angle, DrawRound[i].a,
                                  DrawRound[i].flip);
                break;
            }
        }
    }
    roundLength = Draw.roundLength;
    /* Обнуление длины очереди */
    Draw.roundLength = 0;
    return roundLength;
}

void DrawFlip(void)
{
    draw_sprite(screen, Draw.renderer, 0, 0);
}

