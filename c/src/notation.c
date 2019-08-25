#include <ctype.h>
#include <stdlib.h>
#include "stack.h"
#include "notation.h"

#define IS_OPERATOR(c) ((c) == '+' || (c) == '-' || (c) == '*' || (c) == '/')

static int apply_operator(char operator, int a, int b);

void dummy_free(void *d) {}

int notation_prefix(char *str)
{
    Stack *stack = NULL;
    int result = 0;
    while (*str)
    {
        if (isspace(*str))
        {
            str++;
            continue;
        }
        if (IS_OPERATOR(*str))
            stack_push(&stack, str);
        else if (isdigit(*str))
        {
            char *peek = (char*)stack_peek(stack);
            /* printf("%c\n", *peek); */
            if (isdigit(*peek))
            {
                stack_pop(&stack, dummy_free);
                char operator = *(char*)stack_peek(stack);
                stack_pop(&stack, dummy_free);
                /* printf("%s %c %s", str, operator, peek); */
                result = apply_operator(operator, atoi(peek), atoi(str));
                /* stack_push(&stack, */ // push the result back onto the stack
            }
            else
                stack_push(&stack, str);
            while (isdigit(*str))
                str++;
            /* printf("%c ", *str); */
        }
        str++;
    }
    stack_destroy(&stack, dummy_free);
    return result;
}

static int apply_operator(char operator, int a, int b)
{
    switch (operator)
    {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
    }
    return 0;
}
