#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

void mx_print_dist(t_island *il, t_path *p, int l, int d, int ds) {
    int curr = d;
    bool found = false;
    int id = 1;

    while (true) {
        found = false;
	for (int i = 0; i < l && !found; i += 1) {
	    if ((il[curr].id == p[i].id1 && il[p[i].id2].usage == id)
		|| (il[curr].id == p[i].id2 && il[p[i].id1].usage == id)) {
	        found = true;
		id += 1;
		if (mx_print_sign(il, p, d, ds, &curr, i) == 1)
		    return;
	    }
	}
    }
}
