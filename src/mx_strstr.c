#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle)
{
    if (haystack == NULL || needle == NULL) return NULL;

    for (int i = 0; haystack[i] != '\0'; i++)
    {
        if (haystack[i] == needle[0])
        {
            for (int j = 1; needle[j] != '\0'; j++)
            {
                if (haystack[i + j] != needle[j])
                    break;
                else if (needle[j + 1] == '\0')
                    return (char *)haystack + i;
            }
        }
    }

    return NULL;
}
