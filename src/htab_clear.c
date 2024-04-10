#include <stdlib.h>
#include "htab.h"
#include "htab_def.h"

void htab_clear(htab_t *t) 
{
    for (size_t i = 0; i < t->arr_size; i++) {
        htab_item_t *item = t->arr[i];

        while (item != NULL) {
            htab_item_t *next = item->next;

            free((char *)item->pair.key);
            free(item);

            item = next;
        }

        t->arr[i] = NULL;
    }

    t->size = 0;
}
