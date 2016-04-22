#ifndef RNJ_PHYSICS_ODE_H
#define RNJ_PHYSICS_ODE_H

#include "log.h"

#include "defines.h"

#define dSINGLE
#include "ode/ode.h"

/* ��������� ��������� - ���� */
typedef struct {
    dGeomID geom; /* ��������� */
    /* �������� ��� ����������� (������ ������) */
    double x; /* ���������� */
    double y; /* ���������� */
    double width; /* ������� */
    double height; /* ������� */
} staticGeom;

/* ���������� ���� - ������ */
typedef struct {
    dGeomID geom; /* ��������� */
    dBodyID body; /* ���� */
    dMass mass; /* ����� */
    /* �������� ��� ����������� (������ ������). ����������� ���������� PhysicsBodyRefreshStats() */
    double x; /* ���������� */
    double y; /* ���������� */
    double width; /* ������� */
    double height; /* ������� */
    double weight; /* ����� */
    double angle; /* ���� �������� */
} tbody;

struct physics {
    dWorldID world; /* ����� ��� */
    dSpaceID space; /* ����� ������������ */
    dJointGroupID jointGroup; /* ����� ������ ����� ��������������� */
    staticGeom *block; /* ������ ����������� ��������� */
    tbody *object; /* ������ ���������� ��� */
    int blocksCount; /* ������� ����������� ��������� */
    int objectsCount; /* ������� ���������� ��� */
    dReal stepSize; /* ����� ���� ��������� */
} Physics;

void PhysicsInit(dReal, dReal, dReal, dReal, int, int);
void PhysicsDestroy(void);
int PhysicsPlaceBlock(dReal, dReal, dReal, dReal);
int PhysicsPlaceObject(dReal, dReal, dReal, dReal, dReal);
void PhysicsStep(void);
void PhysicsBodyRefreshStats(int);

#endif

