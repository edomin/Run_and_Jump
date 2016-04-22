#ifndef RNJ_PHYSICS_DUMMY_H
#define RNJ_PHYSICS_DUMMY_H

#include "log.h"

#include "defines.h"

/* ��������� ��������� - ���� */
typedef struct {
    //dGeomID geom; /* ��������� */
    /* �������� ��� ����������� (������ ������) */
    double x; /* ���������� */
    double y; /* ���������� */
    double width; /* ������� */
    double height; /* ������� */
} staticGeom;

/* ���������� ���� - ������ */
typedef struct {
    //dGeomID geom; /* ��������� */
    //dBodyID body; /* ���� */
    //dMass mass; /* ����� */
    /* �������� ��� ����������� (������ ������). ����������� ���������� PhysicsBodyRefreshStats() */
    double x; /* ���������� */
    double y; /* ���������� */
    double width; /* ������� */
    double height; /* ������� */
    double weight; /* ����� */
    double angle; /* ���� �������� */
} tbody;

struct physics {
    //dWorldID world; /* ����� ��� */
    //dSpaceID space; /* ����� ������������ */
    //dJointGroupID jointGroup; /* ����� ������ ����� ��������������� */
    //staticGeom *block; /* ������ ����������� ��������� */
    //tbody *object; /* ������ ���������� ��� */
    int blocksCount; /* ������� ����������� ��������� */
    int objectsCount; /* ������� ���������� ��� */
    double stepSize; /* ����� ���� ��������� */
} Physics;

void PhysicsInit(double, double, double, double, int, int);
void PhysicsDestroy(void);
int PhysicsPlaceBlock(double, double, double, double);
int PhysicsPlaceObject(double, double, double, double, double);
void PhysicsStep(void);
void PhysicsBodyRefreshStats(int);

#endif


