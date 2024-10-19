#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

int mx_print_way(t_island *il, t_path *p, char *ds, int c, int *curr, int i) {
    if ((mx_strcmp(il[*curr].name, p[i].first) == 0
	&& mx_strcmp(p[i].second, ds) == 0)
	|| (mx_strcmp(il[*curr].name, p[i].second) == 0
	&& mx_strcmp(p[i].first, ds) == 0)) {
        mx_printstr(il[*curr].name);
	mx_printstr(" -> ");
	mx_printstr(ds);
	return 1;
    }
    else {
        mx_printstr(il[*curr].name);
	mx_printstr(" -> ");
	*curr = mx_strcmp(il[*curr].name, p[i].first) == 0 ?
	       mx_index(p[i].second, il, c) :
	       mx_index(p[i].first, il, c);
	return 0;
    }
}

