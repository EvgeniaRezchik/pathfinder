#include "../inc/libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    unsigned long int length = 0;

    while (s1[length] != 0)
        length += 1;
    length = n < length ? n : length;
    char *result = mx_strnew(length);

    if (result == NULL)
        return NULL;
    for (unsigned long int i = 0; i < length; i += 1)
        result[i] = s1[i];
    return result;
}

