#include "libmx.h"

char **mx_strsplit(const char *s, char c) {
    if (s == NULL) return NULL;

    static char words[20][30];
    int letter = 0, word = 0, delim = 0;

    int i;
    for (i = 0; s[i] != '\0'; i++) {

        if (s[i] != c) {
            // return NULL if creation falls
            if (word > 19 || letter > 29) return NULL;

            words[word][letter] = s[i];
            letter++;
            delim = 0;

            if (s[i + 1] == c || s[i + 1] == '\0') {
                words[word][letter] = '\0';
                letter++;
            }

        }
        else if (!delim) {

            if (word != 0 || letter != 0) 
                word++;

            letter = 0;
            delim = 1;

        }

    }

    if (word == 0 && letter == 0) return NULL;

    return (char **)words;
}
