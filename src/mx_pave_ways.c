#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

void mx_pave_ways(t_island **il, t_path *p, int l, int c,
		  int d, int ds, int s, int i, int j, int id) {
    if ((*il)[d].id == p[j].id1 && (*il)[i].id == p[j].id2
	&& (*il)[p[j].id2].weight == (*il)[d].weight + p[j].length) {
        if ((*il)[p[j].id2].id == ds) {
	    (*il)[p[j].id2].usage = id + 1;
	    mx_print_block(*il, p, l, s, ds);
	    (*il)[p[j].id2].usage = -1;
	}
	else
	    mx_build_paths(il, p, l, c, p[j].id2, ds, s, id + 1);
    }
    else if ((*il)[d].id == p[j].id2 && (*il)[i].id == p[j].id1
	     && (*il)[p[j].id1].weight == (*il)[d].weight + p[j].length) {
        if ((*il)[p[j].id1].id == ds) {
	    (*il)[p[j].id1].usage = id + 1;
	    mx_print_block(*il, p, l, s, ds);
	    (*il)[p[j].id1].usage = -1;
	}
	else
	    mx_build_paths(il, p, l, c, p[j].id1, ds, s, id + 1);
    }
}
