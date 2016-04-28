#include "utils.h"

/* Подсчитывает число цифр в числе */
int RnjuDigitsCount(int number)
{
    int result = 0;
    if (number == 0)
        return 1;
    if (number < 0)
    {
        number = -number;
    }
    do
    {
        result += 1;
        number /= BASE_DECIMAL;
    } while (number > 0);
    return result;
}

/* Конвертирует число в строку */
char *RnjuItoa(int number)
{
    int digits = RnjuDigitsCount(number);
    static char result[X32_MAX_INT_DIGITS + 1];
    int i;
    /* result = (char *)malloc(sizeof(char) * digits + 1); */
    for (i = 0; i < digits; i++)
    {
        result[digits - 1 - i] = ASCII_ZERO_CODE + number % BASE_DECIMAL;
        number /= BASE_DECIMAL;
    }
    result[digits] = '\0';

    return result;
}

int16_t RnjuAxisFloatToInt(float value)
{
    return (int16_t)(value * 32767);
}

int RnjuIsPowerOfTwo (unsigned int x)
{
    return (
            x == 1 || x == 2 || x == 4 || x == 8 || x == 16 || x == 32 ||
            x == 64 || x == 128 || x == 256 || x == 512 || x == 1024 ||
            x == 2048 || x == 4096 || x == 8192 || x == 16384 ||
            x == 32768 || x == 65536 || x == 131072 || x == 262144 ||
            x == 524288 || x == 1048576 || x == 2097152 ||
            x == 4194304 || x == 8388608 || x == 16777216 ||
            x == 33554432 || x == 67108864 || x == 134217728 ||
            x == 268435456 || x == 536870912 || x == 1073741824);/* ||
            x == 2147483648); */
}

uint32_t RnjuPreviousPowerOfTwo(uint32_t x)
{
    x = x | (x >> 1);
    x = x | (x >> 2);
    x = x | (x >> 4);
    x = x | (x >> 8);
    x = x | (x >> 16);
    return x - (x >> 1);
}
