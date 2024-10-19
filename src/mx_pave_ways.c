#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

void mx_pave_ways(t_island **il, t_path *p, int l, int c,
		  char *d, char *ds, char *s, int i) {
    if (mx_strcmp((*il)[mx_index(d, *il, c)].name, p[i].first) == 0
	&& (*il)[mx_index(p[i].second, *il, c)].weight == (*il)[mx_index(d, *il, c)].weight + p[i].length) {
        if (mx_strcmp((*il)[mx_index(p[i].second, *il, c)].name, ds) == 0) {
	    (*il)[mx_index(p[i].second, *il, c)].usage = 0;
	    mx_print_block(*il, p, l, c, s, ds);
	    (*il)[mx_index(p[i].second, *il, c)].usage = -1;
	}
	else
	    mx_build_paths(il, p, l, c, p[i].second, ds, s);
    }
    else if (mx_strcmp((*il)[mx_index(d, *il, c)].name, p[i].second) == 0
	     && (*il)[mx_index(p[i].first, *il, c)].weight == (*il)[mx_index(d, *il, c)].weight + p[i].length) {
        if (mx_strcmp((*il)[mx_index(p[i].first, *il, c)].name, ds) == 0) {
	    (*il)[mx_index(p[i].first, *il, c)].usage = 0;
	    mx_print_block(*il, p, l, c, s, ds);
	    (*il)[mx_index(p[i].first, *il, c)].usage = -1;
	}
	else
	    mx_build_paths(il, p, l, c, p[i].first, ds, s);
    }
}

