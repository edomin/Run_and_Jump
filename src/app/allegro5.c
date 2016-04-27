#include "app/allegro5.h"

void AppInit(void)
{
    uint32_t version;

    LogWrite("Initializing application", 0, MT_INFO, NULL);
    LogWrite("Initializing Allegro", 1, MT_INFO, NULL);

    version = al_get_allegro_version();
    LogWrite("Checking Allegro compile-time version", 1, MT_INFO, NULL);
    LogWrite2("Major:", 2, MT_INFO, version >> 24);
    LogWrite2("Minor:", 2, MT_INFO, (version >> 16) & 255);
    LogWrite2("Revision:", 2, MT_INFO, (version >> 8) & 255);
    LogWrite2("Release:", 2, MT_INFO, version & 255);

    if (al_init()) /* Инициализируем Allegro */
    {
        LogWrite("Allegro initialized", 1, MT_INFO, NULL);
    }
    else
    {
        ErrorGive("Can not initialize Allegro", 1);
    }

    App.eq = al_create_event_queue();

    App.quit = false;
    LogWrite("Application initialized", 0, MT_INFO, NULL);
}

void AppDestroy(void)
{
    LogWrite("Destroying application", 0, MT_INFO, NULL);
    LogWrite("Quiting Allegro", 1, MT_INFO, NULL);
    al_uninstall_system();

    LogWrite("Application destroyed", 0, MT_INFO, NULL);
}

bool AppXed(void)
{
    if (!al_is_event_queue_empty(App.eq))
    {
        al_get_next_event(App.eq, &App.event);
        if (App.event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            LogWrite("Application window was Xed", 0, MT_INFO, NULL);
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}


