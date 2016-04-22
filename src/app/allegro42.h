#ifndef RNJ_APP_ALLEGRO42_H
#define RNJ_APP_ALLEGRO42_H

#include "log.h"
#include "error.h"
#include "defines.h"

#define ALLEGRO_NO_MAGIC_MAIN
#include "allegro42/allegro.h"

struct {
    bool quit; /* ����� �� ��������� */
    //ALLEGRO_EVENT_QUEUE* eq; /* ������� ������� */
    //ALLEGRO_EVENT event; /* ������� ���������� */
    signed int mouseX; /* �������������� ������� ������� */
    signed int mouseY; /* ������������ ������� ������� */
    bool xed;
} App;

void AppInit(void); /* ������������� ���������� */
void AppDestroy(void); /* ��������������� ���������� */
bool AppXed(void); /* ������, ��� �� �������� ����� �� ��������� */

#endif


