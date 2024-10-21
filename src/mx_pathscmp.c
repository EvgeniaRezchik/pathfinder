#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

bool mx_pathscmp(t_path *paths, int line) {
    for (int i = 0; i < line - 2; i += 1) {
        for (int j = i + 1; j < line - 2; j += 1) {
	    if ((paths[i].id1 == paths[j].id1
		&& paths[i].id2 == paths[j].id2)
		|| (paths[i].id1 == paths[j].id2
		&& paths[i].id2 == paths[j].id1))
	        return false;
	}
    }
    return true;
}
