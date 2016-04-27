#ifndef RNJ_FILES_H
#define RNJ_FILES_H

#include <stdio.h>
#include <string.h>

#include "defines.h"

void FileOpenForWrite(char*);   /* ������� ���� ��� ������                  */
void FileOpenForAppend(char*);  /* ������� ���� ��� �������� � ����� �����  */
void FileClose(void);           /* ������� ����                             */
void FileWrite(char*);          /* �������� ������ � ����                   */
void FileWriteLine(char*);      /* �������� ������ � ���� � ������� �� �����
                                   ������                                   */

struct {
    FILE *fs;                   /* ��������� �� �������� ����               */
} File;

#endif
