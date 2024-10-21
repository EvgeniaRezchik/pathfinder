#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

void mx_find_paths(t_island **islands, t_path *paths, int line, int count) {
    int usage[count];
    for (int i = 0; i < count - 1; i += 1) {
        mx_set_weights(islands, paths, line, count, (*islands)[i].id);
	for (int j = 0; j < count; j += 1)
	    usage[j] = (*islands)[j].usage;
	for (int j = i + 1; j < count; j += 1) {
	    if ((*islands)[j].usage != -1) {
	        mx_reset_usage(islands, count);
		mx_build_paths(islands, paths,
			       line, count,
			       (*islands)[i].id, (*islands)[j].id,
			       (*islands)[i].id, 0);
		for (int k = 0; k < count; k += 1)
		    (*islands)[k].usage = usage[k];
	    }
	}
	mx_reset_usage(islands, count);
	mx_nullify_weight(islands, count);
    }
}
