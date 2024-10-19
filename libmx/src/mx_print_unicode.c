#include "../inc/libmx.h"

static int define_size(wchar_t c);
static void write_bytes(unsigned char bytes[4], wchar_t c);

void mx_print_unicode(wchar_t c) {
    unsigned char character_bytes[4];
    int size = define_size(c);

    write_bytes(character_bytes, c);
    write(1, character_bytes, size);
}

static int define_size(wchar_t c) {
    if (c < 128)
        return 1;
    else if (c < 2048)
        return 2;
    else if (c < 65536)
        return 3;
    else if (c < 1114112)
        return 4;
    return 0;
}

static void write_bytes(unsigned char bytes[4], wchar_t c) {
    if (c < 128)
        bytes[0] = ((c >> 0) & 127) | 0;
    else if (c < 2048) {
        bytes[0] = ((c >> 6) & 31) | 192;
        bytes[1] = ((c >> 0) & 63) | 128;
    }
    else if (c < 65536) {
        bytes[0] = ((c >> 12) & 15) | 224;
        bytes[1] = ((c >> 6) & 63) | 128;
        bytes[2] = ((c >> 0) & 63) | 128;
    }
    else if (c < 1114112) {
        bytes[0] = ((c >> 18) & 7) | 240;
        bytes[1] = ((c >> 12) & 63) | 128;
        bytes[2] = ((c >> 6) & 63) | 128;
        bytes[3] = ((c >> 0) & 63) | 128;
    }
}

