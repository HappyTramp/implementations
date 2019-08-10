#ifndef __HEAP_H__
# define __HEAP_H__

# include <string.h>
# include "vector.h"

/* max heap */
typedef Vector Heap;

Heap *heap_new(void);
void heap_destroy(Heap **heap, void (*free_fn)(void *));
void *heap_find_max(Heap *heap);
void heap_insert(Heap *heap, void *data, int (*compar)(const void *, const void *));
void *heap_extract_max(Heap *heap);
void heap_stash_max(Heap *heap, int (*compar)(const void *, const void *));
void heap_delete_max(Heap *heap, void (*free_fn)(void *),
                     int (*compar)(const void *, const void *));
Heap *heap_heapify(void **datas, size_t size,
                   int (*compar)(const void *, const void *));
void heap_heapify_array(void **datas, size_t size,
                        int (*compar)(const void *, const void *));
// pop followed by push, can be optimized
/* void *heap_replace(Heap *heap, void *data, int (*compar)(const void *, const void *)); */
void sift_up(Heap *heap, size_t i, int (*compar)(const void *, const void *));
void sift_down(Heap *heap, size_t i, int (*compar)(const void *, const void *));
void *heap_left(Heap *heap, size_t i);
void *heap_right(Heap *heap, size_t i);
void *heap_parent(Heap *heap, size_t i);

#endif
