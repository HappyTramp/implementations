#ifndef __QUEUE_H__
# define __QUEUE_H__

# include <stdbool.h>
# include "list.h"

typedef List QueueNode;

typedef struct {
    QueueNode *back;
    QueueNode *front;
} Queue;

Queue *queue_new(void);
void queue_destroy(Queue **queue, void (*free_fn)(void *));
void queue_enqueue(Queue *queue, void *data);
void queue_dequeue(Queue *queue, void (*free_fn)(void *));
void *queue_peek(Queue *queue);
size_t queue_size(Queue *queue);
void queue_print(Queue *queue, void (*print_fn)(void *));

#endif
