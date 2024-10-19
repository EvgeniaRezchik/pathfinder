#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

int mx_index(char *str, t_island *islands, int count) {
    for (int i = 0; i < count; i += 1) {
        if (mx_strcmp(str, islands[i].name) == 0)
	    return i;
    }
    return -1;
}

