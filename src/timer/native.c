#include "timer/native.h"

uint32_t kolibrios_GetTicks(void)
{
    uint32_t s100;
    __asm__ __volatile__(
    "int $0x40"
    :"=a"(s100)
    :"a"(26),"b"(9)
    :"memory");

    return s100 * 10;
};

void kolibrios_Delay(uint32_t ms)
{
    uint32_t s100;
    s100 = (uint32_t)floor((double)(ms / 10));
    if (s100 > 0)
    {
        __asm__ __volatile__(
        "int $0x40"
        :
        :"a"(5),"b"(s100)
        :"memory");
    }
}

unsigned int kolibrios_Time(void)
{
    uint32_t kos_time;
    __asm__ __volatile__(
    "int $0x40"
    :"=a"(kos_time)
    :"a"(3)
    :"memory");

    return (unsigned int)kos_time;
};

void InitTimer(void)
{
    LogWrite("Initializing timer", 0, MT_INFO, NULL);
    srand(kolibrios_Time());
    LogWrite("Timer initialized", 1, MT_INFO, NULL);
}

void TimerStart(void)
{
    Timer.startTime = kolibrios_GetTicks();
}

int TimerGetTicks(void)
{
    return kolibrios_GetTicks() - Timer.startTime;
}

int TimerDelay(int ms)
{
    kolibrios_Delay(ms);
    return ONE_SECOND / TimerGetTicks();
}

int TimerDelayForFPS(int fps)
{
    int ticks;
    ticks = TimerGetTicks();
    if(ticks < ONE_SECOND / fps)
    {
        /* Sleep the remaining frame time */
        kolibrios_Delay((ONE_SECOND / fps) - ticks);
        return fps;
    }
    else
    {
        return ONE_SECOND / ticks;
    }
}
