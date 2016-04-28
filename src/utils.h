#ifndef RNJ_UTILS_H
#define RNJ_UTILS_H

#include <stdlib.h>
#include <stdint.h>

#include "defines.h"

int RnjuDigitsCount(int);           /* Посчитать число знаков в числе       */
char *RnjuItoa(int);                /* Число в строку                       */
int16_t RnjuAxisFloatToInt(float);  /* Перевести число из диапазона -1..1
                                       в -32768..32767                      */
int RnjuIsPowerOfTwo(unsigned int x); /* Возвращает истину, если число
                                         является степенью двойки */
uint32_t RnjuPreviousPowerOfTwo(uint32_t x); /* Округлить число вниз до
                                                близжайшей степени двойки */
#endif
