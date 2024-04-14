// htab_statistics.c
// Řešení IJC-DU2, příklad 2), 14.4.2024
// Autor: Matěj Šturma, FIT
// Přeloženo: gcc 13.2.1

#include <stdio.h>
#include <stdlib.h>
#include "htab.h"
#include "htab_def.h"

void htab_statistics(const htab_t *t) 
{
    size_t max = 0;
    size_t min = 0;
    size_t avg = 0;

    for (size_t i = 0; i < t->arr_size; i++) {
        size_t count = 0;
        htab_item_t *item = t->arr[i];

        while (item != NULL) {
            count++;
            item = item->next;
        }

        if (i == 0 || count < min) {
            min = count;
        }

        if (i == 0 || count > max) {
            max = count;
        }

        avg += count;
    }

    fprintf(stderr, "min: %zu\n", min);
    fprintf(stderr, "max: %zu\n", max);
    fprintf(stderr, "avg: %zu\n", avg / t->arr_size);
}
