#ifndef RNJ_SPRITES_H
#define RNJ_SPRITES_H

#ifdef LSPRITES_DEVIL
    #include "sprites/devil.h"
#endif
#ifdef LSPRITES_SDL12_IMAGE
    #include "sprites/sdl12_image.h"
#endif
#ifdef LSPRITES_SDL2_IMAGE
    #include "sprites/sdl2_image.h"
#endif
#ifdef LSPRITES_ALLEGRO42
    #include "sprites/allegro42.h"
#endif
#ifdef LSPRITES_ALLEGRO5_IMAGE
    #include "sprites/allegro5_image.h"
#endif
#ifdef LSPRITES_DUMMY
    #include "sprites/dummy.h"
#endif

#endif
