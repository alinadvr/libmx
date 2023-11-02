#include <stdio.h>
#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    double quotient = nbr;
    int remainder, i = 0;
    static char res[100];
    
    while ((int) quotient != 0) {
        quotient /= 16;
        remainder = (quotient - (int) quotient) * 16;

        if (remainder < 10)
            res[i] = remainder + 48;
        else
            res[i] = remainder + 87;

        i++;
    };

    mx_str_reverse(res);
    
    return res;
}
