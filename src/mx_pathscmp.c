#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

bool mx_pathscmp(t_path *paths, int line) {
    for (int i = 0; i < line - 2; i += 1) {
        for (int j = i + 1; j < line - 2; j += 1) {
	    if ((mx_strcmp(paths[i].first, paths[j].first) == 0
		&& mx_strcmp(paths[i].second, paths[j].second) == 0)
		|| (mx_strcmp(paths[i].first, paths[j].second) == 0
		&& mx_strcmp(paths[i].second, paths[j].first) == 0))
	        return false;
	}
    }
    return true;
}

