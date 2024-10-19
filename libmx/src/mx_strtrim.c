#include "../inc/libmx.h"

static bool is_space(char c);

char *mx_strtrim(const char *str) {
    int i = 0;
    char *result;

    if (str == NULL)
        return NULL;
    int len = mx_strlen(str);
    int j = len - 1;

    while (is_space(str[i]))
        i += 1;
    while (is_space(str[j]) && j > 0)
        j -= 1;
    if (i == len)
        result = mx_strnew(0);
    else
        result = mx_strnew(j - i + 1);
    if (result == NULL)
        return NULL;
    mx_strncpy(result, &str[i], j - i + 1);
    return result;
}

static bool is_space(char c) {
    if (((c >= 9) && (c <= 13)) || (c == 32))
        return true;
    else
        return false;
}

