#include "../inc/libmx.h"

static char *write_zero(void);
static char *write_hex(unsigned long int number);

char *mx_nbr_to_hex(unsigned long nbr) {
    if (nbr < 0 || nbr > ULONG_MAX) {
        char *zero = write_zero();

	return zero;
    }
    else {
        char *hex = write_hex(nbr);

	return hex;
    }
}

static char *write_zero(void) {
    char *zero = mx_strnew(1);

    if (zero == NULL)
        return NULL;
    zero[0] = '0';
    return zero;
}

static char *write_hex(unsigned long int number) {
    unsigned long int orig = number;
    int length = 1;

    while (number / 16 != 0) {
        length += 1;
        number /= 16;
    }
    char *hex = mx_strnew(length);

    if (hex == NULL)
        return NULL;
    for (int i = length - 1; i >= 0; i -= 1) {
        hex[i] = orig % 16 > 9 ? orig % 16 + 87 : orig % 16 + 48;
        orig /= 16;
    }
    return hex;
}

