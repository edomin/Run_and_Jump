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
