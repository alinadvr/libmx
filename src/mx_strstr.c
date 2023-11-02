#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    int j = 0;
    static char res[100];

    for (int i = 0; haystack[i] != '\0'; i++) {
        if (haystack[i] == needle[j]) {
            res[j] = haystack[i];
            if (needle[j + 1] == '\0') return res;
            j++;
        } else j = 0;
    }

    return NULL;
}
