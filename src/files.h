#ifndef RNJ_FILES_H
#define RNJ_FILES_H

#include <stdio.h>
#include <string.h>

#include "defines.h"

void FileOpenForWrite(char*);   /* Открыть файл для записи                  */
void FileOpenForAppend(char*);  /* Открыть файл для дозаписи в конец файла  */
void FileClose(void);           /* Закрыть файл                             */
void FileWrite(char*);          /* Записать строку в файл                   */
void FileWriteLine(char*);      /* Записать строку в файл и перейти на новую
                                   строку                                   */

struct {
    FILE *fs;                   /* Указатель на открытый файл               */
} File;

#endif
