#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

void mx_error3(char *filename, char **s, int file) {
    mx_printerr("error: file ");
    mx_printerr(filename);
    mx_printerr(" is empty\n");
    mx_strdel(s);
    close(file);
    exit(1);
}

