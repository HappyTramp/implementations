#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"
#include "stack.h"

static bool empty(Stack *stack);
static bool full(Stack *stack);
static Stack *new_element(Stack *next, int value);
static Stack *push(Stack *stack, int value);
static Stack *pop(Stack *stack);

// pop until the stack is empty
void stack_destroy(Stack **stack_ptr, void (*free_fn)(void *))
{
    list_destroy(stack_ptr, free_fn);
}

// push an element on top of the stack
void stack_push(Stack **stack_ptr, void *data)
{
    list_push_front(stack_ptr, data);
}

// pop an element and return the next one
void stack_pop(Stack **stack_ptr, void (*free_fn)(void *))
{
    Stack *tmp;

    if (*stack_ptr == NULL)
        return;
    free_fn((*stack_ptr)->data);
    tmp = (*stack_ptr)->next;
    free(*stack_ptr);
    *stack_ptr = tmp;
}

// show top value
void *stack_peek(Stack *stack)
{
    return stack->data;
}

/*// push top element*/
void stack_duplicate(Stack **stack)
{
    Stack *clone = list_create_elem((*stack)->data);
    clone->next = *stack;
    *stack = clone;
}

/*// swap the 2 top most element*/
void stack_swap(Stack **stack)
{
    Stack *new_top = (*stack)->next;
    Stack *current_top = *stack;
    current_top->next = new_top->next;
    new_top->next = current_top;
    *stack = new_top;
}

// rotate the n top most element to the right
void stack_rotate_right(Stack **stack, int n)
{
}

// rotate the n top most element to the left
void stack_rotate_left(Stack **stack, int n)
{
}

int stack_size(Stack *stack)
{
    return list_size(stack);
}
