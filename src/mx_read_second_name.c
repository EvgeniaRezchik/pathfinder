#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

int mx_read_second_name(int line, char **s, int file, t_path **paths) {
    int c;

    c = mx_read_line(s, 1, ',', file);
    if (c < 1) {
        if (c == -1)
	    return c;
	else
	    mx_delfirst_printerr5(line, s, file, paths);
    }
    if (!mx_check_name(*s))
        mx_delfirst_printerr5(line, s, file, paths);
    (*paths)[line - 2].second = mx_strdup(*s);
    if (mx_strcmp((*paths)[line - 2].second, (*paths)[line - 2].first) == 0)
        mx_delislands_printerr5(line, s, file, paths);
    mx_strdel(s);
    return c;
}
