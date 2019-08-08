#ifndef __H_STACK__
#define __H_STACK__

#include <stdbool.h>

typedef struct Stack {
    int value;
    struct Stack *next;
} Stack;

typedef enum {
    RotateLeft,
    RotateRight
} RotationDirection;

Stack *stack_new(void);
Stack *stack_destroy(Stack *stack);
Stack *stack_push(Stack *stack, int value);
Stack *stack_pop(Stack *stack);
int stack_peek(Stack *stack);
Stack *stack_duplicate(Stack *stack);
Stack *stack_swap(Stack *stack);
Stack *stack_rotate(Stack *stack, int n, RotationDirection direction);
Stack *stack_rotate_right(Stack *stack, int n);
Stack *stack_rotate_left(Stack *stack, int n);
int stack_length(Stack *stack);
void stack_print(Stack *stack);

#endif
