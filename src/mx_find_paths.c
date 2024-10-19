#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

void mx_find_paths(t_island **islands, t_path *paths, int line, int count) {
    for (int i = 0; i < count - 1; i += 1) {
        for (int j = i + 1; j < count; j += 1) {
	    mx_set_weights(islands, paths, line, count, (*islands)[i].name);
	    if ((*islands)[j].usage != -1) {
	        mx_reset_usage(islands, count);
		mx_build_paths(islands, paths,
			       line, count,
			       (*islands)[i].name, (*islands)[j].name,
			       (*islands)[i].name);
	    }
	    mx_nullify_weight(islands, count);
	}
    }
}

