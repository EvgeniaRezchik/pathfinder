#include "../inc/libmx.h"

static void spaces_words(char *s, int *len);
static bool is_space(char c);
static void copy_string(int len, char *s1, char *s2);

char *mx_del_extra_spaces(const char *str) {
    char *str1 = mx_strtrim(str);

    if (str1 == NULL)
        return NULL;
    int len = mx_strlen(str1);

    spaces_words(str1, &len);
    char *str2 = mx_strnew(len);

    if (str2 == NULL) {
        mx_strdel(&str1);
	return NULL;
    }
    copy_string(len, str1, str2);
    mx_strdel(&str1);
    return str2;
}

static void spaces_words(char *s, int *len) {
    int spaces = 0;
    int words = 1;

    for (int i = 0; s[i] != 0; i += 1) {
        if (is_space(s[i])) {
            spaces += 1;
            if (!is_space(s[i + 1]))
                words += 1;
        }
    }
    *len = *len - spaces + words - 1;
}

static bool is_space(char c) {
    if (((c >= 9) && (c <= 13)) || (c == 32))
        return true;
    else
        return false;
}

static void copy_string(int len, char *s1, char *s2) {
    char buffer[len];
    int i = 0;

    for (int j = 0; s1[j] != 0; j += 1) {
        if (is_space(s1[j])) {
            buffer[i] = ' ';
            i += 1;
            j += 1;
            while (is_space(s1[j]))
                j += 1;
        }
        buffer[i] = s1[j];
        i += 1;
    }
    mx_strncpy(s2, buffer, len);
}

