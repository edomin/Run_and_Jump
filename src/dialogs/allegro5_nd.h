#ifndef RNJ_DIALOGS_ALLEGRO5_ND_H
#define RNJ_DIALOGS_ALLEGRO5_ND_H

#include <allegro5/allegro_native_dialog.h>
#include BOOLLIB
#include "defines.h"

#include "screen.h"

void DialogsShowSimpleMessageBox(int, char *, char *);
bool DialogsShowYesNoMessageBox(char *, char *);

#endif
