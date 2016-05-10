#ifndef RNJ_APP_H
#define RNJ_APP_H

#ifdef LAPP_FREEGLUT
    #include "app/freeglut.h"
#endif
#ifdef LAPP_SDL12
    #include "app/sdl12.h"
#endif
#ifdef LAPP_SDL2
    #include "app/sdl2.h"
#endif
#ifdef LAPP_ALLEGRO42
    #include "app/allegro42.h"
#endif
#ifdef LAPP_ALLEGRO5
    #include "app/allegro5.h"
#endif

#endif
