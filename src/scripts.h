#ifndef RNJ_SCRIPTS_H
#define RNJ_SCRIPTS_H

#ifdef LS_LUA
    #include "scripts/lua.h"
#endif
#ifdef LS_SQUIRREL
    #include "scripts/squirrel.h"
#endif
#ifdef LS_DUMMY
    #include "scripts/dummy.h"
#endif

#endif
