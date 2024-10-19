#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

void mx_print_route(t_island *il, t_path *p, int l,
		    int c, char *d, char *ds) {
    int curr = mx_index(d, il, c);
    bool found = false;

    while (true) {
        found = false;
	for (int i = 0; i < l && !found; i += 1) {
	    if ((mx_strcmp(il[curr].name, p[i].first) == 0
		&& il[mx_index(p[i].second, il, c)].usage != -1
		&& il[mx_index(p[i].second, il, c)].weight == il[curr].weight + p[i].length)
		|| (mx_strcmp(il[curr].name, p[i].second) == 0
		&& il[mx_index(p[i].first, il, c)].usage != -1
		&& il[mx_index(p[i].first, il, c)].weight == il[curr].weight + p[i].length)) {
	        found = true;
		if (mx_print_way(il, p, ds, c, &curr, i) == 1)
		    return;
	    }
	}
    }
}

