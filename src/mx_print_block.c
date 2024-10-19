#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

void mx_print_block(t_island *i, t_path *p, int l, int c, char *d, char *ds) {
    mx_printstr("========================================\nPath: ");
    mx_printstr(i[mx_index(d, i, c)].name);
    mx_printstr(" -> ");
    mx_printstr(i[mx_index(ds, i, c)].name);
    mx_printstr("\nRoute: ");
    mx_print_route(i, p, l, c, d, ds);
    mx_printstr("\nDistance: ");
    mx_print_dist(i, p, l, c, d, ds);
    mx_printstr("\n========================================\n");
}

