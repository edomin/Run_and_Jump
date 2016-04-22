#ifndef RNJ_APP_ALLEGRO42_H
#define RNJ_APP_ALLEGRO42_H

#include "log.h"
#include "error.h"
#include "defines.h"

#define ALLEGRO_NO_MAGIC_MAIN
#include "allegro42/allegro.h"

struct {
    bool quit; /* Выход из программы */
    //ALLEGRO_EVENT_QUEUE* eq; /* Сборщик событий */
    //ALLEGRO_EVENT event; /* Событие приложения */
    signed int mouseX; /* Горизонтальная позиция курсора */
    signed int mouseY; /* Вертикальная позиция курсора */
    bool xed;
} App;

void AppInit(void); /* Инициализация приложения */
void AppDestroy(void); /* Деинициализация приложения */
bool AppXed(void); /* Узнать, был ли совершен выход из программы */

#endif


