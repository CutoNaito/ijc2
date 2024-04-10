#include <stdlib.h>
#include "htab.h"
#include "htab_def.h"

htab_pair_t *htab_lookup_add(htab_t *t, htab_key_t key) 
{
    size_t index = htab_hash_function(key) % t->arr_size;
    htab_item_t *item = t->arr[index];

    while (item != NULL) {
        if (strcmp(item->pair.key, key) == 0) {
            return &item->pair;
        }

        item = item->next;
    }

    item = malloc(sizeof(htab_item_t));
    if (item == NULL) {
        return NULL;
    }

    item->pair.key = (const char *)malloc(sizeof(char) * (strlen(key) + 1));
    if (item->pair.key == NULL) {
        free(item);
        return NULL;
    }

    strcpy((char *)item->pair.key, key);

    item->pair.value = 0;

    item->next = t->arr[index];
    t->arr[index] = item;
    t->size++;

    htab_pair_t *pair = &item->pair;

    return pair;
}
