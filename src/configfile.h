#ifndef RNJ_CONFIGFILE_H
#define RNJ_CONFIGFILE_H

#ifdef LCONFIGFILE_ALLEGRO5
    #include "configfile/allegro5.h"
#endif
#ifdef LCONFIGFILE_INIPARSER
    #include "configfile/iniparser.h"
#endif
#ifdef LCONFIGFILE_DUMMY
    #include "configfile/dummy.h"
#endif

#endif
