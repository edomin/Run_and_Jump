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
    lua_State* vm; /* ����������� ������ */
    int ObjectsCount;
} Scripts;

void ScriptsInit(void); /* ������������� ��������� �������� */
void ScriptsRegisterFunction(lua_CFunction, char *); /* ����������� ������� */
void ScriptsRegisterNumericVariable(char *, double); /* ����������� ���������� �������� ���������� */
void ScriptsRegisterStringVariable(char *, char *); /* ����������� ���������� ��������� ���������� */
int ScriptsDoFile(char *); /* ���������� ������� */
void ScriptsQuit(void); /* ��������������� ��������� �������� */

#endif
