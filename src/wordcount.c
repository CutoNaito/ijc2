#include <stdio.h>
#include "htab.h"

void print_pair(htab_pair_t *pair)
{
    printf("%s\t%d\n", pair->key, pair->value);
}

int main(void)
{
    htab_t *t = htab_init(10);

    char buffer[100];

    while (fgets(buffer, 100, stdin) != NULL) {
        htab_lookup_add(t, buffer);
    }

    htab_for_each(t, print_pair);

    return 0;
}
