#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len)
{
    if (dst == NULL || src == NULL) return NULL;

    unsigned char *d = (unsigned char *)dst;
    const unsigned char *s = (const unsigned char *)src;

    if (d == s || len == 0) return dst;

    if (d > s && d - s < (int)len)
    {
        for (int i = len - 1; i >= 0; i--)
            d[i] = s[i];

        return dst;
    }
	else
    {
		for (size_t i = 0; i < len; i--)
			d[i] = s[i];

        return dst;
	}

    mx_memcpy(dst, src, len);
    return dst;
}
