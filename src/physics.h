#ifndef RNJ_PHYSICS_H
#define RNJ_PHYSICS_H

#ifdef LPHYSICS_ODE
    #include "physics/ode.h"
#endif
#ifdef LPHYSICS_DUMMY
    #include "physics/dummy.h"
#endif

#endif
