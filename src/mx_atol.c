#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

static long a_to_l(const char *nptr, long *result, int *sign, int i);

long mx_atol(const char *nptr) {
    long result = 0;
    int sign = 1;
    int i = 0;

    return a_to_l(nptr, &result, &sign, i);
}

static long a_to_l(const char *nptr, long *result, int *sign, int i) {
    while (mx_isdigit(nptr[i]) || mx_isspace(nptr[i])
           || nptr[i] == '-' || nptr[i] == '+') {
        if (nptr[i] == '-' || nptr[i] == '+') {
            *sign = nptr[i] == '-' ? -1 : 1;
            if (!mx_isdigit(nptr[i + 1]))
                break;
        }
        else if (mx_isdigit(nptr[i])) {
            if (*result > LONG_MAX / 10
                || (*result == LONG_MAX / 10 && nptr[i] - 48 > 7))
                return *sign == 1 ? LONG_MAX : LONG_MIN;
            if (*result != 0)
                *result *= 10;
            *result += nptr[i] - 48;
            if (!mx_isdigit(nptr[i + 1]))
                break;
        }
        i += 1;
    }
    return *result * *sign;
}

