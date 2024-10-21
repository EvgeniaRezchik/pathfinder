#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

int mx_print_sign(t_island *il, t_path *p, int d,
		  int ds, int *cu, int i) {
    if ((il[*cu].id == p[i].id1 && p[i].id2 == ds)
	|| (il[*cu].id == p[i].id2 && p[i].id1 == ds)) {
        if (p[i].id1 != d && p[i].id2 != d) {
	    mx_printint(p[i].length);
	    mx_printstr(" = ");
	}
	mx_printint(il[ds].weight);
	return 1;
    }
    else {
        mx_printint(p[i].length);
	mx_printstr(" + ");
	*cu = il[*cu].id == p[i].id1 ? p[i].id2 : p[i].id1;
	return 0;
    }
}
