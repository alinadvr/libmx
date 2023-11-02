#include "libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int start = 0;
    int end = size - 1;

    while (start <= end) {
        *count += 1;
        int mid = start + (end - start) / 2;
        int strcmp = mx_strcmp(arr[mid], s);

        if (strcmp == 0)
            return mid;
        else if (strcmp < 0) 
            start = mid + 1;
        else
            end = mid - 1;
    }

    *count = 0;
    return -1;
}
