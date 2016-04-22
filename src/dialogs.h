#ifndef RNJ_DIALOGS_H
#define RNJ_DIALOGS_H

#ifdef LDIALOGS_SDL2
    #include "dialogs/sdl2.h"
#endif
#ifdef LDIALOGS_ALLEGRO5_ND
    #include "dialogs/allegro5_nd.h"
#endif
#ifdef LDIALOGS_WINDOWS_H
    #include "dialogs/windows_h.h"
#endif
#ifdef LDIALOGS_NATIVE
    #include "dialogs/native.h"
#endif
#ifdef LDIALOGS_DUMMY
    #include "dialogs/dummy.h"
#endif

#endif
