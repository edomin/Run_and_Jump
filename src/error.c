#include "error.h"

void ErrorGive(char *message, int level)
{
    LogWrite(message, level, MT_ERROR, NULL);
    DialogsShowSimpleMessageBox(1, "Error", message);
}
