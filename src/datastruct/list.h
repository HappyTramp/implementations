#ifndef __LIST_H__
#define __LIST_H__

#include <stdbool.h>
#include <string.h>

typedef struct List {
    struct List *next;
    void *data;
} List;

List *list_create_elem(void *data);
void list_clear(List *list, void (*free_fn)(void *));
void list_destroy(List **list, void (*free_fn)(void *));
void list_push_front(List **list, void *data);
void list_push_back(List **list, void *data);
void list_destroy_elem(List **elem, void (*free_fn)(void *));
void list_remove_if(List **list, bool (*f)(void *), void (*free_fn)(void *));
void list_remove_at(List **list, int index, void (*free_fn)(void *));
void list_reverse(List **list);
List *list_reverse_rec(List *list);
List *list_at(List *list, int index);
size_t list_size(List *list);
void list_print(List *list, void (*print_fn)(void *));

#endif
