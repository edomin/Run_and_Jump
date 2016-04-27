#ifndef RNJ_APP_ALLEGRO5_H
#define RNJ_APP_ALLEGRO5_H

#include "log.h"
#include "error.h"
#include "defines.h"

#include "allegro5/allegro.h"

struct {
    bool                 quit;  /* Выход из программы                         */
    ALLEGRO_EVENT_QUEUE* eq;    /* Сборщик событий                            */
    ALLEGRO_EVENT        event; /* Событие приложения                         */
    signed int           mouseX;/* Горизонтальная позиция курсора             */
    signed int           mouseY;/* Вертикальная позиция курсора               */
} App;

void AppInit(void);             /* Инициализация приложения                   */
void AppDestroy(void);          /* Деинициализация приложения                 */
bool AppXed(void);              /* Узнать, был ли совершен выход из программы */

#endif

