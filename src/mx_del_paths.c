#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

void mx_del_paths(t_path **paths, int line) {
    for (int i = 0; i < line - 2; i += 1) {
        if ((*paths)[i].first != NULL)
	    mx_strdel(&(*paths)[i].first);
	if ((*paths)[i].second != NULL)
	    mx_strdel(&(*paths)[i].second);
    }
    free(*paths);
    *paths = NULL;
}

