#ifndef RNJ_TIMER_H
#define RNJ_TIMER_H

#ifdef LTIMER_SDL12
    #include "timer/sdl12.h"
#endif
#ifdef LTIMER_SDL2
    #include "timer/sdl2.h"
#endif
#ifdef LTIMER_ALLEGRO5
    #include "timer/allegro5.h"
#endif
#ifdef LTIMER_TIME_H
    #include "timer/time_h.h"
#endif
#ifdef LTIMER_NATIVE
    #include "timer/native.h"
#endif

#endif
