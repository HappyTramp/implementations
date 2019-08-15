#include <stddef.h>
#include "list.h"
#include "vector.h"
#include "graph.h"

Graph *graph_new(void)
{
    Graph *graph = (Graph*)vector_new(sizeof(Vertex*));
    return graph;
}

static void dummy_free(void *data) {} // remove all free_fn plz
void graph_destroy(Graph **graph)
{
    for (size_t i = 0; i < (*graph)->size; i++)
        list_clear(vector_get(*graph, i), dummy_free);
    vector_destroy(graph, dummy_free);
}

void graph_add_vertex(Graph *graph, void *data)
{
    Vertex *vertex = (Vertex*)list_create_elem(data);
    if (vertex == NULL)
        return;
    vector_push(graph, vertex);
}

void graph_add_edge(Graph *graph, size_t first, size_t second)
{
    list_push_front(vector_get(graph, first), vector_get(graph, second));
    list_push_front(vector_get(graph, second), vector_get(graph, first));
}
