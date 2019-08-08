#ifndef __H_QUEUE__
#define __H_QUEUE__

#include <stdio.h>
#include <stdbool.h>

typedef struct DLListNode {
    struct DLListNode* prev;
    struct DLListNode* next;
    int value;
} DLListNode;

typedef struct DLList {
    DLListNode* front;
    DLListNode* rear;
    unsigned int length;
} DLList;


DLList* dlist_new(void);
DLList* dlist_destroy(DLList* dlist);
DLList* dlist_push_front(DLList* dlist, int value);
DLList* dlist_push_back(DLList* dlist, int value);
DLList* dlist_pop_front(DLList* dlist);
DLList* dlist_pop_back(DLList* dlist);
void dlist_print(DLList* dlist);

#endif
