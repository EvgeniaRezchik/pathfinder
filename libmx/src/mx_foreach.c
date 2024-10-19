#include "../inc/libmx.h"

void mx_foreach(int *arr, int size, void (*f)(int)) {
    if (f == NULL || arr == NULL)
        return;
    for (int i = 0; i < size; i += 1)
        f(arr[i]);
}

