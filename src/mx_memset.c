#include "libmx.h"

void *mx_memset(void *b, int c, size_t len)
{
    unsigned char *buffer = (unsigned char *) b;
    
    for (size_t i = 0; i < len; i++)
        buffer[i] = c;
        
    return buffer;
}
