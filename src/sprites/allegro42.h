#ifndef RNJ_SPRITES_ALLEGRO42_H
#define RNJ_SPRITES_ALLEGRO42_H

#include <stdlib.h>
#include <string.h>

#include "allegro42/allegro.h"
#include "allegro42/loadpng.h"

#include "app.h"
#include "fonts.h"
#include "draw.h"
#include "error.h"
#include "log.h"
#include "defines.h"

typedef struct rect {
	int x;
	int y;
	int w;
	int h;
} Rect;

struct sprite {
    BITMAP *texture; /* �������� ������� */
    Rect *clip; /* ������������ ����� ������ �������� */
    int clipsCount; /* ���������� ������ �������� */
    char *name; /* ��� ������� (��� ����� ��� ������ ��� ���������� �������) */
    int width; /* ������ ����� ������� */
    int height; /* ������ ����� ������� */
    /* �������� ��� ��������� �������� */
//    ALLEGRO_USTR *text; /* ����� */
//    int fontNum; /* ����� ������ */
//    int textR; /* ������� ��������� */
//    int textG; /* ������� ��������� */
//    int textB; /* ����� ��������� */
//    int wrapLength; /* ����� ������ ��� �������������� ������ (�� ����� ��������) */
} *Sprite;

struct {
    int spritesCount;
    //SDL_Surface *loadedImage; /* ��������� ����������� ��� ����������� ����������� */
} Sprites;

void SpritesInit(int);/* ������������� */
int SpritesCreateSprite(char *, int);/* �������� ������� */
int SpritesCreateText(char *, int, int, int, int, int);/* �������� ���������� ������� */
void SpritesChangeText(int, char *, int, int, int, int, int);/* ���������� ������ �� ������������ ��������� ������� */
                                                        /* � ���������� ��� ����� */
void SpritesBlitSprite(int, int, int, int, int, int, int, int, double, int, int); /* ����� ������� */
void SpritesDestroySprite(int); /* ����������� ������� */
void SpritesQuit(void); /* ��������� ������ ��������� �������� */

#endif


