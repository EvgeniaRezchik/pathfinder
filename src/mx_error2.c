#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

void mx_error2(char *filename) {
    mx_printerr("error: file ");
    mx_printerr(filename);
    mx_printerr(" does not exist\n");
    exit(1);
}

