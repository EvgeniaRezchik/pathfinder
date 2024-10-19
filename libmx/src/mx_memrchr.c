#include "../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    unsigned char *str = (unsigned char *)s;

    for (unsigned long int i = n; i > 0; i -= 1) {
        if (str[i - 1] == c)
            return str + i - 1;
    }
    return NULL;
}

