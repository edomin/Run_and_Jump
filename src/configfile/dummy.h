#ifndef RNJ_CONFIGFILE_DUMMY_H
#define RNJ_CONFIGFILE_DUMMY_H

#include <stdlib.h>

//struct {
//    dictionary *config;
//} Configfile;

void ConfigfileCreateConfig(void);
void ConfigfileLoadConfig(char *);
void ConfigfileSaveConfig(char *);
void ConfigfileAddSection(char *);
void ConfigfileSetKeyValue(char *, char *, char *);
char *ConfigfileGetKeyValue(char *, char *);

#endif


