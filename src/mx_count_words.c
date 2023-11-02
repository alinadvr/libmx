#include "libmx.h"

int mx_count_words(const char *str, char c) {
    if (str == NULL) return -1;

    int res = 0, delim = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c && str[i + 1] != '\0')
        {
            if (delim == 0) res++;
            if (str[i + 1] == c) delim++;
            else delim = 0;
        }
    }

    if (str[0] != c && res > 0) res++;

    return res;
}
