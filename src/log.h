#ifndef RNJ_LOG_H
#define RNJ_LOG_H

#include <stdio.h>
#include <time.h>

#include "files.h"
#include "utils.h"
#include "defines.h"

void LogInit(void); /* Инициализация лога */
void LogWrite(char *, int, int, char *); /* Запись строки в лог на уровне вложенности level*/
void LogWrite2(char *, int, int, int); /* Запись строки в лог на уровне вложенности level*/
void LogWriteFromScript(char *, int, int, char *); /* Запись строки в лог на уровне вложенности level из скрипта */

struct {
    FILE *fs; /* Указатель на файл лога */
    time_t currentTime; /* Текущее время */
    struct tm *now; /* Структура текущего времени */
} Log;

#endif
