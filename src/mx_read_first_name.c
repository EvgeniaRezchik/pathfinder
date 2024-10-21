#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

int mx_read_first_name(int line, char **s, int file, t_path **paths) {
    int c;

    c = mx_read_line(s, 1, '-', file);
    if (c < 1) {
        if (c == -1)
	    return c;
	else
	    mx_error5(line, s, file, paths);
    }
    if (!mx_check_name(*s))
        mx_error5(line, s, file, paths);
    *paths = mx_realloc(*paths, (line - 1) * sizeof(t_path));
    (*paths)[line - 2].first = mx_strdup(*s);
    (*paths)[line - 2].id1 = -1;
    (*paths)[line - 2].second = NULL;
    (*paths)[line - 2].id2 = -1;
    mx_strdel(s);
    return c;
}
