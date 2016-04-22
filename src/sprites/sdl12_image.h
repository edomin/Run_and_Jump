#ifndef RNJ_SPRITES_SDL12_IMAGE_H
#define RNJ_SPRITES_SDL12_IMAGE_H

#include <stdlib.h>
#include <string.h>

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

#include "app.h"
#include "draw.h"
#include "fonts.h"
#include "error.h"
#include "log.h"
#include "defines.h"

struct sprite {
    SDL_Surface *texture; /* �������� ������� */
    SDL_Rect *clip; /* ������������ ����� ������ �������� */
    int clipsCount; /* ���������� ������ �������� */
    char *name; /* ��� ������� (��� ����� ��� ������ ��� ���������� �������) */
    int width;
    int height;
} *Sprite;

struct {
    int spritesCount;
    SDL_Surface *loadedImage; /* ��������� ����������� ��� ����������� ����������� */
    SDL_Surface *tempImage;
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

