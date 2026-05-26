#include "Graph.h"

#include <stdbool.h>
#include <stdio.h>

static const char* bool_string(bool value) {
    return value ? "true" : "false";
}

static void print_weight(int weight) {
    if (weight == INF) {
        printf("INF");
    } else {
        printf("%d", weight);
    }
}

int main(void) {
    Graph G = graph_create(5);

    if (G == NULL) {
        printf("Failed to create graph\n");
        return 1;
    }

    printf("Initial graph:\n");
    printf("order: %d\n", graph_order(G));
    printf("size: %d\n", graph_size(G));
    graph_print(stdout, G);
    printf("\n");

    printf("Adding undirected edges:\n");
    printf("add 1-2 weight 5: %s\n", bool_string(graph_add_edge(G, 1, 2, 5)));
    printf("add 1-3 weight 2: %s\n", bool_string(graph_add_edge(G, 1, 3, 2)));
    printf("add 2-4 weight 7: %s\n", bool_string(graph_add_edge(G, 2, 4, 7)));
    printf("add 3-4 weight 1: %s\n", bool_string(graph_add_edge(G, 3, 4, 1)));
    printf("add 4-5 weight 3: %s\n", bool_string(graph_add_edge(G, 4, 5, 3)));
    printf("order: %d\n", graph_order(G));
    printf("size: %d\n", graph_size(G));
    graph_print(stdout, G);
    printf("\n");

    printf("Access tests:\n");
    printf("has_edge 1 3: %s\n", bool_string(graph_has_edge(G, 1, 3)));
    printf("has_edge 3 1: %s\n", bool_string(graph_has_edge(G, 3, 1)));
    printf("has_edge 2 5: %s\n", bool_string(graph_has_edge(G, 2, 5)));
    printf("weight 3 4: ");
    print_weight(graph_get_weight(G, 3, 4));
    printf("\n");
    printf("weight 2 5: ");
    print_weight(graph_get_weight(G, 2, 5));
    printf("\n");
    printf("degree 4: %d\n", graph_degree(G, 4));
    printf("degree 5: %d\n", graph_degree(G, 5));
    printf("\n");

    printf("Rejected insertions:\n");
    printf("duplicate 1-2 weight 9: %s\n", bool_string(graph_add_edge(G, 1, 2, 9)));
    printf("invalid vertex 0-2: %s\n", bool_string(graph_add_edge(G, 0, 2, 4)));
    printf("invalid weight 2-5 weight 0: %s\n", bool_string(graph_add_edge(G, 2, 5, 0)));
    printf("self-loop 3-3 weight 4: %s\n", bool_string(graph_add_edge(G, 3, 3, 4)));
    printf("size: %d\n", graph_size(G));
    graph_print(stdout, G);
    printf("\n");

    printf("Adding directed arc:\n");
    printf("add arc 5->2 weight 9: %s\n", bool_string(graph_add_arc(G, 5, 2, 9)));
    printf("has_edge 5 2: %s\n", bool_string(graph_has_edge(G, 5, 2)));
    printf("has_edge 2 5: %s\n", bool_string(graph_has_edge(G, 2, 5)));
    printf("mixed duplicate edge 2-5 weight 11: %s\n", bool_string(graph_add_edge(G, 2, 5, 11)));
    printf("size: %d\n", graph_size(G));
    graph_print(stdout, G);
    printf("\n");

    graph_destroy(&G);
    printf("destroyed graph is NULL: %s\n", bool_string(G == NULL));

    return 0;
}
