#include "libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    if (hex == NULL) return -1;

    unsigned long decimal = 0;
    int power = 0, value;

    for (int i = 1; hex[i] != '\0'; i++) {
        power++;
    }

    for (int i = 0; hex[i] != '\0'; i++) {
        if (hex[i] >= 48 && hex[i] <= 57)
            value = hex[i] - 48;
        else if (hex[i] >= 65 && hex[i] <= 70)
            value = hex[i] - 55;
        else
            value = hex[i] - 87;

        decimal += value * mx_pow(16, power);
        power--;
    }
    
    return decimal;
}
