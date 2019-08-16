#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "list.h"
#include "vector.h"
#include "graph.h"

static Vertex *graph_get(Graph *graph, size_t index);
Graph *graph_new(void)
{
    Graph *graph = (Graph*)vector_new(sizeof(Vertex*));
    return graph;
}

static void dummy_free(void *data) {} // remove all free_fn plz
void graph_destroy(Graph **graph)
{
    for (size_t i = 0; i < (*graph)->size; i++)
    {
        list_clear(((Vertex*)vector_get(*graph, i))->neighbours, dummy_free);
        /* free(graph_get(*graph, i)); */
    }
    vector_destroy(graph, dummy_free);
}

void graph_add_vertex(Graph *graph, void *data)
{
    Vertex *vertex = (Vertex*)malloc(sizeof(Vertex));
    if (vertex == NULL)
        return;
    vertex->data = data;
    vertex->neighbours = NULL;
    printf("%p data:%p neighbours:%p\n", vertex, vertex->data, vertex->neighbours);
    vector_push(graph, &vertex);
}

void graph_add_edge(Graph *graph, Vertex *first, Vertex *second)
{
    list_push_front(&first->neighbours, second);
    list_push_front(&second->neighbours, first);
}

// add functions for each vertex
static void print_neighbours(void *data)
{
    if (data != NULL)
        printf("%p -> ", data);
}

void graph_print(Graph *graph)
{
    for (int i = 0; i < graph->size; i++)
    {
        printf("%p (%p): ", vector_get(graph, i), (*(Vertex*)vector_get(graph, i)));
        list_print(vector_get(graph, i), print_neighbours);
        printf("N\n");
    }
}

static Vertex *graph_get(Graph *graph, size_t index)
{
    return (Vertex*)vector_get(graph, index);
}
