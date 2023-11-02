#include "libmx.h"

char *mx_del_extra_spaces(const char *str) {
    if (str == NULL) return NULL;

    char words[20][30], *trimStr = mx_strtrim(str);
    static char res[600];
    int letter = 0, word = 0;

    int i;
    for (i = 0; trimStr[i] != '\0'; i++) {

        if (!is_space(trimStr[i])) {
            // return NULL if creation falls
            if (word > 19 || letter > 29) return NULL;

            words[word][letter] = trimStr[i];
            letter++;

            if (is_space(trimStr[i + 1]) || trimStr[i + 1] == '\0') {
                words[word][letter] = '\0';
                letter++;
            }

        }
        else if (!is_space(trimStr[i - 1])) {
            word++;
            letter = 0;
        }
    }

    int k = 0;
    for (int i = 0; i <= word; i++, k++) {

        for (int j = 0; words[i][j] != '\0' ; j++, k++)
            res[k] = words[i][j];
        
        if (i != word)
            res[k] = ' ';
        
    }

    return res;
}
