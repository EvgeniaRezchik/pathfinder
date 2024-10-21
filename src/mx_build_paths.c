#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

void mx_build_paths(t_island **il, t_path *p, int l,
		    int c, int d, int ds, int s, int i) {
    (*il)[d].usage = i;
    for (int j = 0; j < c; j += 1) {
        if (j != d) {
	    for (int k = 0; k < l; k += 1)
	        mx_pave_ways(il, p, l, c, d, ds, s, j, k, i);
	}
    }
    (*il)[d].usage = -1;
}
