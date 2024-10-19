#include "../inc/libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    char *str1 = (char *)dst;
    char *str2 = (char *)src;

    if (dst <= src) {
        for (unsigned long int i = 0; i < len; i += 1)
            str1[i] = str2[i];
    }
    else {
        for (unsigned long int i = len; i > 0; i -= 1)
            str1[i - 1] = str2[i - 1];
    }
    return str1;
}

