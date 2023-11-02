#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    if (str == NULL || sub == NULL) return -1;
    
    if (sub[0] == '\0') return 0;

    int res = 0, j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == sub[j]) {
            j++;
            if (sub[j] == '\0') {
                res++;
                j = 0;
            }
        } else j = 0;
    }

    return res;
}
