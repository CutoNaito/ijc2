// htab_init.c
// Řešení IJC-DU2, příklad 2), 14.4.2024
// Autor: Matěj Šturma, FIT
// Přeloženo: gcc 13.2.1

#include <stdio.h>
#include <stdlib.h>
#include "htab.h"
#include "htab_def.h"

htab_t *htab_init(const size_t n) 
{
    htab_t *t = malloc(sizeof(htab_t) + n * sizeof(htab_pair_t *));
    if (t == NULL) {
        return NULL;
    }

    t->size = 0;
    t->arr_size = n;
    for (size_t i = 0; i < n; i++) {
        t->arr[i] = NULL;
    }

    return t;
}
