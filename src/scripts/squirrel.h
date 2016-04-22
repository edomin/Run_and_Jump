#ifndef RNJ_SCRIPTS_SQUIRREL_H
#define RNJ_SCRIPTS_SQUIRREL_H

#include <squirrel.h>
#include <sqstdio.h>
#include <sqstdaux.h>

#include "log.h"
#include "error.h"
#include "scriptFuncs.h"
#include "defines.h"

struct {
    HSQUIRRELVM vm; /* виртуальная машина */
    int ObjectsCount;
} Scripts;

void ScriptsInit(void); /* Инициализация Менеджера Скриптов */
void ScriptsRegisterFunction(SQFUNCTION, char *); /* Регистрация функции */
void ScriptsRegisterNumericVariable(char *, double); /* Регистрация глобальной числовой переменной */
void ScriptsRegisterStringVariable(char *, char *); /* Регистрация глобальной строковой переменной */
int ScriptsDoFile(char *); /* Выполнение скрипта */
void ScriptsQuit(void); /* Деинициализация Менеджера Скриптов */

#endif
