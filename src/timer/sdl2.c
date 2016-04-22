#include "timer/sdl2.h"

void InitTimer(void)
{
	LogWrite("Initializing timer", 0, MT_INFO, NULL);
	srand(time(NULL));
	if (SDL_InitSubSystem(SDL_INIT_TIMER) == 0) /* Инициализируем таймер */
    {
        LogWrite("Timer initialized", 1, MT_INFO, NULL);
    }
    else
    {
        ErrorGive("Can not initialize Timer", 1);
    }
}

void TimerStart(void)
{
    Timer.startTime = SDL_GetTicks();
}

int TimerGetTicks(void)
{
    return SDL_GetTicks() - Timer.startTime;
}

int TimerDelay(int ms)
{
    SDL_Delay(ms);
    return ONE_SECOND / TimerGetTicks();
}

int TimerDelayForFPS(int fps)
{
    if(TimerGetTicks() < ONE_SECOND / fps)
    {
        /* Sleep the remaining frame time */
        SDL_Delay((ONE_SECOND / fps) - TimerGetTicks());
        return fps;
    }
    else
    {
        return ONE_SECOND / TimerGetTicks();
    }
}

