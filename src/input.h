#ifndef RNJ_INPUT_H
#define RNJ_INPUT_H

#ifdef LINPUT_SDL12
    #include "input/sdl12.h"
#endif
#ifdef LINPUT_SDL2
    #include "input/sdl2.h"
#endif
#ifdef LINPUT_ALLEGRO5
    #include "input/allegro5.h"
#endif
#ifdef LINPUT_NATIVE
    #include "input/native.h"
#endif
#ifdef LINPUT_DUMMY
    #include "input/dummy.h"
#endif

#endif
