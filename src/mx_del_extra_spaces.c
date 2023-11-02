#include "libmx.h"

char *mx_del_extra_spaces(const char *str)
{
    int start = -1, end = -1, i = 0, j = 0, str_len = mx_strlen(str);
    char *res = mx_strnew(str_len);

    while (start == -1)
    {
        if (!is_space(str[i]))
            start = i;
        else 
            i++;
    }

    i = str_len - 1;
    while (end == -1)
    {
        if (!is_space(str[i]))
            end = i;
        else
            i--;
    }

    for (int k = start; k <= end; k++)
    {
        if (is_space(str[k]))
        {
            if (res[j - 1] != ' ')
                res[j++] = ' ';
                
        }
        else
            res[j++] = str[k];

    }

    return res;
}
