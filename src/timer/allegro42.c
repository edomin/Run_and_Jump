#include "timer/allegro42.h"

void TimerMsIncrementer()
{
    Timer.ms++;
}

void InitTimer(void)
{
    LogWrite("Initializing timer", 0, MT_INFO, NULL);
    LogWrite("Installing Allegro timer interrupt handler", 0, MT_INFO, NULL);
    if (install_timer() == 0)
        LogWrite("Allegro timer interrupt handler installed", 1, MT_INFO, NULL);
    else
        ErrorGive("Unable to install Allegro timer interrupt handler", 1);
    LogWrite("Installing milisecond incrementer handler", 0, MT_INFO, NULL);
    if (install_int(TimerMsIncrementer, 1) == 0)
        LogWrite("Milisecond incrementer handler installed", 1, MT_INFO, NULL);
    else
        ErrorGive("Unable to install milisecond incrementer handler", 1);
    srand(time(NULL));
    LogWrite("Timer initialized", 0, MT_INFO, NULL);
}

int TimerGetTime()
{
    return Timer.ms;
}

void TimerStart(void)
{
    Timer.startTime = TimerGetTime();
}

int TimerGetTicks(void)
{
    return TimerGetTime() - Timer.startTime;
}

int TimerDelay(int ms)
{
    rest(ms);
    return ONE_SECOND / (TimerGetTicks());
}

int TimerDelayForFPS(int fps)
{
    if(TimerGetTicks() < ONE_SECOND / fps)
    {
        /* Sleep the remaining frame time */
        rest((ONE_SECOND / fps) - TimerGetTicks());
        return fps;
    }
    else
    {
        return ONE_SECOND / (TimerGetTicks());
    }
}
