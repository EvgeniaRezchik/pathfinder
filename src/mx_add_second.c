#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

void mx_add_second(t_island **islands, int *count, t_path **paths, int i) {
    *count += 1;
    *islands = mx_realloc(*islands, *count * sizeof(t_island));
    (*islands)[*count - 1].name = mx_strdup((*paths)[i].second);
    (*islands)[*count - 1].id = *count - 1;
    (*islands)[*count - 1].usage = -1;
    (*islands)[*count - 1].weight = 0;
    (*paths)[i].id2 = (*islands)[*count - 1].id;
}
