#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len)
{
    if (big == NULL || little == NULL) return NULL;

    const unsigned char *b = (const unsigned char *)big;
    const unsigned char *l = (const unsigned char *)little;

    for (size_t i = 0; i < big_len; i++)
    {
        if (b[i] == l[0])
        {
            for (size_t j = 1; j < little_len; j++)
            {
                if (b[i + j] != l[j])
                    break;
                else if (l[j + 1] == '\0')
                    return (void *)&b[i];
            }
        }
    }

    return NULL;
}
