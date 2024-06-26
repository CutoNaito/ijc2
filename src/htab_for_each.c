// htab_for_each.c
// Řešení IJC-DU2, příklad 2), 14.4.2024
// Autor: Matěj Šturma, FIT
// Přeloženo: gcc 13.2.1

#include "htab.h"
#include "htab_def.h"

void htab_for_each(const htab_t *t, void (*f)(htab_pair_t *)) 
{
    for (size_t i = 0; i < t->arr_size; i++) {
        htab_item_t *item = t->arr[i];

        while (item != NULL) {
            f(&item->pair);
            item = item->next;
        }
    }
}
