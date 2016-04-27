#include "physics/dummy.h"

/* Инициализация */
void PhysicsInit(double xGrav, double yGrav, double cfm, double stepSize,
                 int blocks, int objects)
{
    ;
}

/* Уничтожение */
void PhysicsDestroy(void)
{
    ;
}

/* Добавление блока */
int PhysicsPlaceBlock(double x, double y, double width, double height)
{
    return 0;
}

/* Добавление объекта */
int PhysicsPlaceObject(double x, double y, double width, double height,
                       double mass)
{
    return 0;
}

// /* Функция обработк столкновений */
//void PhysicsCollide(void* data, dGeomID o1, dGeomID o2)
//{
//     Я хз, как это работает. Выдрал Ѓсок кода из интернета */
//    dBodyID b1 = dGeomGetBody(o1);
//    dBodyID b2 = dGeomGetBody(o2);
//    dContact contacts[PHYS_MAX_CONTACTS];
//    int i, numc;
//    numc = dCollide(o1, o2, PHYS_MAX_CONTACTS, &contacts[0].geom, sizeof(dContact));
//    if (numc)
//    {
//        for (i = 0; i < numc; i++)
//        {
//            contacts[i].surface.mode = dContactSlip1 | dContactSlip2 | dContactSoftERP | dContactSoftCFM | dContactApprox1;
//            contacts[i].surface.mu = dInfinity;
//            contacts[i].surface.slip1 = 0.1;
//            contacts[i].surface.slip2 = 0.1;
//            contacts[i].surface.soft_erp = 0.5;
//            contacts[i].surface.soft_cfm = 0.0;
//            dJointID c = dJointCreateContact(Physics.world, Physics.jointGroup, &contacts[i]);
//            dJointAttach(c, b1, b2);
//        }
//    }
//}

/* Итерация мира */
void PhysicsStep(void)
{
    ;
}

/* Обновление данных о положении объекта */
void PhysicsBodyRefreshStats(int object)
{
    ;
}


