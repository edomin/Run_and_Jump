#ifndef RNJ_UTILS_H
#define RNJ_UTILS_H

#include <stdlib.h>
#include <stdint.h>

#include "defines.h"

int RnjuDigitsCount(int); /* ��������� ����� ������ � ����� */
char *RnjuItoa(int); /* ����� � ������ */
int16_t RnjuAxisFloatToInt(float); /* ��������� ����� �� ��������� -1..1 � -32768..32767 */

#endif
