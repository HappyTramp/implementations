#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "logger.h"

#define GROWTH_FACTOR 2

static Vector *grow(Vector *vector, unsigned int growth);
static Vector *geometric_expension(Vector *vector);
static void check_index(Vector *vector, unsigned int index);

Vector *vector_new(void)
{
    Vector *vector = malloc(sizeof(Vector));
    if (vector == NULL)
        log_error_exit("new vector is NULL");
    vector->capacity = 0;
    vector->size = 0;
    vector->under = NULL;
    return vector;
}

Vector *vector_destroy(Vector *vector)
{
    free(vector->under);
    free(vector);
    return NULL;
}

int vector_get(Vector *vector, unsigned int index)
{
    check_index(vector, index);
    return vector->under[index];
}

Vector *vector_set(Vector *vector, unsigned int index, int value)
{
    check_index(vector, index);
    vector->under[index] = value;
    return vector;
}

Vector *vector_insert(Vector *vector, int value)
{

    return vector;
}

Vector *vector_push(Vector *vector, int value)
{
    vector = grow(vector, 1);
    vector->under[vector->size - 1] = value;
    return vector;
}

Vector *vector_pop(Vector *vector)
{
    if (vector->size == 0)
        log_error_exit("pop empty vector");
    vector->under[vector->size - 1] = 0;
    vector->size--;
    return vector;
}

Vector *vector_unshift(Vector *vector, int value)
{
    vector = grow(vector, 1);
    for (int i = vector->size - 1; i != 0; i--)
        vector->under[i] = vector->under[i - 1];
    vector->under[0] = value;
    return vector;
}

Vector *vector_shift(Vector *vector)
{
    if (vector->size == 0)
        log_error_exit("shift empty vector");
    for (unsigned int i = 0; i < vector->size - 1; i++)
        vector->under[i] = vector->under[i + 1];
    vector->under[vector->size - 1] = 0;
    vector->size--;
    return vector;
}

static Vector *grow(Vector *vector, unsigned int growth)
{
    vector->size += growth;
    int cap_growth = vector->size - vector->capacity;
    if (cap_growth <= 0)
        return vector;

    vector->under = realloc(vector->under, sizeof(int) * vector->size);
    if (vector->under == NULL)
        log_error_exit("vector under reallocation is NULL");
    vector->capacity = vector->size;
    return vector;
}

static Vector *geometric_expension(Vector *vector)
{
    return grow(vector, vector->size * GROWTH_FACTOR);
}

static void check_index(Vector *vector, unsigned int index)
{
    if (index > vector->size || index > -vector->size)
        log_error_exit("invalid index");
}

void vector_print(Vector *vector)
{
    printf("vector at %p [%d > %d]: ",
          vector, vector->size, vector->capacity);
    for (unsigned int i = 0; i < vector->size; i++)
        printf("%d, ", vector_get(vector, i));
    printf("\n");
}

