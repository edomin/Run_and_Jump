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
    lua_State*  vm; /* виртуальная машина */
    int         ObjectsCount;
} Scripts;

/* Инициализация Менеджера Скриптов */
void ScriptsInit(void);
/* Регистрация функции */
void ScriptsRegisterFunction(lua_CFunction, char *);
/* Регистрация глобальной числовой переменной */
void ScriptsRegisterNumericVariable(char *, double);
/* Регистрация глобальной строковой переменной */
void ScriptsRegisterStringVariable(char *, char *);
/* Выполнение скрипта */
int ScriptsDoFile(char *);
/* Деинициализация Менеджера Скриптов */
void ScriptsQuit(void);

#endif
