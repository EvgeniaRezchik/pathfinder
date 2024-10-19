#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <unistd.h>

typedef struct s_island {
    char *name;
    int usage;
    unsigned int weight;
}              t_island;

typedef struct s_path {
    char *first;
    char *second;
    unsigned int length;
}              t_path;

void mx_printerr(const char *s);
bool mx_isdigit(int c);
bool mx_isspace(int c);
bool mx_isalpha(int c);
bool mx_is_correct_number(char *string);
long mx_atol(const char *nptr);
void mx_error1(void);
void mx_error2(char *filename);
void mx_error3(char *filename, char **s, int file);
void mx_error4(char **s, int file);
void mx_error5(int line, char **s, int file, t_path **paths);
void mx_error6(t_path **paths, int line, t_island **islands, int count);
void mx_error7(t_path **paths, int line, t_island **islands, int count);
void mx_error8(t_path **paths, int line, t_island **islands, int count);
bool mx_check_name(char *name);
int mx_read_first_name(int line, char **s, int file, t_path **paths);
int mx_read_second_name(int line, char **s, int file, t_path **paths);
void mx_read_length(int line, char **s, int file, t_path **paths);
void mx_del_paths(t_path **paths, int line);
void mx_del_islands(t_island **islands, int count);
void mx_delfirst_printerr5(int line, char **s, int file, t_path **paths);
void mx_delislands_printerr5(int line, char **s, int file, t_path **paths);
void mx_fill_islands(t_island **islands, int *count, t_path *paths, int ln);
void mx_add_island(t_island **islands, int *count, char *str);
bool mx_pathscmp(t_path *paths, int line);
void mx_find_paths(t_island **islands, t_path *paths, int line, int count);
int mx_index(char *str, t_island *islands, int count);
void mx_set_weights(t_island **il, t_path *p, int ln, int count, char *dpr);
void mx_set_bool(t_island **il, t_path *p, char *d, int i,
		 int j, int c, int co, bool *s);
void mx_build_paths(t_island **il, t_path *p, int l,
		    int c, char *d, char *ds, char *s);
void mx_pave_ways(t_island **il, t_path *p, int l, int c,
		  char *d, char *ds, char *s, int i);
void mx_print_block(t_island *i, t_path *p, int l, int c, char *d, char *ds);
void mx_print_route(t_island *il, t_path *p, int l, int c, char *d, char *ds);
int mx_print_way(t_island *il, t_path *p, char *ds, int c, int *curr, int i);
void mx_print_dist(t_island *il, t_path *p, int l, int c, char *d, char *ds);
int mx_print_sign(t_island *il, t_path *p, char *d,
		  char *ds, int c, int *cu, int i);
void mx_reset_usage(t_island **islands, int count);
void mx_nullify_weight(t_island **islands, int count);

#endif

