#ifndef RNJ_LOG_H
#define RNJ_LOG_H

#include <stdio.h>
#include <time.h>

#include "files.h"
#include "utils.h"
#include "defines.h"

void LogInit(void); /* ������������� ���� */
void LogWrite(char *, int, int, char *); /* ������ ������ � ��� �� ������ ����������� level*/
void LogWrite2(char *, int, int, int); /* ������ ������ � ��� �� ������ ����������� level*/
void LogWriteFromScript(char *, int, int, char *); /* ������ ������ � ��� �� ������ ����������� level �� ������� */

struct {
    FILE *fs; /* ��������� �� ���� ���� */
    time_t currentTime; /* ������� ����� */
    struct tm *now; /* ��������� �������� ������� */
} Log;

#endif
