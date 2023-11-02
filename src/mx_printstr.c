#include "libmx.h"

void mx_printstr(const char *s) {

    if (s == NULL)
        write(1, "(null)", 6);
    else {
        int str_len = mx_strlen(s);
    
        write(1, s, str_len);
    }
    
}
