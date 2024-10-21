#include "../libmx/inc/libmx.h"
#include "../inc/pathfinder.h"

static void handling_errors_p1(int argc, char *argv[], int *file);
static void handling_errors_p2(int file, long *count, char **s, char *name);
static void handling_errors_p3(int *ln, char **s, int file, t_path **paths);
static void handling_errors_p4(t_island **i, int *c,
		               t_path **p, int l, int ic);

int main(int argc, char *argv[]) {
    int file;
    long island_count;
    char *s = NULL;
    t_island *islands = NULL;
    t_path *paths = NULL;
    int line = 2;
    int count = 0;

    handling_errors_p1(argc, argv, &file);
    handling_errors_p2(file, &island_count, &s, argv[1]);
    handling_errors_p3(&line, &s, file, &paths);
    handling_errors_p4(&islands, &count, &paths, line, island_count);
    mx_find_paths(&islands, paths, line - 2, count);
    mx_del_paths(&paths, line);
    mx_del_islands(&islands, count);
}

static void handling_errors_p1(int argc, char *argv[], int *file) {
    if (argc != 2)
        mx_error1();
    *file = open(argv[1], O_RDWR);
    if (*file == -1)
        mx_error2(argv[1]);
}

static void handling_errors_p2(int file, long *count, char **s, char *name) {
    int c;

    c = mx_read_line(s, 1, '\n', file);
    if (c < 0)
        mx_error3(name, s, file);
    if (c < 1 || !mx_is_correct_number(*s))
        mx_error4(s, file);
    *count = mx_atol(*s);
    if (*count > 2147483647)
        mx_error4(s, file);
    mx_strdel(s);
}

static void handling_errors_p3(int *ln, char **s, int file, t_path **paths) {
    while (true) {
        if (mx_read_first_name(*ln, s, file, paths) == -1)
            break;
        if (mx_read_second_name(*ln, s, file, paths) == -1)
            break;
        mx_read_length(*ln, s, file, paths);
        *ln += 1;
    }
    mx_strdel(s);
    close(file);
}

static void handling_errors_p4(t_island **i, int *c,
		               t_path **p, int l, int ic) {
    long int sum = 0;

    mx_fill_islands(i, c, p, l);
    if (*c != ic)
        mx_error6(p, l, i, *c);
    if (!mx_pathscmp(*p, l))
        mx_error7(p, l, i, *c);
    for (int j = 0; j < l - 2; j += 1)
        sum += (*p)[j].length;
    if (sum > 2147483647)
        mx_error8(p, l, i, *c);
}
