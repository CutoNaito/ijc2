// htab_size.c
// Řešení IJC-DU2, příklad 2), 14.4.2024
// Autor: Matěj Šturma, FIT
// Přeloženo: gcc 13.2.1

#include "htab.h"
#include "htab_def.h"

size_t htab_size(const htab_t *t) 
{
    return t->size;
}
