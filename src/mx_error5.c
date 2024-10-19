#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

void mx_error5(int line, char **s, int file, t_path **paths) {
    char *linenum;

    mx_printerr("error: line ");
    linenum = mx_itoa(line);
    mx_printerr(linenum);
    mx_strdel(&linenum);
    mx_printerr(" is not valid\n");
    mx_strdel(s);
    close(file);
    if (*paths != NULL)
        mx_del_paths(paths, line);
    exit(1);
}

