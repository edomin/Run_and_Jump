#include "scripts/squirrel.h"

void ScriptsInit(void)
{
    LogWrite("Initializing Script Manager", 0, MT_INFO, NULL);
    Scripts.vm = sq_open(1024);
    LogWrite("Squirrel VM created", 1, MT_INFO, NULL);
    //sqstd_seterrorhandlers(v); // это для обработки ошибок. Сделать позже
    RegisterAll();
    LogWrite("Script functions registered", 1, MT_INFO, NULL);
    LogWrite("Script Manager initialized", 0, MT_INFO, NULL);
}

void ScriptsRegisterFunction(SQFUNCTION func, char *funcname)
{
    sq_pushroottable(Scripts.vm);
    sq_pushstring(Scripts.vm, funcname, -1);
    sq_newclosure(Scripts.vm, func, 0); //create a new function
    sq_newslot(Scripts.vm, -3, SQFalse);
    sq_pop(Scripts.vm, 1); //pops the root table
    return;
}

void ScriptsRegisterStringVariable(char *name, char *value)
{
//    lua_pushstring(Scripts.vm, value);
//    lua_setglobal(Scripts.vm, name);
    ;
}

void ScriptsRegisterNumericVariable(char *name, double value)
{
//    lua_pushnumber(Scripts.vm, value);
//    lua_setglobal(Scripts.vm, name);
    ;
}

int ScriptsDoFile(char * filename)
{
    sq_pushroottable(Scripts.vm);
    if (SQ_FAILED(sqstd_dofile(Scripts.vm, filename, 0, 1)))
    {
        return 1;
    }
    return 0;
}

void ScriptsQuit(void)
{
    sq_pop(Scripts.vm, 1); //pops the root table
    sq_close(Scripts.vm);
    LogWrite("Squirrel VM closed", 0, MT_INFO, NULL);
}
