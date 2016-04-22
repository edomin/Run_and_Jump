#ifndef RNJ_UTILS_H
#define RNJ_UTILS_H

#include <stdlib.h>
#include <stdint.h>

#include "defines.h"

int RnjuDigitsCount(int); /* Посчитать число знаков в числе */
char *RnjuItoa(int); /* Число в строку */
int16_t RnjuAxisFloatToInt(float); /* Перевести число из диапазона -1..1 в -32768..32767 */

#endif
