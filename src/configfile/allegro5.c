#include "configfile/allegro5.h"

void ConfigfileCreateConfig(void)
{
	if (Configfile.config != NULL)
	{
		al_destroy_config(Configfile.config);
		Configfile.config = NULL;
	}
	Configfile.config = al_create_config();
}

void ConfigfileLoadConfig(char *filename)
{
	if (Configfile.config != NULL)
	{
		al_destroy_config(Configfile.config);
		Configfile.config = NULL;
	}
	Configfile.config = al_load_config_file((const char *)filename);
}

void ConfigfileSaveConfig(char *filename)
{
	if (Configfile.config != NULL)
	{
		al_save_config_file((const char *)filename, (const ALLEGRO_CONFIG *)Configfile.config);
	}
}

void ConfigfileAddSection(char *sectionName)
{
	if (Configfile.config != NULL)
	{
		al_add_config_section(Configfile.config, (const char *)sectionName);
	}
}

void ConfigfileSetKeyValue(char *sectionName, char *key, char *value)
{
	if (Configfile.config != NULL)
	{
		al_set_config_value(Configfile.config, (const char *)sectionName, (const char *)key, (const char *)value);
	}
}

char *ConfigfileGetKeyValue(char *sectionName, char *key)
{
	if (Configfile.config != NULL)
	{
		return (char *)al_get_config_value((const ALLEGRO_CONFIG *)Configfile.config, (const char *)sectionName, (const char *)key);
	}
	else
	{
		return NULL;
	}
}
