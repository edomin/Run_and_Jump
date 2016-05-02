#ifndef RNJ_DRAW_H
#define RNJ_DRAW_H

#ifdef LDRAW_FREEGLUT
    #include "draw/freeglut.h"
#endif
#ifdef LDRAW_SDL12
    #include "draw/sdl12.h"
#endif
#ifdef LDRAW_SDL2
    #include "draw/sdl2.h"
#endif
#ifdef LDRAW_ALLEGRO42
    #include "draw/allegro42.h"
#endif
#ifdef LDRAW_ALLEGRO5
    #include "draw/allegro5.h"
#endif

#endif
