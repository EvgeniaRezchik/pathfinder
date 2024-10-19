#include "../inc/libmx.h"

void mx_printstr(const char *s) {
    if (s == NULL)
        return;
    int counter = mx_strlen(s);

    for (int i = 0; i < counter; i += 1)
        write(1, &s[i], 1);
}

