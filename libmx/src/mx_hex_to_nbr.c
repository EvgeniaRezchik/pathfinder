#include "../inc/libmx.h"

static bool htod(const char *hex, int length, unsigned long int *dec);
static bool is_digit(int c);
static bool is_alpha(int c);
static bool is_lower(int c);

unsigned long mx_hex_to_nbr(const char *hex) {
    int length = 0;
    unsigned long int dec = 0;

    if (hex == NULL)
        return 0;
    while (hex[length] != 0)
        length += 1;
    if (length < 1 || length > 16)
        return 0;
    if (!htod(hex, length, &dec))
        return 0;
    return dec;
}

static bool htod(const char *hex, int length, unsigned long int *dec) {
    for (int i = 0; hex[i] != 0; i += 1) {
        unsigned long int n;
	if (is_digit(hex[length - 1 - i]))
	    n = hex[length - 1 - i] - 48;
	else if (is_alpha(hex[length - 1 - i])) {
	    if (is_lower(hex[length - 1 - i])
		&& (hex[length - 1 - i] >= 'a' && hex[length - 1 - i] <= 'f'))
	        n = hex[length - 1 - i] - 87;
	    else if (hex[length - 1 - i] >= 'A' && hex[length - 1 - i] <= 'F')
	        n = hex[length - 1 - i] - 55;
	    else
	        return false;
	}
	else
	    return false;
	for (int j = 1; j <= i; j += 1)
	    n *= 16;
	*dec += n;
    }
    return true;
}

static bool is_digit(int c) {
    if ((c >= 48) && (c <= 57))
        return true;
    else
        return false;
}

static bool is_alpha(int c) {
    if (((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122)))
        return true;
    else
        return false;
}

static bool is_lower(int c) {
    if ((c >= 97) && (c <= 122))
        return true;
    else
        return false;
}

