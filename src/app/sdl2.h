#ifndef RNJ_APP_SDL2_H
#define RNJ_APP_SDL2_H

#include "bool.h"
#include "SDL2/SDL.h"

#include "log.h"
#include "error.h"
#include "defines.h"

struct {
    bool quit; /* ����� �� ��������� */
    SDL_Event event; /* ������� ���������� */
    signed int mouseX; /* �������������� ������� ������� */
    signed int mouseY; /* ������������ ������� ������� */
} App;

void AppInit(void); /* ������������� ���������� */
void AppDestroy(void); /* ��������������� ���������� */
bool AppXed(void); /* ������, ��� �� �������� ����� �� ��������� */

#endif

