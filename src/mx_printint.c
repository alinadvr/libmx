#include "libmx.h"

void mx_printint(int n) {
    char *s = mx_itoa(n);

    mx_printstr(s);
}
