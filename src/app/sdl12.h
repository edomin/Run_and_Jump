#ifndef RNJ_APP_SDL12_H
#define RNJ_APP_SDL12_H

#include "log.h"
#include "error.h"
#include "defines.h"

#include "bool.h"
#include "SDL/SDL.h"

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


