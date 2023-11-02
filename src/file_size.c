#include "libmx.h"

int file_size(const char *file_name)
{
    if (file_name == NULL) return -1;

    char c;
    int size = 0;

    int fd = open(file_name, O_RDONLY);
    if (fd < 0) return -1;

    while (read(fd, &c, 1))
        size++;

    int closed = -1;
    while (closed == -1)
        closed = close(fd);

    return size;
}
