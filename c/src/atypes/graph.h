#ifndef __GRAPH_H__
# define __GRAPH_H__

# include "list.h"
# include "vector.h"

typedef struct
{
    List *neighbours;
    void *data;
} Vertex;
typedef Vector Graph;

Graph *graph_new(void);
void graph_destroy(Graph **graph);
void graph_add_vertex(Graph *graph, void *data);
void graph_add_edge(Graph *graph, Vertex *first, Vertex *second);
/* void *graph_get_vertex_value(Graph *graph, */
void graph_print(Graph *graph);

#endif
