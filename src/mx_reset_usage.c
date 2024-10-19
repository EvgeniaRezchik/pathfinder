#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

void mx_reset_usage(t_island **islands, int count) {
    for (int i = 0; i < count; i += 1)
        (*islands)[i].usage = -1;
}

