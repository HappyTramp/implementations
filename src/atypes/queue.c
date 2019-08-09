#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"
#include "queue.h"

Queue *queue_new(void)
{
    Queue *queue = malloc(sizeof(Queue));
    if (queue == NULL)
        return NULL;
    queue->front = NULL;
    queue->back = NULL;
    return queue;
}

void queue_destroy(Queue **queue, void (*free_fn)(void *))
{
    if (queue == NULL)
        return;
    list_clear((*queue)->front, free_fn);
    free(*queue);
    *queue = NULL;
}

void queue_enqueue(Queue *queue, void *data)
{
    QueueNode *new_back = list_create_elem(data);
    if (new_back == NULL)
        return;
    new_back->next = NULL;
    if (queue->back == NULL)
        queue->front = new_back;
    else
        queue->back->next = new_back;
    queue->back = new_back;
}

void queue_dequeue(Queue *queue, void (free_fn)(void *))
{
    QueueNode *new_front = queue->front->next;
    free_fn(queue->front->data);
    free(queue->front);
    queue->front = new_front;
    if (new_front == NULL)
        queue->back = NULL;
}

void *queue_peek(Queue *queue)
{
    return queue->front->data;
}

size_t queue_size(Queue *queue)
{
    return list_size(queue->front);
}

void queue_print(Queue *queue, void (*print_fn)(void *))
{
    list_print(queue->back, print_fn);
}

