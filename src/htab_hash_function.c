#include "htab.h"
#include "htab_def.h"

size_t htab_hash_function(htab_key_t str) 
{
    size_t h = 0;
    const unsigned char *p;

    for (p = (const unsigned char *)str; *p != '\0'; p++) {
        h = 65599 * h + *p;
    }

    return h;
}
