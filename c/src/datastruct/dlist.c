#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dlist.h"

DList* dlist_create_elem(void *data)
{
    DList* dlist = malloc(sizeof(DList));
    if (dlist == NULL)
        return NULL;
    dlist->prev = NULL;
    dlist->next = NULL;
    dlist->data = data;
    return dlist;
}

void dlist_destroy(DList **dlist, void (*free_fn)(void *))
{
    dlist_clear(dlist, free_fn);
    *dlist = NULL;
}

void dlist_clear(DList **dlist, void (*free_fn)(void *))
{
    while (dlist != NULL)
        dlist_pop_front(dlist, free_fn);
}

void dlist_push_front(DList **dlist, void *data)
{
    DList *new_front = dlist_create_elem(data);
    if (new_front == NULL)
        return;
    new_front->next = *dlist;
    *dlist = new_front;
}

void dlist_push_back(DList **dlist, void *data)
{
    DList *new_back = dlist_create_elem(data);
    if (new_back == NULL)
        return;
    new_back->prev = *dlist;
    if (*dlist == NULL)
    {
        *dlist = new_back;
        return;
    }
    while (new_back->prev->next != NULL)
        new_back->prev = new_back->prev->next;
}

void dlist_pop_front(DList **dlist, void (*free_fn)(void *))
{
    if (*dlist == NULL)
        return;
    DList *new_front = (*dlist)->next;
    new_front->prev = NULL;
    free_fn((*dlist)->data);
    free(*dlist);
    *dlist = new_front;
}

void dlist_pop_back(DList **dlist, void (*free_fn)(void *))
{
    if (*dlist == NULL)
        return;
    DList *new_back = *dlist;
    while (new_back->next != NULL)
        new_back = new_back->next;
    free_fn(new_back->data);
    if (new_back->prev == NULL)
    {
        free(new_back);
        *dlist = NULL;
        return;
    }
    new_back = new_back->prev;
    free(new_back->next);
    new_back->next = NULL;
}
