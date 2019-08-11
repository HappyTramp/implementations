#ifndef __STACK_H__
# define __STACK_H__

# include <stdbool.h>
# include "list.h"

typedef List Stack;

void stack_destroy(Stack **stack_ptr, void (*free_fn)(void *));
void stack_push(Stack **stack_ptr, void *data);
void stack_pop(Stack **stack_ptr, void (*free_fn)(void *));
void *stack_peek(Stack *stack);
void stack_duplicate(Stack **stack);
void stack_swap(Stack **stack);
void stack_rotate_right(Stack **stack, int n);
void stack_rotate_left(Stack **stack, int n);
int stack_size(Stack *stack);

#endif
