#ifndef RNJ_DIALOGS_SDL2_H
#define RNJ_DIALOGS_SDL2_H

#include "SDL2/SDL_messagebox.h"

#include "screen.h"
#include "defines.h"

void DialogsShowSimpleMessageBox(int, char *, char *);
bool DialogsShowYesNoMessageBox(char *, char *);

#endif
