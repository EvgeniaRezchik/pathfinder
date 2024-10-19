#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

void mx_set_bool(t_island **il, t_path *p, char *d, int i,
		 int j, int c, int co, bool *s) {
    if (mx_strcmp((*il)[i].name, p[j].first) == 0
	&& (((*il)[mx_index(p[j].second, *il, co)].weight == 0
	&& mx_strcmp((*il)[mx_index(p[j].second, *il, co)].name, d) != 0)
	|| (*il)[mx_index(p[j].second, *il, co)].weight > (*il)[i].weight + p[j].length)) {
        (*il)[mx_index(p[j].second, *il, co)].weight = (*il)[i].weight + p[j].length;
	(*il)[mx_index(p[j].second, *il, co)].usage = c + 1;
	*s = true;
    }
    else if (mx_strcmp((*il)[i].name, p[j].second) == 0
	     && (((*il)[mx_index(p[j].first, *il, co)].weight == 0
	     && mx_strcmp((*il)[mx_index(p[j].first, *il, co)].name, d) != 0)
	     || (*il)[mx_index(p[j].first, *il, co)].weight > (*il)[i].weight + p[j].length)) {
        (*il)[mx_index(p[j].first, *il, co)].weight = (*il)[i].weight + p[j].length;
	(*il)[mx_index(p[j].first, *il, co)].usage = c + 1;
	*s = true;
    }
}

