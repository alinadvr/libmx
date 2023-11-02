#include "libmx.h"

char *mx_file_to_str(const char *file) {
    if (file == NULL) return NULL;

    int str_size = file_size(file);
    if (str_size <= 0) return NULL;

    int fd = open(file, O_RDONLY);
    if (fd < 0) return NULL;

    char *s = mx_strnew(str_size);
    read(fd, s, str_size);

    int closed = -1;
    while (closed == -1)
        closed = close(fd);

    return s;
}
