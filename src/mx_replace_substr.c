#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace)
{
    if (str == NULL || sub == NULL || replace == NULL) return NULL;

    int j = 0, strLen = mx_strlen(str), subLen = mx_strlen(sub);
    char *res = mx_strnew(strLen + 50);

    for (int i = 0; i < strLen; i++)
    {
        if (str[i] != sub[0])
        {
            res[j] = str[i];
            j++;
        } 
        else
        {
            if (mx_strcmp(strcpy_part(str, i, i + subLen - 1), sub) == 0)
            {
                for (int k = 0; replace[k] != '\0'; k++, j++)
                    res[j] = replace[k];

                i += subLen - 1;
            } 
            else
            {
                res[j] = str[i];
                j++;
            }
        }
    }

    return res;
}
