// htab_bucket_count.c
// Řešení IJC-DU2, příklad 2), 14.4.2024
// Autor: Matěj Šturma, FIT
// Přeloženo: gcc 13.2.1

#include "htab.h"
#include "htab_def.h"

size_t htab_bucket_count(const htab_t *t) 
{
    return t->arr_size;
}
