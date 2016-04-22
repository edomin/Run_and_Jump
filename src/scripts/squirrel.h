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
    HSQUIRRELVM vm; /* ����������� ������ */
    int ObjectsCount;
} Scripts;

void ScriptsInit(void); /* ������������� ��������� �������� */
void ScriptsRegisterFunction(SQFUNCTION, char *); /* ����������� ������� */
void ScriptsRegisterNumericVariable(char *, double); /* ����������� ���������� �������� ���������� */
void ScriptsRegisterStringVariable(char *, char *); /* ����������� ���������� ��������� ���������� */
int ScriptsDoFile(char *); /* ���������� ������� */
void ScriptsQuit(void); /* ��������������� ��������� �������� */

#endif
