#include "../inc/libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
    if (arr == NULL || delim == NULL)
        return;
    for (int i = 0; arr[i] != NULL; i += 1) {
        mx_printstr(arr[i]);
	if (arr[i + 1] != NULL)
	    mx_printstr(delim);
    }
    write(1, "\n", 1);
}

