#include "draw/freeglut.h"

void DrawInit(int driver, int filtering)
{
    LogWrite("Initializing Draw Subsystem", 0, MT_INFO, NULL);
    // Draw.renderer = NULL;
    DrawRound = malloc(sizeof(struct drawStep) * RNJ_DRAW_ROUND_LENGTH);
    if (DrawRound == NULL)
         ErrorGive("Can not allocate memory for DrawRound", 1);
    Draw.roundLength = 0;
    LogWrite("Draw subsystem initialized", 0, MT_INFO, NULL);
}

void DrawDestroy(void)
{
    free(DrawRound);
}

void DrawAddSprite(int spriteNum, int clipNum, int x, int y)
{
    Draw.roundLength += 1;
    DrawRound[Draw.roundLength - 1].spriteNum = spriteNum;
    DrawRound[Draw.roundLength - 1].clipNum = clipNum;
    DrawRound[Draw.roundLength - 1].x = x;
    DrawRound[Draw.roundLength - 1].y = y;
    #ifndef LSPRITES_DUMMY
    DrawRound[Draw.roundLength - 1].width = Sprite[spriteNum].clip[clipNum].w;
    DrawRound[Draw.roundLength - 1].height = Sprite[spriteNum].clip[clipNum].h;
    #endif
    DrawRound[Draw.roundLength - 1].centerX = 0;
    DrawRound[Draw.roundLength - 1].centerY = 0;
    DrawRound[Draw.roundLength - 1].angle = 0.0;
    DrawRound[Draw.roundLength - 1].a = 255;
    DrawRound[Draw.roundLength - 1].flip = 0;
}

void DrawAddSpriteSized(int spriteNum, int clipNum, int x, int y, int width, int height)
{
    if (width == 0)
    {
        #ifndef LSPRITES_DUMMY
        width = Sprite[spriteNum].clip[clipNum].w;
        #endif
    }
    if (height == 0)
    {
        #ifndef LSPRITES_DUMMY
        height = Sprite[spriteNum].clip[clipNum].h;
        #endif
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

void DrawAddSpriteAngled(int spriteNum, int clipNum, int x, int y, int centerX, int centerY, double angle)
{
    Draw.roundLength += 1;
    DrawRound[Draw.roundLength - 1].spriteNum = spriteNum;
    DrawRound[Draw.roundLength - 1].clipNum = clipNum;
    DrawRound[Draw.roundLength - 1].x = x;
    DrawRound[Draw.roundLength - 1].y = y;
    #ifndef LSPRITES_DUMMY
    DrawRound[Draw.roundLength - 1].width = Sprite[spriteNum].clip[clipNum].w;
    DrawRound[Draw.roundLength - 1].height = Sprite[spriteNum].clip[clipNum].h;
    #endif
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
    #ifndef LSPRITES_DUMMY
    DrawRound[Draw.roundLength - 1].width = Sprite[spriteNum].clip[clipNum].w;
    DrawRound[Draw.roundLength - 1].height = Sprite[spriteNum].clip[clipNum].h;
    #endif
    DrawRound[Draw.roundLength - 1].centerX = 0;
    DrawRound[Draw.roundLength - 1].centerY = 0;
    DrawRound[Draw.roundLength - 1].angle = 0.0;
    DrawRound[Draw.roundLength - 1].a = a;
    DrawRound[Draw.roundLength - 1].flip = 0;
}

void DrawAddSpriteGeneral(int spriteNum, int clipNum, int x, int y, int width, int height, int centerX, int centerY, double angle, int a, int flip)
{
    if (width == 0)
    {
        #ifndef LSPRITES_DUMMY
        width = Sprite[spriteNum].clip[clipNum].w;
        #endif
    }
    if (height == 0)
    {
        #ifndef LSPRITES_DUMMY
        height = Sprite[spriteNum].clip[clipNum].h;
        #endif
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

void DrawAddRect(int x, int y, int width, int height, int r, int g, int b, int a)
{
    Draw.roundLength += 1;
    DrawRound[Draw.roundLength - 1].spriteNum = RNJ_SPRITE_NUM_RECT;
    DrawRound[Draw.roundLength - 1].clipNum = 0;
    DrawRound[Draw.roundLength - 1].x = x;
    DrawRound[Draw.roundLength - 1].y = y;
    DrawRound[Draw.roundLength - 1].width = width;
    DrawRound[Draw.roundLength - 1].height = height;
    DrawRound[Draw.roundLength - 1].r = r;
    DrawRound[Draw.roundLength - 1].g = g;
    DrawRound[Draw.roundLength - 1].b = b;
    DrawRound[Draw.roundLength - 1].a = a;
    DrawRound[Draw.roundLength - 1].flip = 0;
}

void DrawAddFilledRect(int x, int y, int width, int height, int r, int g, int b, int a)
{
    Draw.roundLength += 1;
    DrawRound[Draw.roundLength - 1].spriteNum = RNJ_SPRITE_NUM_FILLED_RECT;
    DrawRound[Draw.roundLength - 1].clipNum = 0;
    DrawRound[Draw.roundLength - 1].x = x;
    DrawRound[Draw.roundLength - 1].y = y;
    DrawRound[Draw.roundLength - 1].width = width;
    DrawRound[Draw.roundLength - 1].height = height;
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
    glClear(GL_COLOR_BUFFER_BIT);
    for (i = 0; i <= Draw.roundLength - 1; i++)
    {
        switch (DrawRound[i].spriteNum)
        {
            case (RNJ_SPRITE_NUM_POINT):
            {
                // SDL_SetRenderDrawColor(Draw.renderer, DrawRound[i].r, DrawRound[i].g, DrawRound[i].b, DrawRound[i].a);
                // SDL_RenderDrawPoint(Draw.renderer, DrawRound[i].x, DrawRound[i].y);
                break;
            }
            case (RNJ_SPRITE_NUM_LINE):
            {
                // SDL_SetRenderDrawColor(Draw.renderer, DrawRound[i].r, DrawRound[i].g, DrawRound[i].b, DrawRound[i].a);
                // SDL_RenderDrawLine(Draw.renderer, DrawRound[i].x, DrawRound[i].y, DrawRound[i].width, DrawRound[i].height);
                break;
            }
            case (RNJ_SPRITE_NUM_RECT):
            {
                // SDL_SetRenderDrawColor(Draw.renderer, DrawRound[i].r, DrawRound[i].g, DrawRound[i].b, DrawRound[i].a);
                // rect.x = DrawRound[i].x;
                // rect.y = DrawRound[i].y;
                // rect.w = DrawRound[i].width;
                // rect.h = DrawRound[i].height;
                // SDL_RenderDrawRect(Draw.renderer, &rect);
                break;
            }
            case (RNJ_SPRITE_NUM_FILLED_RECT):
            {
                // SDL_SetRenderDrawColor(Draw.renderer, DrawRound[i].r, DrawRound[i].g, DrawRound[i].b, DrawRound[i].a);
                // rect.x = DrawRound[i].x;
                // rect.y = DrawRound[i].y;
                // rect.w = DrawRound[i].width;
                // rect.h = DrawRound[i].height;
                // SDL_RenderFillRect(Draw.renderer, &rect);
                break;
            }
            case (RNJ_SPRITE_NUM_FILL):
            {
                // SDL_SetRenderDrawColor(Draw.renderer, DrawRound[i].r, DrawRound[i].g, DrawRound[i].b, DrawRound[i].a);
                // SDL_RenderClear(Draw.renderer);
                break;
            }
            default:
            {
                SpritesBlitSprite(DrawRound[i].spriteNum, DrawRound[i].clipNum, DrawRound[i].x, DrawRound[i].y, DrawRound[i].width, DrawRound[i].height, DrawRound[i].centerX, DrawRound[i].centerY, DrawRound[i].angle, DrawRound[i].a, DrawRound[i].flip);
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
    glutSwapBuffers();
}
