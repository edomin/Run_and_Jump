#ifndef RNJ_SCRIPTFUNCS_H
#define RNJ_SCRIPTFUNCS_H

#include <math.h>
#include <stdlib.h>

#if INCLUDE_BOOL
    #include <bool.h>
#endif

#include "scripts.h"
#include "app.h"
#include "configfile.h"
#include "screen.h"
#include "draw.h"
#include "input.h"
#include "timer.h"
#include "sounds.h"
#include "images.h"
#include "physics.h"
#include "files.h"
#include "dialogs.h"
#include "log.h"
#include "utils.h"
#include "defines.h"

#ifdef LS_LUA
    #include "scriptFuncs/lua.h"
#endif
#ifdef LS_SQUIRREL
    #include "scriptFuncs/squirrel.h"
#endif
#ifdef LS_DUMMY
    #include "scriptFuncs/dummy.h"
#endif

void RegisterAll(void);

#endif

