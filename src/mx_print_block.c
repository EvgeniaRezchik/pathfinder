#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

void mx_print_block(t_island *i, t_path *p, int l, int d, int ds) {
    mx_printstr("========================================\nPath: ");
    mx_printstr(i[d].name);
    mx_printstr(" -> ");
    mx_printstr(i[ds].name);
    mx_printstr("\nRoute: ");
    mx_print_route(i, p, l, d, ds);
    mx_printstr("\nDistance: ");
    mx_print_dist(i, p, l, d, ds);
    mx_printstr("\n========================================\n");
}
