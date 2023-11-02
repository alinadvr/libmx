#include "libmx.h"

char *mx_strdup(const char *str)
{
    if (str == NULL) return NULL;

    int size = mx_strlen(str);
    char *newStr = mx_strnew(size);

    mx_strcpy(newStr, str);
    
    return newStr;
}
