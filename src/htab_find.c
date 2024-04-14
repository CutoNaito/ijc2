// htab_find.c
// Řešení IJC-DU2, příklad 2), 14.4.2024
// Autor: Matěj Šturma, FIT
// Přeloženo: gcc 13.2.1

#include <stdlib.h>
#include "htab.h"
#include "htab_def.h"

htab_pair_t *htab_find(const htab_t *t, htab_key_t key) 
{
    size_t index = htab_hash_function(key) % t->arr_size;
    htab_item_t *item = t->arr[index];

    while (item != NULL) {
        if (item->pair.key == key) {
            return &item->pair;
        }

        item = item->next;
    }

    return NULL;
}
