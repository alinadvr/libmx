#include "libmx.h"

void *mx_realloc(void *ptr, size_t size)
{
    if (size == 0)
    {
        free(ptr);

        return NULL;
    } 

    void *new_ptr = malloc(size);

    if (new_ptr)
    {
        size_t s = size;

        if (ptr)
        {
            size_t old_size = malloc_usable_size(ptr);
            s = old_size < size ? old_size : size;

            mx_memcpy(new_ptr, ptr, s);
            free(ptr);
        }
    }

    return new_ptr;
}
