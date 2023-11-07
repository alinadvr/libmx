#include "libmx.h"

char *mx_strtrim(const char *str) {
    if (str == NULL) return NULL;

    int start = -1, end = -1, i = 0, j = 0, s_length = mx_strlen(str);
    char *res = mx_strnew(s_length);

    while (start == -1) {

        if (!is_space(str[i]))
            start = i;
        else if (i + 1 == s_length)
            start = 0;
        else 
            i++;

    }

    i = s_length - 1;
    while (end == -1 && i != start) {
        if (!is_space(str[i]))
            end = i;
        else
            i--;

    }

    for (int k = start; k <= end; k++, j++) {
        res[j] = str[k];
    }

    return res;
}
