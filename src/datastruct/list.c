#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "logger.h"
#include "linkedlist.h"


static bool empty(LList *llist);

LList *llist_new(void)
{
    return NULL;
}

void llist_destroy(LList *llist)
{
    for (; !empty(llist); llist = llist_remove(llist, 0));
}

LList *llist_insert(LList *llist, unsigned int index, int value)
{
    LLNode *node = (LLNode *)malloc(sizeof(LLNode));
    if (node == NULL) log_error_exit("insert node is NULL");
    node->value = value;

    if (index == 0) {
        node->next = llist;
        llist = node;
    } else {
        LLNode *prev = llist_at(llist, index - 1);
        LLNode *next = prev->next;
        prev->next = node;
        node->next = next;
    }
    return llist;
}

LList *llist_remove(LList *llist, unsigned int index)
{
    if (empty(llist)) log_error_exit("remove from empty list");

    if (index == 0) {
        LList *new_head = llist->next;
        free(llist);
        return new_head;
    }
    LLNode *prev = llist_at(llist, index - 1);
    LLNode *goner = prev->next;
    prev->next = goner->next;
    free(goner);
    return llist;
}

LList *llist_reverse(LList *llist)
{
    if (empty(llist)) return llist;
    LLNode *node_prev = NULL,
           *node = llist,
           *temp;
    while (node != NULL) {
        temp = node->next;
        node->next = node_prev;
        node_prev = node;
        node = temp;
    }
    return node_prev;
}

LList *llist_reverse_rec(LList *llist)
{
    if (empty(llist)) return llist;
    if (llist->next == NULL) return llist;

    LLNode *head = llist_reverse_rec(llist->next);
    llist->next->next = llist;
    llist->next = NULL;
    return head;
}

LLNode *llist_at(LList *llist, unsigned int index)
{
    for (unsigned int i = 0; i != index; i++, llist = llist->next);
    return llist;
}

unsigned int llist_length(LList *llist)
{
    unsigned int counter = 0;
    for (; !empty(llist); counter++, llist = llist->next);
    return counter;
}

static bool empty(LList *llist)
{
    return llist == NULL;
}

void llist_print(LList *llist)
{
    printf("linked list at %p [%d]: ", llist, llist_length(llist));
    for (; !empty(llist); llist = llist->next)
        printf(" %d", llist->value);
    printf("\n");
}
