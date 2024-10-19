#include "../inc/libmx.h"

void mx_str_reverse(char *s) {
    int middle = mx_strlen(s) / 2;

    for (int i = 0; i < middle; i += 1)
        mx_swap_char(&s[i], &s[mx_strlen(s) - i - 1]);
}

