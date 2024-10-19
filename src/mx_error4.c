#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

void mx_error4(char **s, int file) {
    mx_printerr("error: line 1 is not valid\n");
    mx_strdel(s);
    close(file);
    exit(1);
}

