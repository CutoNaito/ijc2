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
    cbuf->buf[cbuf->index] = line;
    cbuf->index = (cbuf->index + 1) % cbuf->size;
}

char *cbuf_get(cbuf_t *cbuf)
{
    printf("cbuf->index: %d\n", cbuf->index);
    char *line = cbuf->buf[cbuf->index];
    cbuf->index = (cbuf->index + 1) % cbuf->size;

    return line;
}

void cbuf_free(cbuf_t *cbuf)
{
    if (cbuf->buf != NULL) {
        free(cbuf->buf);
    }

    if (cbuf != NULL) {
        free(cbuf);
    }
}
