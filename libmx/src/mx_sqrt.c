#include "../inc/libmx.h"

int mx_sqrt(int x) {
    for (long int i = 0; i * i <= x; i += 1) {
        if (i * i == x)
	    return i;
    }
    return 0;
}

