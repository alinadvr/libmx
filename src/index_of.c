#include "libmx.h"

int index_of(char **arr, char *str)
{
    for (int i = 0; arr[i] != NULL; i++)
    {
        if (mx_strcmp(arr[i], str) == 0)
            return i;
    }

    return -1;
}
