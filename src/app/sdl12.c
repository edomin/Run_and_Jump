#include "app/sdl12.h"

void AppInit(void)
{
    SDL_version ctVersion;
    const SDL_version *dllVersion;

    LogWrite("Initializing application", 0, MT_INFO, NULL);

	SDL_VERSION(&ctVersion)
    LogWrite("Checking SDL compile-time version", 1, MT_INFO, NULL);
    LogWrite2("Major:", 2, MT_INFO, ctVersion.major);
    LogWrite2("Minor:", 2, MT_INFO, ctVersion.minor);
    LogWrite2("Patch:", 2, MT_INFO, ctVersion.patch);

    dllVersion = SDL_Linked_Version();
    LogWrite("Checking SDL linked version", 1, MT_INFO, NULL);
    LogWrite2("Major:", 2, MT_INFO, dllVersion->major);
    LogWrite2("Minor:", 2, MT_INFO, dllVersion->minor);
    LogWrite2("Patch:", 2, MT_INFO, dllVersion->patch);

    LogWrite("Initializing SDL", 1, MT_INFO, NULL);
    if (SDL_Init(SDL_INIT_EVENTTHREAD) == 0) /* Инициализируем SDL */
    {
        LogWrite("SDL initialized", 1, MT_INFO, NULL);
    }
    else
    {
        ErrorGive("Can not initialize SDL", 1);
    }
    App.quit = false;
    LogWrite("Application initialized", 0, MT_INFO, NULL);
}

void AppDestroy(void)
{
    LogWrite("Destroying application", 0, MT_INFO, NULL);
    LogWrite("Quiting SDL", 1, MT_INFO, NULL);
    SDL_Quit();

    LogWrite("Application destroyed", 0, MT_INFO, NULL);
}

bool AppXed(void)
{
    SDL_PollEvent(&App.event);
    if(App.event.type == SDL_QUIT)
    {
        LogWrite("Application window was Xed", 0, MT_INFO, NULL);
        return true;
    }
    else
    {
        return false;
    }
}



