#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

int mx_print_way(t_island *il, t_path *p, int ds, int *curr, int i) {
    if ((il[*curr].id == p[i].id1 && p[i].id2 == ds)
	|| (il[*curr].id == p[i].id2 && p[i].id1 == ds)) {
        mx_printstr(il[*curr].name);
	mx_printstr(" -> ");
	mx_printstr(il[ds].name);
	return 1;
    }
    else {
        mx_printstr(il[*curr].name);
	mx_printstr(" -> ");
	*curr = il[*curr].id == p[i].id1 ? p[i].id2 : p[i].id1;
	return 0;
    }
}
