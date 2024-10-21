#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

void mx_fill_islands(t_island **islands, int *count, t_path **paths, int ln) {
    for (int i = 0; i < ln - 2; i += 1) {
        bool new_first = true;
	bool new_second = true;
	for (int j = 0; j < *count; j += 1) {
	    if (mx_strcmp((*paths)[i].first, (*islands)[j].name) == 0) {
	        (*paths)[i].id1 = (*islands)[j].id;
		new_first = false;
	    }
	    if (mx_strcmp((*paths)[i].second, (*islands)[j].name) == 0) {
	        (*paths)[i].id2 = (*islands)[j].id;
		new_second = false;
	    }
	    if (!new_first && !new_second)
	        break;
	}
	if (new_first)
	    mx_add_first(islands, count, paths, i);
	if (new_second)
	    mx_add_second(islands, count, paths, i);
    }
}
