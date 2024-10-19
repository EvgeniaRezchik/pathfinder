#include "../inc/libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    int destlen = mx_strlen(s1);
    int i = 0;

    while (s2[i] != 0) {
        s1[destlen + i] = s2[i];
	i += 1;
    }
    s1[destlen + i] = 0;
    return s1;
}

