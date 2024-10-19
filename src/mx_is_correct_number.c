#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

bool mx_is_correct_number(char *string) {
    if (string[0] == '0')
        return false;
    for (int i = 0; string[i] != 0; i += 1) {
        if (!mx_isdigit(string[i]))
	    return false;
    }
    return true;
}

