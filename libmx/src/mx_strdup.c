#include "../inc/libmx.h"

char *mx_strdup(const char *s1) {
    int length = mx_strlen(s1);
    char *dup = mx_strnew(length);

    if (dup == NULL)
        return NULL;
    for (int i = 0; i < length; i += 1)
        dup[i] = s1[i];
    return dup;
}

