#include "Graph.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Graph.c
 *
 * Starter file for the Weighted Graph ADT.
 *
 * Complete the TODOs in this file.
 * You may add private helper functions, but do not change Graph.h.
 */

typedef struct NeighborNode {
    int vertex;
    int weight;
    struct NeighborNode* next;
} NeighborNode;

struct GraphObj {
    int num_vertices;
    int num_edges;
    NeighborNode** adj_lists;
};

/*
 * Suggested private helper functions:
 *
 * You are not required to use these exact helper names, but they are useful:
 *
 *   static bool is_valid_vertex(Graph G, int v);
 *   static NeighborNode* create_neighbor(int vertex, int weight);
 *   static void free_adj_list(NeighborNode* head);
 *   static NeighborNode* find_neighbor(NeighborNode* head, int v);
 *   static bool insert_neighbor_sorted(NeighborNode** pHead, int vertex, int weight);
 *   static bool remove_neighbor(NeighborNode** pHead, int vertex);
 *   static int list_length(NeighborNode* head);
 *
 * Keep helper functions private by declaring them static inside this file.
 */

/* constructors / destructors ------------------------------------------------ */

Graph graph_create(int n) {
    // TODO:
    // 1. Reject n <= 0 by returning NULL.
    // 2. Allocate a GraphObj.
    // 3. Allocate an array of NeighborNode* of size n + 1.
    // 4. Initialize every adjacency list to NULL.
    // 5. Initialize num_vertices and num_edges.
    // 6. Return the new graph.
    (void)n;

    if(n <= 0) {
        return NULL;
    }

    // note how we used calloc here because it initializes to NULL (or so i think)
    Graph G = calloc(sizeof(struct GraphObj), 1); // 1-index

    NeighborNode** adj_lists = calloc((n+1), sizeof(NeighborNode*));

    G->num_vertices = n;
    G->num_edges = 0;

    return G;
}

void graph_destroy(Graph* pG) {
    // TODO:
    // 1. Check pG and *pG.
    // 2. Free every adjacency list.
    // 3. Free the adjacency-list array.
    // 4. Free the graph object.
    // 5. Set *pG to NULL.
    (void)pG;
    while(pG != NULL && *pG != NULL) {
        Graph G = *pG;
    }
}

/* access functions ---------------------------------------------------------- */

int graph_order(Graph G) {
    // TODO: Return the number of vertices, or 0 if G is NULL.
    (void)G;

    if(G == NULL) {
        return 0;
    }

    return G->num_vertices;
}

int graph_size(Graph G) {
    // TODO: Return the number of logical edges/arcs, or 0 if G is NULL.
    (void)G;

    if(G == NULL) {
        return 0;
    }

    return G->num_edges;
}

bool graph_has_edge(Graph G, int u, int v) {
    // TODO: Validate vertices and check whether v appears in u's adjacency list.
    (void)G;
    (void)u;
    (void)v;
    return false;
}

int graph_get_weight(Graph G, int u, int v) {
    // TODO: Return the weight of edge u->v, or INF if it does not exist.
    (void)G;
    (void)u;
    (void)v;
    return INF;
}

int graph_degree(Graph G, int v) {
    // TODO: Return the length of v's adjacency list, or -1 if invalid.
    (void)G;
    (void)v;
    return -1;
}

/* manipulation procedures --------------------------------------------------- */

bool graph_add_arc(Graph G, int u, int v, int weight) {
    // TODO:
    // 1. Validate G, u, v, and weight.
    // 2. Reject self-loops where u == v.
    // 3. Reject duplicates.
    // 4. Insert v into u's adjacency list with the given weight.
    // 5. Increment num_edges only if insertion succeeds.
    (void)G;
    (void)u;
    (void)v;
    (void)weight;
    return false;
}

bool graph_add_edge(Graph G, int u, int v, int weight) {
    // TODO:
    // 1. Validate G, u, v, and weight.
    // 2. Reject self-loops where u == v.
    // 3. Reject the edge if either direction already exists.
    //    This includes mixed cases where one direction was previously added
    //    by graph_add_arc.
    // 4. Insert v into u's list and u into v's list.
    // 5. If the second insertion fails, undo the first insertion.
    // 6. Increment num_edges only once for the undirected edge.
    //
    // Hint: you may want a private helper to remove a neighbor from a list.
    (void)G;
    (void)u;
    (void)v;
    (void)weight;
    return false;
}

/* output -------------------------------------------------------------------- */

void graph_print(FILE* out, Graph G) {
    // TODO:
    // Print one line per vertex in this exact format:
    //
    // 1: (2, 5) (3, 2)
    // 2: (1, 5)
    // 3:
    //
    // Do not print trailing spaces at the end of any line.
    // Do nothing if out == NULL or G == NULL.
    (void)out;
    (void)G;
}
