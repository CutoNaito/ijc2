// cbuf.c
// Řešení IJC-DU2, příklad 1), 14.4.2024
// Autor: Matěj Šturma, FIT
// Přeloženo: gcc 13.2.1

#include "cbuf.h"

cbuf_t *cbuf_create(unsigned int size)
{
    cbuf_t *cbuf = (cbuf_t*)malloc(sizeof(*cbuf));
    if (cbuf == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory.\n");
        return NULL;
    }

    cbuf->size = size;
    cbuf->index = 0;
    cbuf->buf = malloc(size * sizeof(char*));
    if (cbuf->buf == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory.\n");
        return NULL;
    }

    return cbuf;
}

void cbuf_put(cbuf_t *cbuf, char *line)
{
    if (cbuf->buf[cbuf->index] != NULL) {
        free(cbuf->buf[cbuf->index]);
    }

    cbuf->buf[cbuf->index] = malloc(strlen(line) + 1);
    if (cbuf->buf[cbuf->index] == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory.\n");
        return;
    }

    strcpy(cbuf->buf[cbuf->index], line);

    if (cbuf->buf[cbuf->index][strlen(cbuf->buf[cbuf->index]) - 1] != '\0') {
        strcat(cbuf->buf[cbuf->index], "\0");
    }

    cbuf->index = (cbuf->index + 1) % cbuf->size;
}

char *cbuf_get(cbuf_t *cbuf)
{
    char *line = cbuf->buf[cbuf->index];

    cbuf->buf[cbuf->index] = NULL;
    cbuf->index = (cbuf->index + 1) % cbuf->size;

    return line;
}

void cbuf_free(cbuf_t *cbuf)
{
    for (unsigned int i = 0; i < cbuf->size; i++) {
        if (cbuf->buf[i] != NULL) {
            free(cbuf->buf[i]);
        }
    }

    if (cbuf->buf != NULL) {
        free(cbuf->buf);
    }

    if (cbuf != NULL) {
        free(cbuf);
    }
}
