#ifndef RNJ_CONFIGFILE_INIPARSER_H
#define RNJ_CONFIGFILE_INIPARSER_H

#include <iniparser.h>
/* #include "dictionary.h" */

#include "files.h"

struct {
    dictionary *config;
} Configfile;

void ConfigfileCreateConfig(void);
void ConfigfileLoadConfig(char *);
void ConfigfileSaveConfig(char *);
void ConfigfileAddSection(char *);
void ConfigfileSetKeyValue(char *, char *, char *);
char *ConfigfileGetKeyValue(char *, char *);

#endif

