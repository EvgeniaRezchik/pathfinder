#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

void mx_nullify_weight(t_island **islands, int count) {
    for (int i = 0; i < count; i += 1)
        (*islands)[i].weight = 0;
}

