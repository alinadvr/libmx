#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n)
{
    unsigned char *d = (unsigned char *) dst;
    const unsigned char *s = (const unsigned char *) src;
    unsigned char ch = (unsigned char) c;

    for (size_t i = 0; i < n; i++)
    {
        d[i] = s[i]; 

        if (s[i] == ch)
        {
            size_t j;

            for (j = 0; j <= i; j++)
            {
                d[j] = s[j];
            }

            d[j] = '\0';

            return d;
        }

    }

    return NULL;
}
