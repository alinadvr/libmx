#include "libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd)
{
    if (lineptr == NULL || buf_size == 0 || fd < 0) return -2;

    size_t bytes_read = 0;
    size_t line_size = buf_size;
    char *buffer = (char *) malloc(line_size);

    if (buffer == NULL) return -2;

    char c;
    int result;

    while ((result = read(fd, &c, 1)) > 0)
    {
        if (c == delim) break;

        if (bytes_read + 1 >= line_size)
        {
            line_size += 1;
            char *new_buffer = (char *) malloc(line_size);

            if (new_buffer == NULL)
            {
                free(buffer);
                return -2;
            }

            mx_memcpy(new_buffer, buffer, bytes_read);
            free(buffer);
            buffer = new_buffer;
        }

        buffer[bytes_read++] = c;
    }

    if (result == -1) 
    {
        free(buffer);
        return -2;
    }

    if (bytes_read == 0 && result == 0) {
        free(buffer);
        return -1;
    }

    buffer[bytes_read] = '\0';
    *lineptr = buffer;

    return bytes_read;
}
