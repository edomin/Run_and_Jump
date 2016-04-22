#ifndef RNJ_SCRIPTS_DUMMY_H
#define RNJ_SCRIPTS_DUMMY_H

#include "log.h"
#include "error.h"
#include "scriptFuncs.h"
#include "defines.h"

//struct {
//    lua_State* vm; /* ����������� ������ */
//    int ObjectsCount;
//} Scripts;

void ScriptsInit(void); /* ������������� ��������� �������� */
void ScriptsRegisterFunction(void *, char *); /* ����������� ������� */
void ScriptsRegisterNumericVariable(char *, double); /* ����������� ���������� �������� ���������� */
void ScriptsRegisterStringVariable(char *, char *); /* ����������� ���������� ��������� ���������� */
int ScriptsDoFile(char *); /* ���������� ������� */
void ScriptsQuit(void); /* ��������������� ��������� �������� */

#endif
