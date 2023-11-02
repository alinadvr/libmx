#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n)
{
    if (s == NULL) return NULL;
    
    const unsigned char *str = (const unsigned char *)s;
    unsigned char ch = (unsigned char)c;
    
    for (size_t i = 0; i < n; i++)
        if (str[i] == ch) return (void *)&str[i];

    return NULL;
}
