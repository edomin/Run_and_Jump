#ifndef RNJ_SCRIPTS_LUA_H
#define RNJ_SCRIPTS_LUA_H

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "log.h"
#include "error.h"
#include "scriptFuncs.h"
#include "defines.h"

struct {
    lua_State* vm; /* виртуальная машина */
    int ObjectsCount;
} Scripts;

void ScriptsInit(void); /* Инициализация Менеджера Скриптов */
void ScriptsRegisterFunction(lua_CFunction, char *); /* Регистрация функции */
void ScriptsRegisterNumericVariable(char *, double); /* Регистрация глобальной числовой переменной */
void ScriptsRegisterStringVariable(char *, char *); /* Регистрация глобальной строковой переменной */
int ScriptsDoFile(char *); /* Выполнение скрипта */
void ScriptsQuit(void); /* Деинициализация Менеджера Скриптов */

#endif
