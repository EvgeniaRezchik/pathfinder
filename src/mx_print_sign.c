#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

int mx_print_sign(t_island *il, t_path *p, char *d,
		  char *ds, int c, int *cu, int i) {
    if ((mx_strcmp(il[*cu].name, p[i].first) == 0
	&& mx_strcmp(p[i].second, ds) == 0)
	|| (mx_strcmp(il[*cu].name, p[i].second) == 0
	&& mx_strcmp(p[i].first, ds) == 0)) {
        if (mx_strcmp(p[i].first, d) != 0
	    && mx_strcmp(p[i].second, d) != 0) {
	    mx_printint(p[i].length);
	    mx_printstr(" = ");
	}
	mx_printint(il[mx_index(ds, il, c)].weight);
	return 1;
    }
    else {
        mx_printint(p[i].length);
	mx_printstr(" + ");
	*cu = mx_strcmp(il[*cu].name, p[i].first) == 0 ?
	    mx_index(p[i].second, il, c) :
	    mx_index(p[i].first, il, c);
	return 0;
    }
}

