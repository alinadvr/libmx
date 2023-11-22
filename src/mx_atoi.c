#include "libmx.h"

int mx_atoi(char *str)
{
    int res = 0, sign = 1;

    if (str[0] == '-')
    {
        sign *= -1;
        str++;
    } 
    else if (str[0] == '+')
    {
        str++;
    }

    while (*str != '\0')
    {
        if (*str > '9' || *str < '0')
            return -1;

        res = res * 10 + *str - '0';

        str++;
    }

    return res * sign;
}
