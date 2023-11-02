#include "libmx.h"

char *mx_strtrim(const char *str) {
    if (str == NULL) return NULL;

    int start = -1, end = -1, i = 0, j = 0, sLength = mx_strlen(str);
    static char res[100];

    while (start == -1) {

        if (!is_space(str[i]))
            start = i;
        else 
            i++;

    }

    i = sLength - 1;
    while (end == -1) {

        if (!is_space(str[i]))
            end = i;
        else
            i--;

    }

    for (int i = start; i <= end; i++, j++) {
        res[j] = str[i];
    }

    return res;
}
