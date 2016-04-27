#include "dialogs/allegro5_nd.h"

void DialogsShowSimpleMessageBox(int type, char *title, char *message)
{
    switch (type)
    {
        case DIALOG_TYPE_ERROR: /* error */
        {
            al_show_native_message_box(Screen.window, (char const *)title,
                                       (char const *)title,
                                       (char const *)message, NULL,
                                       ALLEGRO_MESSAGEBOX_ERROR);
            break;
        }
        case DIALOG_TYPE_WARNING: /* warning */
        {
            al_show_native_message_box(Screen.window, (char const *)title,
                                       (char const *)title,
                                       (char const *)message, NULL,
                                       ALLEGRO_MESSAGEBOX_WARN);
            break;
        }
        case DIALOG_TYPE_INFO: /* info */
        {
            al_show_native_message_box(Screen.window, (char const *)title,
                                       (char const *)title,
                                       (char const *)message, NULL, 0);
            break;
        }
    }
}

bool DialogsShowYesNoMessageBox(char *title, char *message)
{
    al_show_native_message_box(Screen.window, (char const *)title,
                               (char const *)title, (char const *)message,
                               NULL,
                               ALLEGRO_MESSAGEBOX_QUESTION | ALLEGRO_MESSAGEBOX_YES_NO);
    switch (MessageBox(0, message, title, MB_YESNO | MB_ICONQUESTION | MB_TASKMODAL))
    {
        case 1:
        {
            return true;
            break;
        }
        case 2:
        {
            return false;
            break;
        }
    }
    return false;
}
