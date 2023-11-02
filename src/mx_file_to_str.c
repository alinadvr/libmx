#include "libmx.h"

char *mx_file_to_str(const char *file) {
    if (file == NULL) return NULL;

    int fd = open(file, O_RDONLY);

    if (fd == -1) return NULL;

    char *s = mx_strnew(100);

    read(fd, s, 100);

    int closed = -1;
    while (closed == -1)
        closed = close(fd);

    return s;
}
