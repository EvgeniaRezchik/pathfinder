#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

void mx_read_length(int line, char **s, int file, t_path **paths) {
    int c;

    c = mx_read_line(s, 1, '\n', file);
    if (c < 1)
        mx_delislands_printerr5(line, s, file, paths);
    if (!mx_is_correct_number(*s))
        mx_delislands_printerr5(line, s, file, paths);
    (*paths)[line - 2].length = mx_atol(*s);
    mx_strdel(s);
}

