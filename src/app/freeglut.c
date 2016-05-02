#include "app/freeglut.h"

void AppInit(void)
{
    int fake_argc;
    char *fake_argv[1];

    fake_argc = 1;
    fake_argv[0] = "nothing";

    glutInit(&fake_argc, fake_argv);
    App.quit = false;
}

void AppDestroy(void)
{
    // LogWrite("Destroying application", 0, MT_INFO, NULL);
    // LogWrite("Quiting SDL", 1, MT_INFO, NULL);
    // SDL_Quit();

    // LogWrite("Application destroyed", 0, MT_INFO, NULL);
}

bool AppXed(void)
{
    // SDL_PollEvent(&App.event);
    // if(App.event.type == SDL_QUIT)
    // {
        // LogWrite("Application window was Xed", 0, MT_INFO, NULL);
        // return true;
    // }
    // else
    // {
        return false;
    // }
}
