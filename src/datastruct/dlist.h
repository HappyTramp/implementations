#ifndef __DLIST_H__
# define __DLIST_H__

# include <stdbool.h>

typedef struct DList {
    struct DList* prev;
    struct DList* next;
    void *data;
} DList;

DList* dlist_create_elem(void *data);
void dlist_destroy(DList **dlist, void (*free_fn)(void *));
void dlist_clear(DList **dlist, void (*free_fn)(void *));
void dlist_push_front(DList **dlist, void *data);
void dlist_push_back(DList **dlist, void *data);
void dlist_pop_front(DList **dlist, void (*free_fn)(void *));
void dlist_pop_back(DList **dlist, void (*free_fn)(void *));

#endif
