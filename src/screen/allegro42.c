#include "screen/allegro42.h"

void ScreenInit(int w, int h, const char *title, bool fullscreen)
{
//    int i;
//    int j;
//    ALLEGRO_DISPLAY_MODE mode;
//
//	LogWrite("Checking available display modes", 0, MT_INFO, NULL);
//    i = al_get_num_display_modes();
//    if (i < 0)
//    {
//    	LogWrite("Can not check available display modes", 0, MT_WARNING, NULL);
//    }
//    else
//    {
//		LogWrite2("Modes found", 0, MT_INFO, i);
//		for (j = 0; j < i; j++)
//		{
//			al_get_display_mode(j, &mode);
//			LogWrite2("No.", 1, MT_INFO, j);
//			LogWrite2("Width:", 2, MT_INFO, mode.width);
//			LogWrite2("Height:", 2, MT_INFO, mode.height);
//			LogWrite2("Pixel Format No.:", 2, MT_INFO, mode.format);
//			LogWrite2("Refresh Rate:", 2, MT_INFO, mode.refresh_rate);
//		}
//    }

    LogWrite("Initializing Screen", 0, MT_INFO, NULL);
    Screen.width = w;
    Screen.height = h;
//    Screen.window = NULL;

    LogWrite("Setting screen resolution", 1, MT_INFO, NULL);
    set_color_depth(32);
    if (set_gfx_mode(GFX_AUTODETECT, w, h, w, h) != 0)
    {
        ErrorGive("Can not set screen resolution", 1);
    }
    else
    {
        LogWrite("Screen resolution set.", 1, MT_INFO, NULL);
    }

//	LogWrite("Creating Window", 1, MT_INFO, NULL);
//    if (!fullscreen)
//	{
//		al_set_new_display_flags(ALLEGRO_WINDOWED);
//	}
//    else
//    {
//    	al_set_new_display_flags(ALLEGRO_FULLSCREEN);
//    }
//    Screen.window = al_create_display(w, h);
//	if(Screen.window)
//	{
//		LogWrite("Window Created.", 1, MT_INFO, NULL);
//	}
//	else
//	{
//		ErrorGive("Can not create window", 1);
//	}
//	al_set_window_title(Screen.window, title);
//
	Screen.hwnd = win_get_window();
//
//	al_register_event_source(App.eq, al_get_display_event_source(Screen.window));

    LogWrite("Screen initialized", 0, MT_INFO, NULL);
}

void ScreenDestroy(void)
{
//    al_set_target_bitmap(NULL);
//    al_destroy_display(Screen.window);
    LogWrite("Window destroyed", 0, MT_INFO, NULL);
}

void ScreenCursorShow(void)
{
//     show_os_cursor(MOUSE_CURSOR_ARROW);
}

void ScreenCursorHide(void)
{
//    show_os_cursor(MOUSE_CURSOR_NONE);
}


