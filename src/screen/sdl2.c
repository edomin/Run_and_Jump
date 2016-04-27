#include "screen/sdl2.h"

void ScreenInit(int w, int h, const char *title, bool fullscreen)
{
    int i;
    int j;
    SDL_DisplayMode mode;
    SDL_SysWMinfo sdlinfo;
    SDL_version sdlver;
    /* Находим все доступные режимы дисплея */
    LogWrite("Checking available display modes", 0, MT_INFO, NULL);
    i = SDL_GetNumDisplayModes(0);
    if (i < 0)
    {
        LogWrite("Can not check available display modes", 0, MT_WARNING, NULL);
    }
    else
    {
        LogWrite2("Modes found", 0, MT_INFO, i);
        for (j = 0; j < i; j++)
        {
            SDL_GetDisplayMode(0, j, &mode);
            LogWrite2("No.", 1, MT_INFO, j);
            LogWrite2("Width:", 2, MT_INFO, mode.w);
            LogWrite2("Height:", 2, MT_INFO, mode.h);
            LogWrite2("Pixel Format No.:", 2, MT_INFO, mode.format);
            LogWrite2("Refresh Rate:", 2, MT_INFO, mode.refresh_rate);
        }
    }
    LogWrite("Initializing Screen", 0, MT_INFO, NULL);
    Screen.width = w;
    Screen.height = h;
    Screen.window = NULL;
    LogWrite("Initializing Video", 1, MT_INFO, NULL);
    if(SDL_InitSubSystem(SDL_INIT_VIDEO) == 0)
    {
        LogWrite("Video initialized", 1, MT_INFO, NULL);
    }
    else
    {
        ErrorGive("Can not initialize Video", 1);
    }
    if (!fullscreen)
        Screen.window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED,
                                         SDL_WINDOWPOS_UNDEFINED, w, h,
                                         SDL_WINDOW_OPENGL);
    else
        Screen.window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED,
                                         SDL_WINDOWPOS_UNDEFINED, w, h,
                                         SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN);

    #ifdef PLATFORM_WIN32
    SDL_VERSION(&sdlver);
    sdlinfo.version = sdlver;
    SDL_GetWindowWMInfo(Screen.window, &sdlinfo);
    Screen.hwnd = sdlinfo.info.win.window;
    #endif
    if(Screen.window != 0)
        LogWrite("Window created", 1, MT_INFO, NULL);
    else
        ErrorGive("Can not create window", 1);
    LogWrite("Screen initialized", 0, MT_INFO, NULL);
}

void ScreenDestroy(void)
{
    SDL_DestroyWindow(Screen.window);
    LogWrite("Window destroyed", 0, MT_INFO, NULL);
}

void ScreenCursorShow(void)
{
    SDL_ShowCursor(1);
}

void ScreenCursorHide()
{
    SDL_ShowCursor(0);
}

