#include "libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    int dLength, sLength = mx_strlen(src);

    if (sLength > len) dLength = len;
    else dLength = sLength;

    for (int i = 0; i < dLength; i++) {
        dst[i] = src[i];
    }

    if (len > sLength) {
        for (int i = dLength; i < len; i++) {
            dst[i] = '\0';
        }
    }

    return dst;
}
