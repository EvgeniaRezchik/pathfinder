#include "../inc/libmx.h"

void *mx_memset(void *b, int c, size_t len) {
    char *a = b;

    for (unsigned long int i = 0; i < len; i += 1)
        a[i] = c;
    return a;
}

