#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include "backtrack.h"

#define ABS(x) ((x) < 0 ? -(x) : (x))

void backtrack(void *data, bool (*reject)(void *), bool (*accept)(void *),
               void *(*first)(void *), void *(*next)(void *), void (*output)(void *))
{
    if (reject(data))
        return;
    if (accept(data))
        output(data);
    void *candidate = first(data);
    while (candidate != NULL)
    {
        backtrack(candidate, reject, accept, first, next, output);
        candidate = next(candidate);
    }
}

static bool queens_reject(void *data);
static bool queens_accept(void *data);
static void *queens_first(void *data);
static void *queens_next(void *data);
static void queens_output(void *data);

void backtrack_queens(size_t board_size)
{
    Queens *queens = (Queens*)malloc(sizeof(Queens));
    queens->cols_positions = (int*)malloc(sizeof(int) * board_size);
    if (queens == NULL)
        return;
    queens->curr_x = 0;
    queens->curr_y = 0;
    for (size_t i = 0; i < board_size; i++)
        queens->cols_positions[i] = -1;
    backtrack(queens, queens_reject, queens_accept, queens_first,
              queens_next, queens_output);
}

static bool queens_reject(void *data)
{
    Queens *queens = (Queens*)data;
    for (int i = 0; i < queens->curr_x; i++)
    {
        if (queens->curr_y == queens->cols_positions[i])
            return false;
        if (ABS(queens->curr_x - i) == ABS(queens->curr_y - queens->cols_positions[i]))
            return false;
    }
    return true;
}

static bool queens_accept(void *data)
{
    Queens *queens = (Queens*)data;
    return queens->cols_positions[queens->size - 1] != -1;
}

static void *queens_first(void *data)
{
    Queens *queens = (Queens*)data;
    queens->cols_positions[queens->curr_y] = 0;
    return (void*)queens;
}

static void *queens_next(void *data)
{
    Queens *queens = (Queens*)data;
    if (queens->cols_positions[queens->curr_y] == queens->size - 1)
        return NULL;
    queens->cols_positions[queens->curr_y]++;
    return (void*)queens;
}

static void queens_output(void *data)
{
    Queens *queens = (Queens*)data;
    int i, j;
    printf("+-");
    for (i = 0; i < queens->size; i++)
        printf("--");
    printf("+");
    for (i = 0; i < queens->size; i++)
    {
        printf("| ");
        for (j = 0; j < queens->cols_positions[i]; j++)
            printf(". ");
        printf("Q ");
        for (j = 0; j < queens->size; j++)
            printf(". ");
        printf("|\n");
    }
    printf("+-");
    for (i = 0; i < queens->size; i++)
        printf("--");
    printf("+");
}
