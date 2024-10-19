#include "../inc/libmx.h"

static int if_function(int *a1, char **static_buffer, char **lineptr, char c, int *a2, int a3, bool *reset);
static void fill_buffer(int *a1, char *buffer, char c, int *a2, int a3, char **lineptr);
static void fill_static(char **static_buffer, int a1, int a2, char *buffer, int start);
static int while_function(int *a1, char *buffer, char c, int *a2, int a3, char **lineptr, char **static_buffer, bool *reset);

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    static char *static_buffer = NULL;
    int res = 0;
    int delim_index = -1;
    int a = 0;
    bool concat = false;
    bool reset = true;
    char buffer[buf_size + 1];
    buffer[buf_size] = 0;
    int readed = read(fd, buffer, buf_size);
    if (readed < 0 || (readed == 0 && static_buffer == NULL))
        return readed < 0 ? -2 : -1;
    if (static_buffer != NULL) {
        int stat_len = mx_strlen(static_buffer);
	static_buffer = mx_realloc(static_buffer, stat_len + readed + 1);
	if (static_buffer == NULL)
	    return -2;
	static_buffer = mx_strcat(static_buffer, buffer);
	static_buffer[stat_len + readed] = 0;
	concat = true;
	stat_len = mx_strlen(static_buffer);
	a = if_function(&delim_index, &static_buffer, lineptr, delim, &res, stat_len, &reset);
	if (a < 0)
	    return -2;
    }
    while (static_buffer == NULL && a == 0) {
        if (!concat) {
	    a = while_function(&delim_index, buffer, delim, &res, readed, lineptr, &static_buffer, &reset);
	    if (a < 0)
	        return -2;
	}
	if (static_buffer == NULL && a == 0) {
	    readed = read(fd, buffer, buf_size);
	    if (readed <= 0)
	        return readed < 0 ? -2: readed == 0 && res == 0 ? -1 : res;
	    concat = false;
	}
    }
    return res;
}

static int if_function(int *a1, char **static_buffer, char **lineptr, char c, int *a2, int a3, bool *reset) {
    char stat_rests[a3 - *a1 - 1];

    *lineptr = NULL;
    *reset = false;
    fill_buffer(a1, *static_buffer, c, a2, a3, lineptr);
    if (*lineptr == NULL)
        return -1;
    if (*a1 >= 0) {
        for (int i = 0; i < a3 - *a1 - 1; i += 1)
	    stat_rests[i] = (*static_buffer)[*a1 + 1 + i];
    }
    mx_strdel(static_buffer);
    if (*a1 >= 0 && a3 - *a1 - 1 > 0) {
        fill_static(static_buffer, a3, *a1, stat_rests, 0);
	if (*static_buffer == NULL)
	    return -2;
    }
    return *a1 >= 0 && *static_buffer == NULL ? 1 : 0;
}

static void fill_buffer(int *a1, char *buffer, char c, int *a2, int a3, char **lineptr) {
    int temp = *a2;

    *a1 = mx_get_char_index(buffer, c);
    *a2 += *a1 >= 0 ? *a1 : a3;
    *lineptr = mx_realloc(*lineptr, sizeof(char) * (*a2 + 1));
    if (*lineptr == NULL)
        return;
    (*lineptr)[*a2] = 0;
    for (int i = 0; i < *a1 || (*a1 < 0 && i < a3); i += 1)
        (*lineptr)[temp + i] = buffer[i];
}

static void fill_static(char **static_buffer, int a1, int a2, char *buffer, int start) {
    *static_buffer = mx_strnew(a1 - a2 - 1);
    if (*static_buffer == NULL)
        return;
    for (int i = 0; i < a1 - a2 - 1; i += 1)
        (*static_buffer)[i] = buffer[start + i];
}

static int while_function(int *a1, char *buffer, char c, int *a2, int a3, char **lineptr, char **static_buffer, bool *reset) {
    if (*reset) {
        *lineptr = NULL;
	*reset = false;
    }
    fill_buffer(a1, buffer, c, a2, a3, lineptr);
    if (*lineptr == NULL)
        return -1;
    if (*a1 >= 0 && a3 - *a1 - 1 > 0) {
        fill_static(static_buffer, a3, *a1, buffer, *a1 + 1);
	if (*static_buffer == NULL)
	    return -2;
    }
    return *a1 >= 0 && *static_buffer == NULL ? 1 : 0;
}

