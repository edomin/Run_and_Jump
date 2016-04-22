#ifndef RNJ_APP_ALLEGRO5_H
#define RNJ_APP_ALLEGRO5_H

#include "log.h"
#include "error.h"
#include "defines.h"

#include "allegro5/allegro.h"

struct {
    bool quit; /* ����� �� ��������� */
    ALLEGRO_EVENT_QUEUE* eq; /* ������� ������� */
    ALLEGRO_EVENT event; /* ������� ���������� */
    signed int mouseX; /* �������������� ������� ������� */
    signed int mouseY; /* ������������ ������� ������� */
} App;

void AppInit(void); /* ������������� ���������� */
void AppDestroy(void); /* ��������������� ���������� */
bool AppXed(void); /* ������, ��� �� �������� ����� �� ��������� */

#endif

