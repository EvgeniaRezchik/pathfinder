#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

void mx_add_island(t_island **islands, int *count, char *str) {
    *count += 1;
    *islands = mx_realloc(*islands, *count * sizeof(t_island));
    (*islands)[*count - 1].name = mx_strdup(str);
    (*islands)[*count - 1].usage = -1;
    (*islands)[*count - 1].weight = 0;
}

