#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

void mx_set_weights(t_island **il, t_path *p, int ln, int count, char *dpr) {
    int c = 0;
    bool set = true;

    (*il)[mx_index(dpr, *il, count)].usage = c;
    while (set) {
        set = false;
	for (int i = 0; i < count; i += 1) {
	    if ((*il)[i].usage == c) {
	        for (int j = 0; j < ln; j += 1)
		    mx_set_bool(il, p, dpr, i, j, c, count, &set);
	    }
	}
	c += 1;
    }
}

