#include "../inc/libmx.h"

static void partition(char **list, int *start, int *end, int *swaps);
static void swap_elements(char **el1, char **el2, int *swaps);

int mx_quicksort(char **arr, int left, int right) {
    int swaps = 0;
    int less = left;
    int more = right;

    if (arr == NULL)
        return -1;
    if (left < 0 || left >= right)
        return swaps;
    partition(arr, &less, &more, &swaps);
    swaps += mx_quicksort(arr, left, less - 1);
    swaps += mx_quicksort(arr, more + 1, right);
    return swaps;
}

static void partition(char **list, int *start, int *end, int *swaps) {
    int pivot = *end;
    int equal = *start;

    while (equal <= *end) {
        if (mx_strlen(list[equal]) < mx_strlen(list[pivot])) {
	    if (mx_strlen(list[equal]) < mx_strlen(list[*start]))
	        swap_elements(&list[equal], &list[*start], swaps);
	    if (equal == *start)
	        equal += 1;
	    *start += 1;
	}
	else if (mx_strlen(list[equal]) > mx_strlen(list[pivot])) {
	    if (mx_strlen(list[equal]) > mx_strlen(list[*end]))
	        swap_elements(&list[equal], &list[*end], swaps);
	    *end -= 1;
	}
	else if (mx_strlen(list[equal]) == mx_strlen(list[pivot]))
	    equal += 1;
    }
}

static void swap_elements(char **el1, char **el2, int *swaps) {
    char *buffer;

    buffer = *el1;
    *el1 = *el2;
    *el2 = buffer;
    *swaps += 1;
}

