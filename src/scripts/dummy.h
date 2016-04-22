#ifndef RNJ_SCRIPTS_DUMMY_H
#define RNJ_SCRIPTS_DUMMY_H

#include "log.h"
#include "error.h"
#include "scriptFuncs.h"
#include "defines.h"

//struct {
//    lua_State* vm; /* виртуальная машина */
//    int ObjectsCount;
//} Scripts;

void ScriptsInit(void); /* Инициализация Менеджера Скриптов */
void ScriptsRegisterFunction(void *, char *); /* Регистрация функции */
void ScriptsRegisterNumericVariable(char *, double); /* Регистрация глобальной числовой переменной */
void ScriptsRegisterStringVariable(char *, char *); /* Регистрация глобальной строковой переменной */
int ScriptsDoFile(char *); /* Выполнение скрипта */
void ScriptsQuit(void); /* Деинициализация Менеджера Скриптов */

#endif
