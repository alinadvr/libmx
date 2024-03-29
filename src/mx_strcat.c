#include "libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    int j = 0;

    for (int i = mx_strlen(s1); s2[j] != '\0'; i++, j++) {
        s1[i] = s2[j];
    }
    
    return s1;
}
