#ifndef RNJ_APP_SDL2_H
#define RNJ_APP_SDL2_H

#include "bool.h"
#include "SDL2/SDL.h"

#include "log.h"
#include "error.h"
#include "defines.h"

struct {
    bool quit; /* Выход из программы */
    SDL_Event event; /* Событие приложения */
    signed int mouseX; /* Горизонтальная позиция курсора */
    signed int mouseY; /* Вертикальная позиция курсора */
} App;

void AppInit(void); /* Инициализация приложения */
void AppDestroy(void); /* Деинициализация приложения */
bool AppXed(void); /* Узнать, был ли совершен выход из программы */

#endif

