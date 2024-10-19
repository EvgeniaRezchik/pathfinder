#include "../inc/libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    unsigned char *string = (unsigned char *)s;

    for (unsigned long int i = 0; i < n; i += 1) {
        if (string[i] == c)
            return string + i;
    }
    return NULL;
}

