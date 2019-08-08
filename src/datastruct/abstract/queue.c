#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"
#include "logger.h"


static bool empty(Queue *queue);

Queue *queue_new(void)
{
    Queue *queue = malloc(sizeof(Queue));
    if (queue == NULL)
        log_error_exit("new queue pointer is NULL");
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void queue_destroy(Queue *queue)
{
    if (queue == NULL)
        log_error_exit("cannot destroy NULL");
    while (!empty(queue))
        queue = queue_dequeue(queue);
    free(queue);
}

Queue *queue_enqueue(Queue *queue, void *value)
{
    QueueNode *new_rear = malloc(sizeof(QueueNode));
    if (new_rear == NULL) log_error_exit("new rear pointer is NULL");

    new_rear->value = value;
    new_rear->next = NULL;
    if (empty(queue))
        queue->front = new_rear;
    else
        queue->rear->next = new_rear;
    queue->rear = new_rear;
    return queue;
}

Queue *queue_dequeue(Queue *queue)
{
    if (empty(queue)) log_error_exit("cannot dequeue an empty queue");
    QueueNode *new_front = queue->front->next;
    free(queue->front);
    queue->front = new_front;
    if (new_front == NULL) queue->rear = new_front;
    return queue;
}

void *queue_peek(Queue *queue)
{
    if (empty(queue)) log_error_exit("peek on empty queue");
    return queue->front->value;
}

bool queue_empty(Queue *queue)
{
    if (queue == NULL) log_error_exit("null queue");
    return queue->front == NULL && queue->rear == NULL;
}

static bool empty(Queue *queue) { return queue_empty(queue); }

void queue_print(Queue *queue, void (*f)(void *))
{
    QueueNode *cursor = queue->front;
    printf("queue at %p > ", queue);
    for (cursor = queue->front; cursor != NULL; cursor = cursor->next)
        f(cursor->value);
    printf("\n");
}

