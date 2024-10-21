#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

void mx_set_bool(t_island **il, t_path *p, int d, int i,
		 int j, int c, bool *s) {
    if ((*il)[i].id == p[j].id1 && (((*il)[p[j].id2].weight == 0
	&& (*il)[p[j].id2].id != d)
	|| (*il)[p[j].id2].weight > (*il)[i].weight + p[j].length)) {
        (*il)[p[j].id2].weight = (*il)[i].weight + p[j].length;
	(*il)[p[j].id2].usage = c + 1;
	*s = true;
    }
    else if ((*il)[i].id == p[j].id2 && (((*il)[p[j].id1].weight == 0
	     && (*il)[p[j].id1].id != d)
	     || (*il)[p[j].id1].weight > (*il)[i].weight + p[j].length)) {
        (*il)[p[j].id1].weight = (*il)[i].weight + p[j].length;
	(*il)[p[j].id1].usage = c + 1;
	*s = true;
    }
}
