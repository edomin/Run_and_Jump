#include "screen/allegro42.h"

void ScreenInit(int w, int h, const char *title, bool fullscreen)
{
    LogWrite("Initializing Screen", 0, MT_INFO, NULL);
    Screen.width = w;
    Screen.height = h;

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

    set_color_conversion(COLORCONV_NONE);
    Screen.hwnd = win_get_window();

    LogWrite("Screen initialized", 0, MT_INFO, NULL);
}

void ScreenDestroy(void)
{
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


