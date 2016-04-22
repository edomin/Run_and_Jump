#include "files.h"

void FileOpenForWrite(char* filename)
{
    File.fs = fopen(filename, FM_WRITE);
}

void FileOpenForAppend(char* filename)
{
    File.fs = fopen(filename, FM_APPEND);
}

void FileClose(void)
{
    fclose(File.fs);
}

void FileWrite(char* text)
{
    fwrite(text, sizeof(char), strlen(text), File.fs);
}

void FileWriteLine(char* text)
{
    fwrite(text, sizeof(char), strlen(text), File.fs);
    fwrite("\n", sizeof(char), strlen("\n"), File.fs);
}

