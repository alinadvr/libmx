#include "libmx.h"

char **mx_strsplit(const char *s, char c)
{
    if (s == NULL) return NULL;

    int count_words = mx_count_words(s, c);
    if (count_words < 1) return NULL;

    char **words = (char **) malloc(sizeof(char **) * (count_words + 1));
    if (words == NULL) return NULL;

    int word = 0, word_start = 0, word_end = 0;

    words[count_words] = NULL;

    int i = 0;
    while (s[i] != '\0')
    {

        while (s[i] == c)
            i++;

        word_start = i;

        while (s[i] != c && s[i] != '\0')
            i++;

        word_end = i - 1;

        if (word_start < word_end)
            words[word++] = strcpy_part(s, word_start, word_end);

    }

    return words;
}
