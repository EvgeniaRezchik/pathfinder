#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

bool mx_isspace(int c) {
    if (((c >= 9) && (c <= 13)) || (c == 32))
        return true;
    else
        return false;
}

