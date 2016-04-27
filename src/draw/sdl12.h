#ifndef RNJ_DRAW_SDL12_H
#define RNJ_DRAW_SDL12_H

#include <stdlib.h>
#include "SDL/SDL.h"

#include "screen.h"
#include "sprites.h"
#include "defines.h"

/* Структура элемента очереди рисования */
struct drawStep{
    int             spriteNum; /* Номер спрайта */
    int             clipNum;   /* Номер кадра */
    int             x;         /* Горизонтальная позиция */
    int             y;         /* Вертикальная позиция */
    int             width;     /* Длина */
    int             height;    /* Высота */
    double          angle;     /* Угол поворота */
    int             centerX;   /* Точка поворота */
    int             centerY;   /* Точка поворота */
    int             r;         /* Красный для окраски примитивов */
    int             g;         /* Зеленый для окраски примитивов */
    int             b;         /* Синий для окраски примитивов */
    int             a;         /* Альфа канал спрайта или примитива */
    int             flip;      /* Отражение спрайта по горизонтали и вертикали*/
} *DrawRound;

struct {
    SDL_Surface *   renderer;       /* Рендерер */
    int             roundLength;    /* Длина очереди рисования */
//    SDL_RendererInfo rendererInfo;
} Draw;

/* Инициализация рисовалки */
void DrawInit(int, int);
/* Уничтожение рисовалки */
void DrawDestroy(void);
/* Добавление спрайта в очередь */
void DrawAddSprite(int, int, int, int);
/* Добавление увеличенного или уменьшенного спрайта в очередь */
void DrawAddSpriteSized(int, int, int, int, int, int);
/* Добавление повернутого спрайта в очередь */
void DrawAddSpriteAngled(int, int, int, int, int, int, double);
/* Добавление спрайта c прозрачностью в очередь */
void DrawAddSpriteAlpha(int, int, int, int, int);
/* Добавление увеличенного или уменьшенного повернутого спрайта с прозрачностью
   в очередь */
void DrawAddSpriteGeneral(int, int, int, int, int, int, int, int, double, int,
                          int);
/* Добавление точки в очередь */
void DrawAddPoint(int, int, int, int, int, int);
/* Добавление линии в очередь */
void DrawAddLine(int, int, int, int, int, int, int, int);
/* Добавление прямоугольника в очередь */
void DrawAddRect(int, int, int, int, int, int, int, int);
/* Добавление закрашеного прямоугольника в очередь */
void DrawAddFilledRect(int, int, int, int, int, int, int, int);
/* Добавление заливки экрана в очередь */
void DrawAddFill(int, int, int, int);
/* Вывод всех элементов из очереди */
int DrawOutput(void);
/* Обновление рендерера */
void DrawFlip(void);

#endif

