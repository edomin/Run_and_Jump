#include "physics/ode.h"

/* Инициализация */
void PhysicsInit(dReal xGrav, dReal yGrav, dReal cfm, dReal stepSize,
                 int blocks, int objects)
{
    LogWrite("Initializing Physics Subsystem", 0, MT_INFO, NULL);
    /* Инициализация ОДЕ */
    dInitODE();
    /* Создание общего мира */
    Physics.world = dWorldCreate();
    /* Создание общего пространства */
    Physics.space = dHashSpaceCreate(PHYS_SPACE_NONE);
    /* Установка графитации */
    dWorldSetGravity(Physics.world, xGrav, yGrav, ZAXIS_COORD);
    /* Установка жесткости соединений */
    dWorldSetCFM(Physics.world, cfm);
    /* Создание общей группы контактов */
    Physics.jointGroup = dJointGroupCreate(PHYS_JOINT_MAX_SIZE);
    /* Инициализация структур блоков и объектов */
    Physics.blocksCount = 0;
    Physics.block = malloc(sizeof(staticGeom) * blocks);
    Physics.objectsCount = 0;
    Physics.object = malloc(sizeof(tbody) * objects);
    /* Установка длины шага симуляции */
    Physics.stepSize = stepSize;
    LogWrite("Physics Subsystem initialized", 0, MT_INFO, NULL);
}

/* Уничтожение */
void PhysicsDestroy(void)
{
    LogWrite("Destroying Physics Subsystem", 0, MT_INFO, NULL);
    int i;
    /* Уничтожение объектов */
    for (i = 0; i < Physics.objectsCount; i++)
    {
        dBodyDestroy(Physics.object[i].body);
        dGeomDestroy(Physics.object[i].geom);
        LogWrite("Object Destroyed", 1, MT_INFO, NULL);
    }
    /* Уничтожение блоков */
    for (i = 0; i < Physics.blocksCount; i++)
    {
        dGeomDestroy(Physics.block[i].geom);
        LogWrite("Block Destroyed", 1, MT_INFO, NULL);
    }
    /* Освобождение памяти массивов блоков и объектов */
    free(Physics.block);
    free(Physics.object);
    dSpaceDestroy(Physics.space); /* Уничтожение обзего пространства */
    dWorldDestroy(Physics.world); /* Уничтожение Обзего мира */
    dCloseODE(); /* Деинициалзация ОДЕ */
    LogWrite("Physics Subsystem Destroyed", 0, MT_INFO, NULL);
}

/* Добавление блока */
int PhysicsPlaceBlock(dReal x, dReal y, dReal width, dReal height)
{
    /* Создаем геометрию (пока только квадрат) */
    Physics.block[Physics.blocksCount].geom = dCreateBox(Physics.space, width,
                                                         height, ZAXIS_LENGTH);
    /* Устанавливаем позицию геометрии */
    dGeomSetPosition(Physics.block[Physics.blocksCount].geom, x, y,
                     ZAXIS_COORD);
    /* Заполняем данные для чтения */
    Physics.block[Physics.blocksCount].width = (double)width;
    Physics.block[Physics.blocksCount].height = (double)height;
    Physics.block[Physics.blocksCount].x = (double)x;
    Physics.block[Physics.blocksCount].y = (double)y;
    Physics.blocksCount += 1;
    LogWrite("Block Created", 0, MT_INFO, NULL);
    return Physics.blocksCount - 1;
}

/* Добавление объекта */
int PhysicsPlaceObject(dReal x, dReal y, dReal width, dReal height, dReal mass)
{
    /* Создаем тело объекта */
    Physics.object[Physics.objectsCount].body = dBodyCreate(Physics.world);
    /* Инициализируем массу */
    dMassSetZero(&Physics.object[Physics.objectsCount].mass);
    /* Распределяем массу для квадрата */
    dMassSetBoxTotal(&Physics.object[Physics.objectsCount].mass, mass, width,
                     height, ZAXIS_LENGTH);
    /* станавливаем распределенную массу телу */
    dBodySetMass(Physics.object[Physics.objectsCount].body,
                 &Physics.object[Physics.objectsCount].mass);
    /* Устанавливаем позицию тела */
    dBodySetPosition(Physics.object[Physics.objectsCount].body, x, y,
                     ZAXIS_COORD);
    /* Создаем геометрию (пока только квадрат) */
    Physics.object[Physics.objectsCount].geom = dCreateBox(Physics.space,
                                                           width, height,
                                                           ZAXIS_LENGTH);
    /* Сопоставляем тело и геометрию */
    dGeomSetBody(Physics.object[Physics.objectsCount].geom,
                 Physics.object[Physics.objectsCount].body);

    /* Заполняем данные для чтения */
    Physics.object[Physics.objectsCount].width = (double)width;
    Physics.object[Physics.objectsCount].height = (double)height;
    Physics.object[Physics.objectsCount].x = (double)x;
    Physics.object[Physics.objectsCount].y = (double)y;
    Physics.object[Physics.objectsCount].weight = (double)mass;
    Physics.objectsCount += 1;
    LogWrite("Object Created", 0, MT_INFO, NULL);
    return Physics.objectsCount - 1;
}

/* Функция обработки столкновений */
void PhysicsCollide(void* data, dGeomID o1, dGeomID o2)
{
    /* Я хз, как это работает. Выдрал кусок кода из интернета */
    dBodyID b1 = dGeomGetBody(o1);
    dBodyID b2 = dGeomGetBody(o2);
    dContact contacts[PHYS_MAX_CONTACTS];
    int i, numc;
    numc = dCollide(o1, o2, PHYS_MAX_CONTACTS, &contacts[0].geom,
                    sizeof(dContact));
    if (numc)
    {
        for (i = 0; i < numc; i++)
        {
            contacts[i].surface.mode = dContactSlip1 | dContactSlip2 | dContactSoftERP | dContactSoftCFM | dContactApprox1;
            contacts[i].surface.mu = dInfinity;
            contacts[i].surface.slip1 = 0.1;
            contacts[i].surface.slip2 = 0.1;
            contacts[i].surface.soft_erp = 0.5;
            contacts[i].surface.soft_cfm = 0.0;
            dJointID c = dJointCreateContact(Physics.world, Physics.jointGroup,
                                             &contacts[i]);
            dJointAttach(c, b1, b2);
        }
    }
}

/* Итерация мира */
void PhysicsStep(void)
{
    /* Проверяем столкновения. Хз как работает */
    dSpaceCollide(Physics.space, PHYS_COLLIDE_DATA, &PhysicsCollide);
    /* Выполняем шаг итерации */
    dWorldStep(Physics.world, Physics.stepSize);
    /* Освобождаем группу точек контактов, которая заполнялась функцией
       PhysicsCollide() */
    dJointGroupEmpty(Physics.jointGroup);
}

/* Обновление данных о положении объекта */
void PhysicsBodyRefreshStats(int object)
{
    /* Хз как работает. Выдрал кусок кода из интернета. Вобщем массив a - это
       вектор положения в пространстве, из него достаются координаты. a n - это
       матрица поворота, она каким-то чудом преобразовывется в угол поворота
       относительно оси Z */
    const dReal *a = dBodyGetPosition(Physics.object[object].body);
    const dReal *an = dBodyGetRotation(Physics.object[object].body);
    if (an[8] < 1 - 0.0000001 && an[8] > -1 + 0.0000001)
    {
        Physics.object[object].angle = atan2(an[4] / (cos(-asin(an[8]))),
                                             an[0] / (cos(-asin(an[8]))));
    }
    else
    {
        Physics.object[object].angle = (int)0;
    }
    Physics.object[object].x = (int)a[0];
    Physics.object[object].y = (int)a[1];
}

