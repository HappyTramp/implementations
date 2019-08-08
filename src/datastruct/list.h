#ifndef __H_LIST__
#define __H_LIST__

typedef struct LLNode {
    struct LLNode *next;
    int value;
} LLNode, LList;

LList *llist_new(void);
void llist_destroy(LList *llist);
LList *llist_insert(LList *llist, unsigned int index, int value);
LList *llist_remove(LList *llist, unsigned int index);
LList *llist_reverse(LList *llist);
LList *llist_reverse_rec(LList *llist);
LLNode *llist_at(LList *llist, unsigned int index);
unsigned int llist_length(LList *llist);
void llist_print(LList *llist);

#endif
