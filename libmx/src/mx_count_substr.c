#include "../inc/libmx.h"

static int str_n_cmp(const char *s1, const char *s2, int n);

int mx_count_substr(const char *str, const char *sub) {
    int counter = 0;
    const char *ptr = str;

    if (str == NULL || sub == NULL)
        return -1;
    if (str_n_cmp(sub, "", mx_strlen(sub)) == 0)
        return 0;
    while (ptr != NULL) {
        ptr = mx_strstr(ptr, sub);
	if (ptr != NULL)
	    counter += 1;
	else
	    break;
	ptr += 1;
    }
    return counter;
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

