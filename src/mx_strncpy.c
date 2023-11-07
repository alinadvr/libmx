#include "libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    int dst_len, src_len = mx_strlen(src);

    if (src_len > len) dst_len = len;
    else dst_len = src_len;

    for (int i = 0; i < dst_len; i++) {
        dst[i] = src[i];
    }

    dst[dst_len] = '\0';

    if (len > src_len) {
        for (int i = dst_len + 1; i < len; i++) {
            dst[i] = '\0';
        }
    }

    return dst;
}
