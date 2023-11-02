#include "libmx.h"

char *strcpy_part(const char *s, int start, int end) {
    if (s == NULL) return NULL;

    int strLen = mx_strlen(s);

    if (strLen < start || strLen < end || start > end) return NULL;

    int j = 0;
    char *res = mx_strnew(end - start);

    for (int i = start; i <= end; i++, j++)
        res[j] = s[i];

    return res;
}
