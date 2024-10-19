#include "../inc/libmx.h"

static int str_n_cmp(const char *s1, const char *s2, int n);
static char *str_chr(const char *s, int c);

char *mx_strstr(const char *haystack, const char *needle) {
    const char *ptr = haystack;

    if (needle == NULL || mx_strcmp(needle, "") == 0)
        return (char *)haystack;
    while (ptr != NULL) {
        ptr = str_chr(ptr, needle[0]);
	if (ptr == NULL)
	    break;
	else {
	    if (str_n_cmp(ptr, needle, mx_strlen(needle)) == 0)
	        return (char *)ptr;
	}
	ptr += 1;
    }
    return NULL;
}

static int str_n_cmp(const char *s1, const char *s2, int n) {
    int i = 0;

    if (n < 0) {
        while (s1[i] != 0 || s2[i] != 0) {
	    if (s1[i] != s2[i])
	        return s1[i] - s2[i];
	    i += 1;
	}
    }
    else if (n > 0) {
        while ((i < n) && (s1[i] != 0 || s2[i] != 0)) {
	    if (s1[i] != s2[i])
	        return s1[i] - s2[i];
	    i += 1;
	}
    }
    return 0;
}

static char *str_chr(const char *s, int c) {
    int i = 0;

    while (s[i] != 0) {
        if (s[i] == c)
	    return (char *)&s[i];
	i += 1;
    }
    if (c == 0)
        return (char *)&s[i];
    return NULL;
}

