#ifndef RNJ_PHYSICS_DUMMY_H
#define RNJ_PHYSICS_DUMMY_H

#include "log.h"

#include "defines.h"

/* —татична€ геометри€ - блок */
typedef struct {
    //dGeomID geom; /* геометри€ */
    /* «начени€ дл€ отображени€ (только чтение) */
    double x; /* координаты */
    double y; /* координаты */
    double width; /* размеры */
    double height; /* размеры */
} staticGeom;

/* ‘изическое тело - объект */
typedef struct {
    //dGeomID geom; /* геометри€ */
    //dBodyID body; /* тело */
    //dMass mass; /* масса */
    /* «начени€ дл€ отображени€ (только чтение). «аполн€ютс€ процедурой PhysicsBodyRefreshStats() */
    double x; /* координаты */
    double y; /* координаты */
    double width; /* размеры */
    double height; /* размеры */
    double weight; /* масса */
    double angle; /* угол поворота */
} tbody;

struct physics {
    //dWorldID world; /* общий мир */
    //dSpaceID space; /* общее пространство */
    //dJointGroupID jointGroup; /* обща€ группа точек соприкосновени€ */
    //staticGeom *block; /* массив статических геометрий */
    //tbody *object; /* массив физических тел */
    int blocksCount; /* счетчик статических геометрий */
    int objectsCount; /* счетчик физических тел */
    double stepSize; /* длина шага симул€ции */
} Physics;

void PhysicsInit(double, double, double, double, int, int);
void PhysicsDestroy(void);
int PhysicsPlaceBlock(double, double, double, double);
int PhysicsPlaceObject(double, double, double, double, double);
void PhysicsStep(void);
void PhysicsBodyRefreshStats(int);

#endif


