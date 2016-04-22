#include "dialogs/windows_h.h"

void DialogsShowSimpleMessageBox(int type, char *title, char *message)
{
    switch (type)
    {
        case DIALOG_TYPE_ERROR: /* error */
        {
            MessageBox(0, message, title, MB_OK | MB_ICONERROR | MB_TASKMODAL);
            break;
        }
        case DIALOG_TYPE_WARNING: /* warning */
        {
            MessageBox(0, message, title, MB_OK | MB_ICONWARNING | MB_TASKMODAL);
            break;
        }
        case DIALOG_TYPE_INFO: /* info */
        {
            MessageBox(0, message, title, MB_OK | MB_ICONINFORMATION | MB_TASKMODAL);
            break;
        }
    }
}

bool DialogsShowYesNoMessageBox(char *title, char *message)
{
    switch (MessageBox(0, message, title, MB_YESNO | MB_ICONQUESTION | MB_TASKMODAL))
    {
    	case IDYES:
    	{
    		return true;
    		break;
    	}
    	case IDNO:
    	{
    		return false;
    		break;
    	}
    }
    return false;
}


