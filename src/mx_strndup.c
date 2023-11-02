#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    size_t dLength, sLength = mx_strlen(s1);

    if (sLength < n) dLength = sLength;
    else dLength = n;

    char *newStr = mx_strnew(dLength);

    for (size_t i = 0; i < dLength; i++) {
        newStr[i] = s1[i];
    }
    
    return newStr;
}
