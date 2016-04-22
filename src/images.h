#ifndef RNJ_IMAGES_H
#define RNJ_IMAGES_H

#ifdef LIMAGES_FREEIMAGE
    #include "images/freeimage.h"
#endif
#ifdef LIMAGES_SDL2_IMAGE
    #include "images/sdl2_image.h"
#endif
#ifdef LIMAGES_ALLEGRO5_IMAGE
    #include "images/allegro5_image.h"
#endif
#ifdef LIMAGES_DUMMY
    #include "images/dummy.h"
#endif

#endif
