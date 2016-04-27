#ifndef RNJ_PHYSICS_ODE_H
#define RNJ_PHYSICS_ODE_H

#include "log.h"

#include "defines.h"

#define dSINGLE
#include "ode/ode.h"

/* Статичная геометрия - блок */
typedef struct {
    dGeomID geom;   /* геометрия */
    /* Значения для отображения (только чтение) */
    double  x;      /* координаты */
    double  y;      /* координаты */
    double  width;  /* размеры */
    double  height; /* размеры */
} staticGeom;

/* Физическое тело - объект */
typedef struct {
    dGeomID geom;   /* геометрия */
    dBodyID body;   /* тело */
    dMass   mass;   /* масса */
    /* Значения для отображения (только чтение). Заполняются процедурой
       PhysicsBodyRefreshStats() */
    double  x;      /* координаты */
    double  y;      /* координаты */
    double  width;  /* размеры */
    double  height; /* размеры */
    double  weight; /* масса */
    double  angle;  /* угол поворота */
} tbody;

struct physics {
    dWorldID        world;      /* общий мир */
    dSpaceID        space;      /* общее пространство */
    dJointGroupID   jointGroup; /* общая группа точек соприкосновения */
    staticGeom *    block;      /* массив статических геометрий */
    tbody *         object;     /* массив физических тел */
    int             blocksCount;/* счетчик статических геометрий */
    int             objectsCount;/* счетчик физических тел */
    dReal           stepSize;   /* длина шага симуляции */
} Physics;

void PhysicsInit(dReal, dReal, dReal, dReal, int, int);
void PhysicsDestroy(void);
int PhysicsPlaceBlock(dReal, dReal, dReal, dReal);
int PhysicsPlaceObject(dReal, dReal, dReal, dReal, dReal);
void PhysicsStep(void);
void PhysicsBodyRefreshStats(int);

#endif

