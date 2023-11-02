#include "libmx.h"

static int partition(char **arr, int start, int end, int *swap)
{
    int pivot = (start + end) / 2;

    while (pivot - start > 0 || end - pivot > 0)
    {
        if (start < pivot && mx_strlen(arr[start]) < mx_strlen(arr[pivot]))
            start++;
        else if (end > pivot && mx_strlen(arr[end]) >= mx_strlen(arr[pivot]))
            end--;
        else
        {
            char *temp = *(arr + start);
            *(arr + start) = *(arr + end);
            *(arr + end) = temp;
            
            *swap = *swap + 1;
            start++;
            end--;
        }
    }

    return pivot;
}

int mx_quicksort(char **arr, int left, int right)
{
    if (arr == NULL || *arr == NULL) return -1;

    static int swap = 0;

    if (left < right)
    {
        int pivot_index = partition(arr, left, right, &swap);
        
        mx_quicksort(arr, left, pivot_index - 1);
        mx_quicksort(arr, pivot_index + 1, right);
    }

    return swap;
}
