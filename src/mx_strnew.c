#include "libmx.h"

char *mx_strnew(const int size) {
    char *ptr = (char *) malloc(size + 1);

    if (ptr == NULL)
        return NULL;

    for (int i = 0; i <= size; i++)
        ptr[i] = '\0';

    return ptr;
}
