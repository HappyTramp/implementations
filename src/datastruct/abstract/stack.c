#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "logger.h"
#include "stack.h"

#define MAXSIZE 100


static bool empty(Stack *stack);
static bool full(Stack *stack);
static Stack *new_element(Stack *next, int value);
static Stack *push(Stack *stack, int value);
static Stack *pop(Stack *stack);

// NULL pointer to stack
Stack *stack_new(void)
{
    return NULL;
}

// pop until the stack is empty
Stack *stack_destroy(Stack *stack)
{
    while (!empty(stack))
        stack = stack_pop(stack);
    return NULL;
}

// push an element on top of the stack
Stack *stack_push(Stack *stack, int value)
{
    if (full(stack))
        log_error_exit("stack overflow");
    Stack *top = malloc(sizeof(Stack));
    top->next = stack;
    top->value = value;
    return top;
}

// pop an element and return the next one
Stack *stack_pop(Stack *stack)
{
    if (empty(stack))
        log_error_exit("stack underflow");
    Stack *new_top = stack->next;
    free(stack);
    return new_top;
}

// show top value
int stack_peek(Stack *stack)
{
    if (empty(stack))
        log_error_exit("peek at empty stack");
    return stack->value;
}

// push top element
Stack *stack_duplicate(Stack *stack)
{
    if (empty(stack))
        log_error_exit("duplicate empty stack");
    if (full(stack))
        log_error_exit("duplicate full stack");
    Stack *clone = new_element(stack, stack->value);
    return clone;
}

// swap the 2 top most element
Stack *stack_swap(Stack *stack)
{
    if (stack_length(stack) < 2)
        log_error_exit("swap on stack with less than 2 element");
    Stack *new_top = stack->next,
          *current_top = stack;
    current_top->next = new_top->next;
    new_top->next = current_top;
    return new_top;
}

// rotate the n top most element
Stack *stack_rotate(Stack *stack, int n, RotationDirection direction)
{
    if (empty(stack))
        log_error_exit("rotate empty stack");
    if (n > stack_length(stack))
        log_error_exit("rotation size supperior to stack length");
    if (stack_length(stack) == 1)
        return stack;

    int buffer[n], i;
    switch(direction) {
        case RotateLeft:
            for (i = 1;; i = (i + 1) % (n  - 1)) {
                /*stack_print(stack);*/
                /*printf("i: %d\n", i);*/
                buffer[i] = stack->value;
                stack = pop(stack);
                if (i == 0) break;
            }
            break;
        case RotateRight:
            for (i = -1; i < n - 1; i++) {
                buffer[i] = stack->value;
                stack = pop(stack);
            }
            break;
        default:
            exit(1);
    }
    for (i = 0; i < n; i++)
        /*printf("buf: %d\n", buffer[i]);*/
        stack = push(stack, buffer[i]);
    return stack;
}

// rotate the n top most element to the right
Stack *stack_rotate_right(Stack *stack, int n)
{
    return stack_rotate(stack, n, RotateRight);
}

// rotate the n top most element to the left
Stack *stack_rotate_left(Stack *stack, int n)
{
    return stack_rotate(stack, n, RotateLeft);
}

// number of element in the stack
int stack_length(Stack *stack)
{
    int counter = 0;
    for (; !empty(stack); counter++)
        stack = stack->next;
    return counter;
}

// test if the stack is empty
static bool empty(Stack *stack)
{
    return stack == NULL;
}

// test if the stack is full
static bool full(Stack *stack)
{
    return stack_length(stack) > MAXSIZE;
}

// create a new stack element
static Stack *new_element(Stack *next, int value)
{
    Stack *elt = malloc(sizeof(Stack));
    elt->next = next;
    elt->value = value;
    return elt;
}

// alias for stack_push
static Stack *push(Stack *stack, int value)
{
    return stack_push(stack, value);

}

// alias for stack_pop
static Stack *pop(Stack *stack)
{
   return stack_pop(stack);
}

// print a string representation of the stack
void stack_print(Stack *stack)
{
    printf("stack at %p of length %d: ", stack, stack_length(stack));
    if (empty(stack))
        printf("is empty");
    while (!empty(stack)) {
        printf("[%d] ", stack_peek(stack));
        stack = stack->next;
    }
    printf("\n");
}
