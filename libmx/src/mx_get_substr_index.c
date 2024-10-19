#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    int i = 0;

    if (str == NULL || sub == NULL)
        return -2;
    char *s = mx_strstr(str, sub);

    if (s == NULL)
        return -1;
    for (const char *j = str; *j != 0; j += 1) {
        if (j == s)
	    return i;
	i += 1;
    }
    return -1;
}

