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
    int         ObjectsCount;
} Scripts;

/* Инициализация Менеджера Скриптов */
void ScriptsInit(void);
/* Регистрация функции */
void ScriptsRegisterFunction(SQFUNCTION, char *);
/* Регистрация глобальной числовой переменной */
void ScriptsRegisterNumericVariable(char *, double);
/* Регистрация глобальной строковой переменной */
void ScriptsRegisterStringVariable(char *, char *);
/* Выполнение скрипта */
int ScriptsDoFile(char *);
/* Деинициализация Менеджера Скриптов */
void ScriptsQuit(void);

#endif
