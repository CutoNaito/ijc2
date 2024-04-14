// htab_free.c
// Řešení IJC-DU2, příklad 2), 14.4.2024
// Autor: Matěj Šturma, FIT
// Přeloženo: gcc 13.2.1

#include <stdlib.h>
#include "htab.h"
#include "htab_def.h"

void htab_free(htab_t *t) 
{
    htab_clear(t);

    if (t != NULL) {
        free(t);
    }
}
