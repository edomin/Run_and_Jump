#include "timer/allegro5.h"

void InitTimer(void)
{
    LogWrite("Initializing timer", 0, MT_INFO, NULL);
    srand(time(NULL));
    LogWrite("Timer initialized", 1, MT_INFO, NULL);
}

void TimerStart(void)
{
    Timer.startTime = al_get_time() * 1000;
}

int TimerGetTicks(void)
{
    return al_get_time() * 1000 - Timer.startTime;
}

int TimerDelay(int ms)
{
    al_rest(ms / 1000);
    return ONE_SECOND / (TimerGetTicks());
}

int TimerDelayForFPS(int fps)
{
    if(TimerGetTicks() < ONE_SECOND / fps)
    {
        /* Sleep the remaining frame time */
        al_rest(((ONE_SECOND / fps) - TimerGetTicks()) / 1000);
        return fps;
    }
    else
    {
        return ONE_SECOND / (TimerGetTicks());
    }
}
