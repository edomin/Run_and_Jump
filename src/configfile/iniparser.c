#include "configfile/iniparser.h"

void ConfigfileCreateConfig(void)
{
	if (Configfile.config != NULL)
	{
		iniparser_freedict(Configfile.config);
		Configfile.config = NULL;
	}
	FileOpenForWrite("config.tmp");
	FileClose();
	Configfile.config = iniparser_load("config.tmp");
}

void ConfigfileLoadConfig(char *filename)
{
	if (Configfile.config != NULL)
	{
		iniparser_freedict(Configfile.config);
		Configfile.config = NULL;
	}
	Configfile.config = iniparser_load((const char *)filename);
}

void ConfigfileSaveConfig(char *filename)
{
	if (Configfile.config != NULL)
	{
		FileOpenForWrite(filename);
		iniparser_dump_ini(Configfile.config, File.fs);
		FileClose();
	}
}

void ConfigfileAddSection(char *sectionName)
{
	int i;
	if (Configfile.config != NULL)
	{
		for (i = 0; i < iniparser_getnsec(Configfile.config); i++)
		{
			if (iniparser_getsecname(Configfile.config, i) == sectionName)
			{
				return;
			}
		}
//		FileOpenForWrite("config.tmp");
//		iniparser_dump_ini(Configfile.config, File.fs);
//		FileWriteLine(" ");
//		FileWrite("[");
//		FileWrite(sectionName);
//		FileWrite("]");
//		FileWriteLine(" ");
//		FileClose();
//		Configfile.config = iniparser_load("config.tmp");
		iniparser_set(Configfile.config, (const char *)sectionName, NULL);
	}
}

void ConfigfileSetKeyValue(char *sectionName, char *key, char *value)
{
	char *temp;
	if (sectionName != NULL)
	{
		temp = malloc(sizeof(char) * (strlen(sectionName) + strlen(key) + 1));
		sprintf(temp, "%s:%s\n", sectionName, key);
	}
	else
	{
		temp = key;
	}
	if (Configfile.config != NULL)
	{
		iniparser_set(Configfile.config, temp, (const char *)value);
	}
	free(temp);
}

char *ConfigfileGetKeyValue(char *sectionName, char *key)
{
	char *temp;
	char *result;
	temp = malloc(sizeof(char) * (strlen(sectionName) + strlen(key) + 1));
	sprintf(temp, "%s:%s\n", sectionName, key);
	if (Configfile.config != NULL)
	{
		result = iniparser_getstring(Configfile.config, temp, NULL);
		free(temp);
		return result;
	}
	else
	{
		return NULL;
	}
}
