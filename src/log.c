#include "log.h"

void LogInit(void)
{
    time(&Log.currentTime);
    Log.now = localtime(&Log.currentTime);
    FileOpenForWrite("Log.log");
    FileWrite("[");
    FileWrite(RnjuItoa(Log.now->tm_year + 1900));
    FileWrite("-");
    FileWrite(RnjuItoa(Log.now->tm_mon + 1));
    FileWrite("-");
    FileWrite(RnjuItoa(Log.now->tm_mday));
    FileWrite(" ");
    FileWrite(RnjuItoa(Log.now->tm_hour));
    FileWrite(":");
    FileWrite(RnjuItoa(Log.now->tm_min + 1));
    FileWrite(":");
    FileWrite(RnjuItoa(Log.now->tm_sec + 1));
    FileWriteLine("] Begin logging.");

    FileClose();
}

void LogWrite(char *message, int level, int messageType, char *argument)
{
    int i;
    time(&Log.currentTime);
    Log.now = localtime(&Log.currentTime);
    FileOpenForAppend("Log.log");
    FileWrite("[");
    FileWrite(RnjuItoa(Log.now->tm_year + 1900));
    FileWrite("-");
    FileWrite(RnjuItoa(Log.now->tm_mon + 1));
    FileWrite("-");
    FileWrite(RnjuItoa(Log.now->tm_mday));
    FileWrite(" ");
    FileWrite(RnjuItoa(Log.now->tm_hour));
    FileWrite(":");
    FileWrite(RnjuItoa(Log.now->tm_min + 1));
    FileWrite(":");
    FileWrite(RnjuItoa(Log.now->tm_sec + 1));
    FileWrite("] ");
    switch (messageType)
    {
        case MT_INFO:
            FileWrite("   Info: ");
            break;
        case MT_WARNING:
            FileWrite("Warning: ");
            break;
        case MT_ERROR:
            FileWrite("  Error: ");
            break;
        case MT_NONE:
            break;
    }
    for (i = 0; i < level; i++)
    {
        FileWrite("-- ");
    }
    FileWrite(message);
    if (argument != NULL)
    {
        FileWrite(" \"");
        FileWrite(argument);
        FileWrite("\"");
    }
    FileWriteLine(".");
    FileClose();
}

void LogWrite2(char *message, int level, int messageType, int argument)
{
    int i;
    time(&Log.currentTime);
    Log.now = localtime(&Log.currentTime);
    FileOpenForAppend("Log.log");
    FileWrite("[");
    FileWrite(RnjuItoa(Log.now->tm_year + 1900));
    FileWrite("-");
    FileWrite(RnjuItoa(Log.now->tm_mon + 1));
    FileWrite("-");
    FileWrite(RnjuItoa(Log.now->tm_mday));
    FileWrite(" ");
    FileWrite(RnjuItoa(Log.now->tm_hour));
    FileWrite(":");
    FileWrite(RnjuItoa(Log.now->tm_min + 1));
    FileWrite(":");
    FileWrite(RnjuItoa(Log.now->tm_sec + 1));
    FileWrite("] ");
    switch (messageType)
    {
        case MT_INFO:
            FileWrite("   Info: ");
            break;
        case MT_WARNING:
            FileWrite("Warning: ");
            break;
        case MT_ERROR:
            FileWrite("  Error: ");
            break;
        case MT_NONE:
            break;
    }
    for (i = 0; i < level; i++)
    {
        FileWrite("-- ");
    }
    FileWrite(message);

    FileWrite(" \"");
    FileWrite(RnjuItoa(argument));
    FileWrite("\"");

    FileWriteLine(".");
    FileClose();
}

void LogWriteFromScript(char *message, int level, int messageType, char *argument)
{
    int i;
    time(&Log.currentTime);
    Log.now = localtime(&Log.currentTime);
    FileOpenForAppend("Log.log");
    FileWrite("[");
    FileWrite(RnjuItoa(Log.now->tm_year + 1900));
    FileWrite("-");
    FileWrite(RnjuItoa(Log.now->tm_mon + 1));
    FileWrite("-");
    FileWrite(RnjuItoa(Log.now->tm_mday));
    FileWrite(" ");
    FileWrite(RnjuItoa(Log.now->tm_hour));
    FileWrite(":");
    FileWrite(RnjuItoa(Log.now->tm_min + 1));
    FileWrite(":");
    FileWrite(RnjuItoa(Log.now->tm_sec + 1));
    FileWrite("] ");
    switch (messageType)
    {
        case MT_INFO:
            FileWrite("Info: ");
            break;
        case MT_WARNING:
            FileWrite("Warning: ");
            break;
        case MT_ERROR:
            FileWrite("Error: ");
            break;
    }
    for (i = 0; i < level; i++)
    {
        FileWrite("-- ");
    }
    FileWrite(message);
    if (argument != NULL)
    {
        FileWrite(" \"");
        FileWrite(argument);
        FileWrite("\"");
    }
    FileWriteLine(".");
    FileClose();
}
