#ifndef RNJ_SCREEN_H
#define RNJ_SCREEN_H

#ifdef LSCREEN_SDL12
    #include "screen/sdl12.h"
#endif
#ifdef LSCREEN_SDL2
    #include "screen/sdl2.h"
#endif
#ifdef LSCREEN_ALLEGRO42
    #include "screen/allegro42.h"
#endif
#ifdef LSCREEN_ALLEGRO5
    #include "screen/allegro5.h"
#endif

#endif
