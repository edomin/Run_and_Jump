#include "app/allegro42.h"

void close_button_handler(void)
{
    App.xed = true;
}
END_OF_FUNCTION(close_button_handler)

void AppInit(void)
{
    LogWrite("Initializing application", 0, MT_INFO, NULL);
    LogWrite("Initializing Allegro", 1, MT_INFO, NULL);

    LogWrite("Checking Allegro compile-time version", 1, MT_INFO, NULL);
    LogWrite2("Major:", 2, MT_INFO, ALLEGRO_VERSION);
    LogWrite2("Middle:", 2, MT_INFO, ALLEGRO_SUB_VERSION);
    LogWrite2("Minor:", 2, MT_INFO, ALLEGRO_WIP_VERSION);

    if (allegro_init() == 0) /* Инициализируем Allegro */
    {
        LogWrite("Allegro initialized", 1, MT_INFO, NULL);
    }
    else
    {
        ErrorGive("Can not initialize Allegro", 1);
    }

	//App.eq = al_create_event_queue();

    App.quit = false;
    App.xed = false;

    LogWrite("Installing close button callback function", 1, MT_INFO, NULL);
    LOCK_FUNCTION(close_button_handler);
    if(set_close_button_callback(close_button_handler) == 0)
    {
        LogWrite("Close button callback function installed", 1, MT_INFO, NULL);
    }
    else
    {
        LogWrite("Can not install close button callback function", 1, MT_WARNING, NULL);
    }

    LogWrite("Application initialized", 0, MT_INFO, NULL);
}

void AppDestroy(void)
{
//    LogWrite("Destroying application", 0, MT_INFO, NULL);
//    LogWrite("Quiting Allegro", 1, MT_INFO, NULL);
    //al_uninstall_system();

    LogWrite("Application destroyed", 0, MT_INFO, NULL);
}

bool AppXed(void)
{
    if (App.xed)
    {
        LogWrite("Application window was Xed", 0, MT_INFO, NULL);
        return true;
    }
    else
    {
        return false;
    }
}
