#include "../inc/libmx.h"

int mx_count_words(const char *str, char c) {
    int i = 0;
    int words = 0;
    if (str == NULL)
        return -1;
    if (str[i] == 0)
        return words;
    while (str[i] == c)
        i += 1;
    while (str[i] != 0) {
        if (str[i] == c) {
	    words += 1;
	    while (str[i] == c)
	        i += 1;
	}
	else
	    i += 1;
    }
    if (str[i - 1] == c)
        return words;
    return words + 1;
}

