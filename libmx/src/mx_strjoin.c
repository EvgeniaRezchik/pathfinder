#include "../inc/libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
    char *joined;

    if (s1 == NULL && s2 == NULL)
        return NULL;
    else if (s1 == NULL)
        joined = mx_strdup(s2);
    else if (s2 == NULL)
        joined = mx_strdup(s1);
    else {
        char dup[mx_strlen(s1)];

	mx_strcpy(dup, s1);
	joined = mx_strdup(mx_strcat(dup, s2));
    }
    return joined;
}

