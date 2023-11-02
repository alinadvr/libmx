#include "libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
    if (arr == NULL || delim == NULL) return;

    for (int i = 0; arr[i + 1] != NULL; i++) {
        mx_printstr(arr[i]);

        if (arr[i + 2] != NULL)
            mx_printstr(delim);
    }

    mx_printchar('\n');
}
