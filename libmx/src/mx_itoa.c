#include "../inc/libmx.h"

static void write_ascii(char **result, int number, int size);

char *mx_itoa(int number) {
    int size = 1;
    int temp = number;

    if (temp < 0)
        size += 1;
    while (temp / 10 != 0) {
        temp /= 10;
        size += 1;
    }
    char *result = mx_strnew(size);

    if (result == NULL)
        return NULL;
    write_ascii(&result, number, size);
    return result;
}

static void write_ascii(char **result, int number, int size) {
    int start = 0;

    size -= 1;
    if (number < 0) {
        (*result)[0] = '-';
        size -= 1;
        if (number == -2147483648) {
            (*result)[1] = '2';
            number = -147483648;
            size -= 1;
        }
        number *= -1;
    }
    while ((*result)[start] != 0)
        start += 1;
    for (int i = 0; i < size + 1; i += 1) {
        int delim = (int)mx_pow(10, size - i);
        (*result)[start + i] = number / delim + 48;
        number %= delim;
    }
}

