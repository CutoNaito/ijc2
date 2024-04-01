#include <stdio.h>
#include <stdlib.h>
#include "htab.h"

typedef struct htab_item htab_item_t;
struct htab_item {
    htab_pair_t pair;
    htab_item_t *next;
};

struct htab {
    size_t size;
    size_t arr_size;
    htab_item_t *arr[];
};

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

size_t htab_size(const htab_t *t) 
{
    return t->size;
}

size_t htab_bucket_count(const htab_t *t) 
{
    return t->arr_size;
}

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

htab_pair_t *htab_lookup_add(htab_t *t, htab_key_t key) 
{
    size_t index = htab_hash_function(key) % t->arr_size;
    htab_item_t *item = t->arr[index];

    while (item != NULL) {
        if (item->pair.key == key) {
            return &item->pair;
        }

        item = item->next;
    }

    item = malloc(sizeof(htab_item_t));
    if (item == NULL) {
        return NULL;
    }

    item->pair.key = key;
    item->pair.value = 0;
    item->next = t->arr[index];
    t->arr[index] = item;
    t->size++;

    htab_pair_t *pair = &item->pair;

    if (item != NULL) {
        free(item);
    }

    return pair;
}

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

void htab_clear(htab_t *t) 
{
    for (size_t i = 0; i < t->arr_size; i++) {
        htab_item_t *item = t->arr[i];

        while (item != NULL) {
            htab_item_t *next = item->next;
            free(item);
            item = next;
        }

        t->arr[i] = NULL;
    }

    t->size = 0;
}

void htab_free(htab_t *t) 
{
    htab_clear(t);

    if (t != NULL) {
        free(t);
    }
}

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
