#include <string.h>
#include "sorting.h"

void insertion(void *base, size_t nmemb, size_t size,
		       int (*compar)(const void *, const void *))
{
    for (int i = 0; i < nmemb; i++)
        for (int j = i; j > 0 && compar(base + (j - 1) * size, base + j * size) > 0; j--)
            swap(base + (j - 1) * size, base + j * size, size);
}
