#include "dialogs/sdl2.h"

void DialogsShowSimpleMessageBox(int type, char *title, char *message)
{
    switch (type)
    {
        case DIALOG_TYPE_ERROR: /* error */
        {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, title, message, Screen.window);
            break;
        }
        case DIALOG_TYPE_WARNING: /* warning */
        {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, title, message, Screen.window);
            break;
        }
        case DIALOG_TYPE_INFO: /* info */
        {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, title, message, Screen.window);
            break;
        }
    }
}

bool DialogsShowYesNoMessageBox(char *title, char *message)
{
    SDL_MessageBoxData data;
	SDL_MessageBoxButtonData *buttons;
	int buttonID;
	int result;

	buttons = malloc(sizeof(SDL_MessageBoxButtonData) * 2);

	data.window = Screen.window;
	data.title = title;
	data.message = message;
	data.numbuttons = 2;
	data.buttons = buttons;
	data.flags = SDL_MESSAGEBOX_WARNING;

	buttons[1].buttonid = 0;
	buttons[1].text = "Yes";
	buttons[0].buttonid = 1;
	buttons[0].text = "No";

    result = SDL_ShowMessageBox(&data, &buttonID);
    if (result == -1)
    {
    	return false;
    }
    else
    {
    	if (buttonID == 0)
			return true;
		else
			return false;
    }
}
