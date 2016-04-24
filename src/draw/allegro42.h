#ifndef RNJ_DRAW_ALLEGRO42_H
#define RNJ_DRAW_ALLEGRO42_H

#include <stdlib.h>
#include "allegro42/allegro.h"

#include "screen.h"
#include "sprites.h"
#include "defines.h"

/* ��������� �������� ������� ��������� */
struct drawStep{
    int spriteNum; /* ����� ������� */
    int clipNum; /* ����� ����� */
    int x; /* �������������� ������� */
    int y; /* ������������ ������� */
    int width; /* ����� */
    int height; /* ������ */
    double angle; /* ���� �������� */
    int centerX; /* ����� �������� */
    int centerY; /* ����� �������� */
    int r; /* ������� ��� ������� ���������� */
    int g; /* ������� ��� ������� ���������� */
    int b; /* ����� ��� ������� ���������� */
    int a; /* ����� ����� ������� ��� ��������� */
    int flip; /* ��������� ������� �� ����������� � ��������� */
} *DrawRound;

struct {
	BITMAP *renderer; /* �������� */
    int roundLength; /* ����� ������� ��������� */
} Draw;

void DrawInit(int, int); /* ������������� ��������� */
void DrawDestroy(void); /* ����������� ��������� */
void DrawAddSprite(int, int, int, int); /* ���������� ������� � ������� */
void DrawAddSpriteSized(int, int, int, int, int, int); /* ���������� ������������ ��� ������������ ������� � ������� */
void DrawAddSpriteAngled(int, int, int, int, int, int, double); /* ���������� ����������� ������� � ������� */
void DrawAddSpriteAlpha(int, int, int, int, int); /* ���������� ������� c ������������� � ������� */
void DrawAddSpriteGeneral(int, int, int, int, int, int, int, int, double, int, int); /* ���������� ������������ ��� ������������ ����������� ������� � ������������� � ������� */
void DrawAddPoint(int, int, int, int, int, int); /* ���������� ����� � ������� */
void DrawAddLine(int, int, int, int, int, int, int, int); /* ���������� ����� � ������� */
void DrawAddRect(int, int, int, int, int, int, int, int); /* ���������� �������������� � ������� */
void DrawAddFilledRect(int, int, int, int, int, int, int, int); /* ���������� ����������� �������������� � ������� */
void DrawAddFill(int, int, int, int); /* ���������� ������� ������ � ������� */
int DrawOutput(void); /* ����� ���� ��������� �� ������� */
void DrawFlip(void); /* ���������� ��������� */

#endif


