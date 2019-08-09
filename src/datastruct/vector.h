#ifndef __VECTOR_H__
# define __VECTOR_H__

#define UNITY_OUTPUT_COLOR
# include <string.h>

typedef struct {
    size_t capacity;
    size_t size;
    void **under;
} Vector;

Vector *vector_new(void);
void vector_destroy(Vector **vector, void (*free_fn)(void *));
void *vector_get(Vector *vector, size_t index);
void vector_set(Vector *vector, size_t index, void *data);
void vector_push(Vector *vector, void *data);
void vector_pop(Vector *vector, void (*free_fn)(void *));
void vector_unshift(Vector *vector, void *data);
void vector_shift(Vector *vector, void (*free_fn)(void *));
void vector_print(Vector *vector, void (*f)(void *));

#endif
