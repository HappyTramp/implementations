#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

#define GROWTH_FACTOR 1.5

static void grow_if_full(Vector *vector, size_t growth_size);
static void grow(Vector *vector, size_t growth_size);
/* static void geometric_expension(Vector *vector); */
/* static void check_index(Vector *vector, size_t index); */

Vector *vector_new(void)
{
    Vector *vector = malloc(sizeof(Vector));
    if (vector == NULL)
        return NULL;
    vector->capacity = 0;
    vector->size = 0;
    vector->under = NULL;
    return vector;
}

void vector_destroy(Vector **vector, void (*free_fn)(void *))
{
    if (*vector == NULL)
        return;
    for (size_t i = 0; i < (*vector)->size; i++)
        free_fn(vector_get(*vector, i));
    free((*vector)->under);
    free(*vector);
    *vector = NULL;
}

void *vector_get(Vector *vector, size_t index)
{
    return vector->under[index];
}

void vector_set(Vector *vector, size_t index, void *data)
{
    vector->under[index] = data;
}

void vector_push(Vector *vector, void *data)
{
    grow_if_full(vector, 1);
    vector_set(vector, vector->size - 1, data);
}

void vector_pop(Vector *vector, void (*free_fn)(void *))
{
    vector->size--;
    free_fn(vector_get(vector, vector->size));
    vector_set(vector, vector->size, NULL);
}

void vector_unshift(Vector *vector, void *data)
{
    grow_if_full(vector, 1);
    for (size_t i = vector->size - 1; i > 0; i--)
        vector_set(vector, i, vector_get(vector, i - 1));
    vector_set(vector, 0, data);
}

void vector_shift(Vector *vector, void (*free_fn)(void *))
{
    free_fn(vector_get(vector, 0));
    for (size_t i = 0; i < vector->size; i++)
        vector_set(vector, i, vector_get(vector, i + 1));
    vector_set(vector, --vector->size, NULL);
}

static void grow_if_full(Vector *vector, size_t growth_size)
{
    if (vector->size < vector->capacity)
        return;
    grow(vector, growth_size);
}

static void grow(Vector *vector, size_t growth_size)
{
    vector->capacity += growth_size;
    /* printf("%d, %p", sizeof(void*) * vector->capacity, vector->under); */
    vector->under = (void**)realloc(vector->under, sizeof(void*) * vector->capacity);
    if (vector->under == NULL)
        return;
    vector->size = vector->capacity;
}

/* static void geometric_expension(Vector *vector) */
/* { */
/*     grow(vector, vector->capacity * GROWTH_FACTOR); */
/* } */

/* static void check_index(Vector *vector, size_t index) */
/* { */
/*     if (index > vector->size || index > -vector->size) */
/*         log_error_exit("invalid index"); */
/* } */

void vector_print(Vector *vector, void (*f)(void *))
{
    for (size_t i = 0; i < vector->size; i++)
        f(vector_get(vector, i));
}
