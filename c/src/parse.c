#include <string.h>
#include "stack.h"
#include "parse.h"

static void dummy_free(void *data) {}

static int str_find(char *str, char c)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            return i;
    return -1;
}

bool parse_is_balanced(char *str, char *closures)
{
    if (strlen(closures) % 2 != 0)
        return false;
    int clos_i = 0;
    Stack *stack = NULL;
    for (int i = 0; str[i]; i++)
    {
        if ((clos_i = str_find(closures, str[i])) == -1)
            continue;
        if (clos_i % 2 == 0)
            stack_push(&stack, &str[i]);
        else
        {
            if (*(char*)stack_peek(stack) != closures[clos_i - 1])
                break;
            stack_pop(&stack, dummy_free);
        }
    }
    if (stack == NULL)
        return true;
    stack_destroy(&stack, dummy_free);
    return false;
}
