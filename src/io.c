// io.c
// Řešení IJC-DU2, příklad 2), 14.4.2024
// Autor: Matěj Šturma, FIT
// Přeloženo: gcc 13.2.1

#include <stdlib.h>
#include <string.h>
#include "io.h"

int read_word(char *s, int max, FILE *f)
{
    if (f == NULL) {
        fprintf(stderr, "Error: could not open file\n");
        return 0;
    }

    int i = 0;
    int c;

    while (c = fgetc(f), c != ' ' && c != '\n' && c != '\0') {
        if (feof(f)) {
            return EOF;
        }

        if (i < max - 1) {
            s[i] = c;
            i++;
        } else {
            fprintf(stderr, "Error: buffer overflow\n");
            return 0;
        }
    }

    s[i] = '\0';

    return i;
}
