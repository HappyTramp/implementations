#ifndef __GRAPH_H__
# define __GRAPH_H__

# include "list.h"
# include "vector.h"

typedef List Vertex;
typedef Vector AdjacencyList, Graph;

Graph *graph_new(void);
void graph_destroy(Graph **graph);

#endif
