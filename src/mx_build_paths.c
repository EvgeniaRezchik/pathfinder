#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

void mx_build_paths(t_island **il, t_path *p, int l,
		    int c, char *d, char *ds, char *s) {
    (*il)[mx_index(d, *il, c)].usage = 0;
    for (int i = 0; i < l; i += 1)
        mx_pave_ways(il, p, l, c, d, ds, s, i);
    (*il)[mx_index(d, *il, c)].usage = -1;
}

