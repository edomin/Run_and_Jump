#ifndef RNJ_SOUNDS_H
#define RNJ_SOUNDS_H

#ifdef LSOUNDS_SDL2_MIXER
    #include "sounds/sdl2_mixer.h"
#endif
#ifdef LSOUNDS_ALLEGRO42
    #include "sounds/allegro42.h"
#endif
#ifdef LSOUNDS_DUMMY
    #include "sounds/dummy.h"
#endif

#endif
