#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

void mx_delfirst_printerr5(int line, char **s, int file, t_path **paths) {
    mx_strdel(&(*paths)[line - 2].first);
    mx_error5(line, s, file, paths);
}

