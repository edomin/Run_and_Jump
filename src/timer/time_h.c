#include "timer/time_h.h"

void InitTimer(void)
{
    LogWrite("Initializing timer", 0, MT_INFO, NULL);
    srand(time(NULL));
    LogWrite("Timer initialized", 0, MT_INFO, NULL);
}

void TimerStart(void)
{
    Timer.startTime = clock() * 1000 / CLOCKS_PER_SEC;
}

int TimerGetTicks(void)
{
    return clock() * 1000 / CLOCKS_PER_SEC - Timer.startTime;
}

void TimerSleep(unsigned int mseconds)
{
    uint32_t goal = clock() * 1000 / CLOCKS_PER_SEC + mseconds;
    while (goal > clock() * 1000 / CLOCKS_PER_SEC);
}

int TimerDelay(int ms)
{
    TimerSleep(ms);
    return ONE_SECOND / TimerGetTicks();
}

int TimerDelayForFPS(int fps)
{
    if(TimerGetTicks() < ONE_SECOND / fps)
    {
        /* Sleep the remaining frame time */
        TimerSleep((ONE_SECOND / fps) - TimerGetTicks());
        return fps;
    }
    else
    {
        return ONE_SECOND / TimerGetTicks();
    }
}


