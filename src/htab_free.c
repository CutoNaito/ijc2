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
