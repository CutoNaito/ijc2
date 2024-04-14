// htab_erase.c
// Řešení IJC-DU2, příklad 2), 14.4.2024
// Autor: Matěj Šturma, FIT
// Přeloženo: gcc 13.2.1

#include <stdlib.h>
#include "htab.h"
#include "htab_def.h"

bool htab_erase(htab_t *t, htab_key_t key) 
{
    size_t index = htab_hash_function(key) % t->arr_size;
    htab_item_t *item = t->arr[index];
    htab_item_t *prev = NULL;

    while (item != NULL) {
        if (item->pair.key == key) {
            if (prev == NULL) {
                t->arr[index] = item->next;
            } else {
                prev->next = item->next;
            }

            free(item);
            t->size--;
            return true;
        }

        prev = item;
        item = item->next;
    }

    return false;
}
