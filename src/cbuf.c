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
    cbuf->buf = (char**)malloc(size);
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
    char *line = cbuf->buf[0];

    for (unsigned i = 1; i < cbuf->size; i++) {
        cbuf->buf[i - 1] = cbuf->buf[i];
    }

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
