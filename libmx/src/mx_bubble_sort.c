#include "../inc/libmx.h"

int mx_bubble_sort(char **arr, int size) {
    bool swap;
    char *buffer;
    int counter = 0;
    if (arr == NULL)
        return 0;
    for (int i = 0; i < size - 1; i += 1) {
        swap = false;
	for (int j = 0; j < size - 1 - i; j += 1) {
	    if (mx_strcmp(arr[j], arr[j + 1]) > 0) {
	        buffer = arr[j];
		arr[j] = arr[j + 1];
		arr[j + 1] = buffer;
		swap = true;
		counter += 1;
	    }
	}
	if (!swap)
	    break;
    }
    return counter;
}

