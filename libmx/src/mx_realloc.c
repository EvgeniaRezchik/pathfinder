#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    if (ptr == NULL) {
        ptr = malloc(size);

	return ptr;
    }
    else if (size == 0 && ptr != NULL) {
        free(ptr);
	return NULL;
    }
    else if (size < malloc_usable_size(ptr))
        return ptr;
    else {
        void *new_ptr = malloc(size);

	if (new_ptr == NULL)
	    return new_ptr;
	mx_memcpy(new_ptr, ptr, malloc_usable_size(ptr));
	free(ptr);
	return new_ptr;
    }
}

