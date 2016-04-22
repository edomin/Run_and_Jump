#ifndef RNJ_FONTS_H
#define RNJ_FONTS_H

#ifdef LFONTS_SDL12_TTF
    #include "fonts/sdl12_ttf.h"
#endif
#ifdef LFONTS_SDL2_TTF
    #include "fonts/sdl2_ttf.h"
#endif
#ifdef LFONTS_ALLEGRO5
    #include "fonts/allegro5.h"
#endif
#ifdef LFONTS_DUMMY
    #include "fonts/dummy.h"
#endif

#endif
