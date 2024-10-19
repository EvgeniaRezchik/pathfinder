#include "../inc/libmx.h"

static int count_length(const char *filename);
static void read_in_str(char **str, const char *filename, int length);

char *mx_file_to_str(const char *file) {
    int length = count_length(file);
    char *string = mx_strnew(length);

    if (string == NULL)
        return NULL;
    read_in_str(&string, file, length);
    return string;
}

static int count_length(const char *filename) {
    int fd = open(filename, O_RDWR);
    int length = 0;
    char buffer;

    if (fd == -1)
        return 0;
    while (read(fd, &buffer, 1) != 0)
        length += 1;
    close(fd);
    return length;
}

static void read_in_str(char **str, const char *filename, int length) {
    int fd = open(filename, O_RDWR);

    if (fd == -1) {
        free(*str);
	*str = NULL;
	return;
    }
    read(fd, *str, length);
    close(fd);
    return;
}

