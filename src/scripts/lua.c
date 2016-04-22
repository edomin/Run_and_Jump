#include "scripts/lua.h"

void ScriptsInit(void)
{
    LogWrite("Initializing Script Manager", 0, MT_INFO, NULL);
    Scripts.vm = luaL_newstate();
    if (Scripts.vm != NULL)
        LogWrite("Lua VM created", 1, MT_INFO, NULL);
    else
        ErrorGive("Can not create Lua VM", 1);
    luaL_openlibs(Scripts.vm);
    LogWrite("Lua libs opened", 1, MT_INFO, NULL);
    RegisterAll();
    LogWrite("Script functions registered", 1, MT_INFO, NULL);
    LogWrite("Script Manager initialized", 0, MT_INFO, NULL);
}

void ScriptsRegisterFunction(lua_CFunction func, char * funcname)
{
    lua_register(Scripts.vm, funcname, func); /* регистрируем функцию */
}

void ScriptsRegisterStringVariable(char *name, char *value)
{
    lua_pushstring(Scripts.vm, value);
	lua_setglobal(Scripts.vm, name);
}

void ScriptsRegisterNumericVariable(char *name, double value)
{
    lua_pushnumber(Scripts.vm, value);
	lua_setglobal(Scripts.vm, name);
}

int ScriptsDoFile(char * filename)
{
    return luaL_dofile(Scripts.vm, filename);
}

void ScriptsQuit(void)
{
    lua_close(Scripts.vm);
    LogWrite("Lua VM closed", 0, MT_INFO, NULL);
}
