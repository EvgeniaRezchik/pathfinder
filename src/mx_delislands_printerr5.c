#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

void mx_delislands_printerr5(int line, char **s, int file, t_path **paths) {
    mx_strdel(&(*paths)[line - 2].first);
    mx_strdel(&(*paths)[line - 2].second);
    mx_error5(line, s, file, paths);
}

