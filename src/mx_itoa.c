#include "libmx.h"

char *mx_itoa(int number)
{
    if (number == 0) return "0";
    if (number == -2147483648) return "-2147483648"; 

    int negative = 0;
    
    if (number < 0)
    {
        negative = 1;
        number = -number;
    }

    if (number > -10 && number < 10)
    {
        char *string = mx_strnew(2);

        if (negative)
        {
            string[0] = '-';
            string[1] = number + '0';
        }
        else 
            string[0] = number + '0';
        
        return string;
    }

    char *string = mx_strnew(11); // max int value + '-' sign
    int nLength = 0;

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
