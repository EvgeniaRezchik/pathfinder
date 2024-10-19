#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    char *str = (char *)big;
    char *sub = (char *)little;
    char *temp = str;

    for (unsigned long int i = 0; i < big_len; i += 1) {
        if (mx_memcmp(temp, sub, little_len) == 0)
            return temp;
        temp += 1;
    }
    return NULL;
}

