#ifndef RNJ_DIALOGS_NATIVE_H
#define RNJ_DIALOGS_NATIVE_H

/* В данный момент модуль только для KolibriOS */

#include BOOLLIB

#include "defines.h"
#include "log.h"

//struct {
//	Uint8 dialogStack[1024];
//} Dialogs;

void kolibrios_DialogThread(void);

void DialogsShowSimpleMessageBox(int, char *, char *);
bool DialogsShowYesNoMessageBox(char *, char *);

#endif

