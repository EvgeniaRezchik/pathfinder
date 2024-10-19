#include "../inc/libmx.h"

static void fill_arr(char **arr, const char *s, char c, int i);

char **mx_strsplit(const char *s, char c) {
    int i = 0;

    if (s == NULL)
        return NULL;
    int words = mx_count_words(s, c);
    char **arr = (char **)malloc((words + 1) * sizeof(char *));

    if (arr == NULL)
        return NULL;
    arr[words] = NULL;
    if (words > 0)
        fill_arr(arr, s, c, i);
    return arr;
}

static void fill_arr(char **arr, const char *s, char c, int i) {
    for (int j = 0; s[j] != 0; j += 1) {
        if (s[j] == c) {
	    j += 1;
	    while (s[j] == c)
	        j += 1;
	}
	int size = 0;
	for (int k = j; s[k] != c && s[k] != 0; k += 1)
	    size += 1;
	arr[i] = mx_strnew(size);
	if (arr[i] == NULL) {
	    for (int l = 0; l < i; l += 1)
	        mx_strdel(&arr[l]);
	    free(arr);
	    return;
	}
	mx_strncpy(arr[i], &s[j], size);
	j += size - 1;
	i += 1;
    }
}

