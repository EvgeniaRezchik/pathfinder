#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

void mx_del_islands(t_island **islands, int count) {
    for (int i = 0; i < count; i += 1) {
        if ((*islands)[i].name != NULL)
	    mx_strdel(&(*islands)[i].name);
    }
    free(*islands);
    *islands = NULL;
}

