#include "libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
    if (s1 == NULL || s2 == NULL) return NULL;

    int j = 0, s1Len = mx_strlen(s1), s2Len = mx_strlen(s2);
    char *res = mx_strnew(s1Len + s2Len);

    for (int i = 0; i < s1Len; i++, j++)
        res[j] = s1[i];
        

    for (int i = 0; i < s2Len; i++, j++)
        res[j] = s2[i];

    return res;
}
