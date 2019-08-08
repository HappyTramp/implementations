#ifndef __H_VECTOR__
#define __H_VECTOR__

typedef struct {
    unsigned int capacity;
    unsigned int size;
    int *under;
} Vector;

Vector *vector_new(void);
Vector *vector_destroy(Vector *vector);
int vector_get(Vector *vector, unsigned int index);
Vector *vector_set(Vector *vector, unsigned int index, int value);
Vector *vector_push(Vector *vector, int value);
Vector *vector_pop(Vector *vector);
Vector *vector_unshift(Vector *vector, int value);
Vector *vector_shift(Vector *vector);
void vector_print(Vector *vector);

#endif
