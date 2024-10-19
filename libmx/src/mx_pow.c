#include "../inc/libmx.h"

double mx_pow(double n, unsigned int pow) {
    if (pow == 0) {
        n = 1;
	return n;
    }
    else {
        double result = 1;
	unsigned int i = 0;

	while (i < pow) {
	    result *= n;
	    i += 1;
	}
	return result;
    }
}

