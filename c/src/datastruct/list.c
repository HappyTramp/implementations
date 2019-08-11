#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

List *list_create_elem(void *data)
{
    List *list;

    if ((list = (List*)malloc(sizeof(List))) == NULL)
        return NULL;
    list->data = data;
    list->next = NULL;
    return list;
}

void list_clear(List *list, void (*free_fn)(void *))
{
    List *tmp;

    while (list != NULL)
    {
        tmp = list->next;
        free_fn(list->data);
        free(list);
        list = tmp;
    }
}

void list_destroy(List **list, void (*free_fn)(void *))
{
    list_clear(*list, free_fn);
    *list = NULL;
}


void list_push_front(List **list, void *data)
{
    List *new_front = list_create_elem(data);
    if (new_front == NULL)
        return ;
    new_front->next = *list;
    *list = new_front;
}

void list_push_back(List **list, void *data)
{
    List *cursor;
    List *new_rear = list_create_elem(data);

    if (*list == NULL)
    {
        *list = new_rear;
        return ;
    }
    for (cursor = *list; cursor->next != NULL; cursor = cursor->next);
    cursor->next = new_rear;
}

void list_destroy_elem(List **elem, void (*free_fn)(void *))
{
    if (*elem == NULL)
        return ;
    free_fn((*elem)->data);
    free(*elem);
    *elem = NULL;
}

void list_remove_if(List **list, bool (*f)(void *), void (*free_fn)(void *))
{
    List *tmp;
    List *prev = NULL;
    List *cursor = *list;

    while (cursor != NULL)
    {
        while (cursor && f(cursor->data))
        {
            if (prev != NULL)
                prev->next = cursor->next;
            else
                *list = cursor->next;
            tmp = cursor;
            cursor = cursor->next;
            list_destroy_elem(&tmp, free_fn);
        }
        if (cursor != NULL)
        {
            prev = cursor;
            cursor = cursor->next;
        }
    }
}

void list_remove_at(List **list, int index, void (*free_fn)(void *))
{
    if (index == 0) {
        free_fn((*list)->data);
        *list = (*list)->next;
        free(list);
    }
    List *prev = list_at(*list, index - 1);
    List *goner = prev->next;
    prev->next = goner->next;
    free(goner);
}

void list_reverse(List **list)
{
    List *tmp;
    List *prev = NULL;
    List *cursor = *list;

    while (cursor != NULL) {
        tmp = cursor->next;
        cursor->next = prev;
        prev = cursor;
        cursor = tmp;
    }
    *list = prev;
}

List *list_reverse_rec(List *list)
{
    if (list == NULL || list->next == NULL)
        return list;
    List *head = list_reverse_rec(list->next);
    list->next->next = list;
    list->next = NULL;
    return head;
}

List *list_at(List *list, int index)
{
    for (int i = 0; i != index; i++, list = list->next);
    return list;
}

size_t list_size(List *list)
{
    size_t counter = 0;
    for (; list != NULL; counter++, list = list->next);
    return counter;
}

void list_print(List *list, void (*print_fn)(void *))
{
    for (; list != NULL; list = list->next)
        print_fn(list->data);
}
