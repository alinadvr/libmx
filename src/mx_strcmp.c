int mx_strcmp(const char *s1, const char *s2) {
    int i;

    for (i = 0; s1[i] != '\0'; i++) {
        if (s1[i] == s2[i])
            continue;
        else
            return s1[i] - s2[i];
    }

    if (s2[i] != '\0')
        return -s2[i];

    return 0;
}
