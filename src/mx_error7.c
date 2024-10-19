#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

void mx_error7(t_path **paths, int line, t_island **islands, int count) {
    mx_printerr("error: duplicate bridges\n");
    mx_del_paths(paths, line);
    mx_del_islands(islands, count);
    exit(1);
}

