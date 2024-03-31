#ifndef __TAIL_
#define __TAIL_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 2047

typedef struct {
    char **buf;
    unsigned int index;
    unsigned int size;
} cbuf_t;

cbuf_t *cbuf_create(unsigned int size);
void cbuf_put(cbuf_t *cbuf, char *line);
char *cbuf_get(cbuf_t *cbuf);
void cbuf_free(cbuf_t *cbuf);

#endif
