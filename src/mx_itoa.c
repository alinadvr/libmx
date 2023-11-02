#include "libmx.h"

char *mx_itoa(int number)
{
    if (number == 0) return "0";
    if (number == -2147483648) return "-2147483648"; 

    static char string[11]; // max int value + '-' sign
    int nLength = 0;
    int negative = 0;
    
    if (number < 0)
    {
        negative = 1;
        number = -number;
    }

    while (number > 0)
    {
        string[nLength] = number % 10 + '0';
        nLength++;
        number /= 10;
    }

    if (negative) {
        string[nLength] = '-';
        nLength++;
    }

    mx_str_reverse(string);

    return string;
}
