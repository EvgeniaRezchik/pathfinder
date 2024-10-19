#include "../inc/libmx.h"

void mx_printint(int n) {
    if (n == -2147483648) {
	write(1, "-2147483648", 11);
	return;
    }
    if (n < 0) {
        write(1, "-", 1);
	n *= -1;
    }
    char digit;

    while (n / 10 != 0) {
        mx_printint(n / 10);
	digit = n % 10 + 48;
	write(1, &digit, 1);
	return;
    }
    digit = n + 48;
    write(1, &digit, 1);
}

