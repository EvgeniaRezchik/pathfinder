#include "../inc/libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int minimum = 0;
    int maximum = size - 1;

    if (s == NULL || arr == NULL)
        return -1;
    *count = 0;
    while (minimum <= maximum) {
        int middle = (minimum + maximum) / 2;

	*count += 1;
	if (mx_strcmp(s, arr[middle]) > 0)
	    minimum = middle + 1;
	else if (mx_strcmp(s, arr[middle]) < 0)
	    maximum = middle - 1;
	else
	    return middle;
    }
    *count = 0;
    return -1;
}

