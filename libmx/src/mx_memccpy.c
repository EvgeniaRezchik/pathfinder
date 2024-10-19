#include "../inc/libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
    char *str1 = (char *)dst;
    char *str2 = (char *)src;

    for (unsigned long int i = 0; i < n; i += 1) {
        str1[i] = str2[i];
        if (str2[i] == c)
            return str1 + i + 1;
    }
    return NULL;
}

