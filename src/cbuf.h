// cbuf.h
// Řešení IJC-DU2, příklad 1), 14.4.2024
// Autor: Matěj Šturma, FIT
// Přeloženo: gcc 13.2.1

#ifndef __TAIL_
#define __TAIL_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 2047

/*
 *  Structure cbuf_t represents a circular buffer.
 * */
typedef struct {
    char **buf;
    unsigned int index;
    unsigned int size;
} cbuf_t;

/*
 *  Function cbuf_create creates a circular buffer with a given size.
 *
 *  Return value is a pointer to the circular buffer.
 * */
cbuf_t *cbuf_create(unsigned int size);

/*
 *  Function cbuf_put puts a line into the circular buffer.
 * */
void cbuf_put(cbuf_t *cbuf, char *line);

/*
 *  Function cbuf_get gets a line from the circular buffer.
 *
 *  Return value is a pointer to the line.
 * */
char *cbuf_get(cbuf_t *cbuf);

/*
 *  Function cbuf_free frees the circular buffer.
 * */
void cbuf_free(cbuf_t *cbuf);

#endif
