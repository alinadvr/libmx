#include "libmx.h"

char *mx_strdup(const char *str) {
    int size = mx_strlen(str);
    char *newStr = mx_strnew(size);

    mx_strcpy(newStr, str);
    
    return newStr;
}
