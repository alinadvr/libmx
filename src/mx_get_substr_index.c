#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if (str == NULL || sub == NULL) return -2;

    int res, j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == sub[j]) {
            if (j == 0) res = i;
            if (sub[j + 1] == '\0') return res;
            j++;
        } else j = 0;
    }

    return -1;
}
