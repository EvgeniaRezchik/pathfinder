#include "../inc/libmx.h"

static char *write_with_replaces(const char *str, const char *sub, const char *replace, int count, char *result);

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if (sub == NULL || str == NULL || replace == NULL)
        return NULL;
    int replacelen = mx_strlen(replace);
    const char *temp = mx_strstr(str, sub);
    int count = 0;

    while (temp != NULL && mx_strlen(sub) != 0) {
        temp += mx_strlen(sub);
        temp = mx_strstr(temp, sub);
        count += 1;
    }
    int size = mx_strlen(str) - mx_strlen(sub) * count + replacelen * count;
    char *result = mx_strnew(size);

    if (result == NULL)
        return NULL;
    result = write_with_replaces(str, sub, replace, count, result);
    result[size] = 0;
    return result;
}

static char *write_with_replaces(const char *str, const char *sub, const char *replace, int count, char *result) {
    const char *temp = mx_strstr(str, sub);
    int i = 0;
    const char *c1 = str;
    while (*c1 != '\0') {
        if (c1 == temp && count != 0) {
            for (const char *c2 = replace; *c2 != '\0'; c2 += 1) {
                result[i] = *c2;
                i += 1;
            }
            temp += mx_strlen(sub);
            temp = mx_strstr(temp, sub);
            c1 += mx_strlen(sub);
        }
        else {
            result[i] = *c1;
            i += 1;
            c1 += 1;
        }
    }
    return result;
}

