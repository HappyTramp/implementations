#ifndef __H_QUEUE__
#define __H_QUEUE__

#include <stdio.h>
#include <stdbool.h>

typedef struct QueueNode {
    struct QueueNode *next;
    void *value;
} QueueNode;

typedef struct Queue {
    QueueNode *front;
    QueueNode *rear;
} Queue;

Queue *queue_new(void);
void queue_destroy(Queue *queue);
Queue *queue_enqueue(Queue *queue, void *value);
Queue *queue_dequeue(Queue *queue);
void *queue_peek(Queue *queue);
bool queue_empty(Queue *queue);
void queue_print(Queue *queue, void (*f)(void *));

#endif
