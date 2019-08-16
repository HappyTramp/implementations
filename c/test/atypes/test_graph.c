#include "unity.h"
#include "unity_helper.h"
#include "list.h"
#include "vector.h"
#include "graph.h"

static int i0 = 0;
static int i1 = 1;
static int i2 = 2;
static int i3 = 3;
static int i4 = 4;
static int i5 = 5;
static int i6 = 6;
static int i7 = 7;
static int i8 = 8;
static int i9 = 9;
static Graph *graph;

void setUp(void)
{
    graph = graph_new();
}

void tearDown(void)
{
    if (graph != NULL)
        graph_destroy(&graph);
}

void test_graph_new(void)
{
    TEST_ASSERT_NOT_NULL(graph);
    TEST_ASSERT_EQUAL(0, graph->capacity);
    TEST_ASSERT_EQUAL(0, graph->size);
    TEST_ASSERT_EQUAL(sizeof(Vertex*), graph->data_size);
    TEST_ASSERT_NULL(graph->under);
}

void test_graph_destroy(void)
{
    graph_destroy(&graph);
    TEST_ASSERT_NULL(graph);
}

void test_graph_add_vertex(void)
{
    graph_add_vertex(graph, &i1);
    /* TEST_ASSERT_NOT_NULL(vector_at(graph, 0)); */
    /* TEST_ASSERT_NULL(((Vertex*)vector_get(graph, 0))->neighbours); */
    graph_print(graph);
    /* TEST_ASSERT_EQUAL(&i1, ((Vertex*)vector_get(graph, 0))->data); */

    /* graph_add_vertex(graph, &i1); */
    /* graph_add_vertex(graph, &i2); */
    /* graph_add_vertex(graph, &i3); */
}

void test_add_edge(void)
{
}
