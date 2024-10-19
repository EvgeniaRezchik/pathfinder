#include "../inc/libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    bool swap1 = false;

    if (lst == NULL || cmp == NULL)
        return lst;
    while (!swap1) {
	bool swap2 = false;
	t_list *temp = lst;
	while (temp->next != NULL) {
	    if (cmp(temp->data, temp->next->data)) {
	        void *buffer = temp->data;
		temp->data = temp->next->data;
		temp->next->data = buffer;
		swap2 = true;
	    }
	    temp = temp->next;
	}
	if (!swap2)
	    swap1 = true;
    }
    return lst;
}

