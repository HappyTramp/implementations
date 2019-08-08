#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "doublylinkedlist.h"


static bool empty(DLList* dlist);
static DLListNode* new_element(
    DLListNode* next,
    DLListNode* prev,
    int value
);

// create a new dlist
DLList* dlist_new(void)
{
    DLList* dlist = malloc(sizeof(DLList));
    dlist->front = NULL;
    dlist->rear = NULL;
    dlist->length = 0;
    return dlist;
}

// destroy the dlist
DLList* dlist_destroy(DLList* dlist)
{
    while (!empty(dlist))
        dlist_pop_front(dlist);
    free(dlist);
    return NULL;
}

// push new element at the front
DLList* dlist_push_front(DLList* dlist, int value)
{
    DLListNode* new_front = new_element(dlist->front, NULL, value);
    if (new_front == NULL)
        exit(1);

    if (!empty(dlist))
        dlist->front->prev = new_front;
    else
        dlist->rear = new_front;
    dlist->front = new_front;
    dlist->length++;
    return dlist;
}

// push new element at the end
DLList* dlist_push_back(DLList* dlist, int value)
{
    DLListNode* new_rear = new_element(NULL, dlist->rear, value);
    if (new_rear == NULL)
        exit(1);

    if (!empty(dlist))
        dlist->rear->next = new_rear;
    else
        dlist->front = new_rear;
    dlist->rear = new_rear;
    dlist->length++;
    return dlist;
}

// remove front element
DLList* dlist_pop_front(DLList* dlist)
{
    if (empty(dlist))
        exit(1);
    DLListNode* new_front = dlist->front->next;
    free(dlist->front);
    dlist->front = new_front;
    dlist->length--;
    if (new_front == NULL)
        dlist->rear = new_front;
    else
        new_front->prev = NULL;
    return dlist;
}

// remove rear element
DLList* dlist_pop_back(DLList* dlist)
{
    if (empty(dlist))
        exit(1);
    DLListNode* new_rear = dlist->rear->prev;
    free(dlist->rear);
    dlist->rear = new_rear;
    dlist->length--;
    if (new_rear == NULL)
        dlist->front = new_rear;
    else
        new_rear->next = NULL;
    return dlist;
}

// check if the dlist is empty
static bool empty(DLList* dlist)
{
    return dlist->length == 0
        && dlist->front == NULL
        && dlist->rear == NULL;
}

// create a new dlist element
static DLListNode* new_element(
    DLListNode* next, DLListNode* prev, int value)
{
    DLListNode* elt = malloc(sizeof(DLListNode));
    elt->next = next;
    elt->prev = prev;
    elt->value = value;
    return elt;
}

// print a string representation of dlist
void dlist_print(DLList* dlist)
{
    DLListNode* cursor = dlist->front;
    printf("dlist at %p of length %d: ", dlist, dlist->length);
    while (cursor != NULL) {
        printf("<%d> ", cursor->value);
        cursor = cursor->next;
    }
    printf("\n");
}
