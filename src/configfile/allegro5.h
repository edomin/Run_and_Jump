#ifndef RNJ_CONFIGFILE_ALLEGRO5_H
#define RNJ_CONFIGFILE_ALLEGRO5_H

#include <allegro5/allegro.h>

struct {
    ALLEGRO_CONFIG *config;
} Configfile;

void ConfigfileCreateConfig(void);
void ConfigfileLoadConfig(char *);
void ConfigfileSaveConfig(char *);
void ConfigfileAddSection(char *);
void ConfigfileSetKeyValue(char *, char *, char *);
char *ConfigfileGetKeyValue(char *, char *);

#endif
