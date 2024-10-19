#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

bool mx_check_name(char *name) {
    for (int i = 0; name[i] != 0; i += 1) {
        if (!mx_isalpha(name[i]))
	    return false;
    }
    return true;
}

