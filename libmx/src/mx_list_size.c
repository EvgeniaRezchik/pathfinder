#include "../inc/libmx.h"

int mx_list_size(t_list *list) {
    t_list *temp = list;
    int size = 0;

    while (temp != NULL) {
        temp = temp->next;
	size += 1;
    }
    return size;
}

