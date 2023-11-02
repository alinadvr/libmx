#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len)
{
    if (dst == NULL || src == NULL || len < 0) return NULL;

    char *p_src = (char *) src;
    char *p_dst = (char *) dst;
    char *buf = (char *) malloc(sizeof(char) * len);

    mx_memcpy(buf, p_src, len);
    mx_memcpy(p_dst, buf, len);
    free(buf);

    return dst;
}
