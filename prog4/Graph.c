#include "Graph.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Graph.c
 *
 * Starter file for the Weighted Graph ADT from Hwk 4.
 *
 * Complete the TODOs in this file or replace this file with your completed
 * Hwk 4 Graph.c implementation.
 *
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

/* private helper functions -------------------------------------------------- */

/*
 * is_valid_vertex
 * Returns true if v is a valid vertex label for G.
 */
static bool is_valid_vertex(Graph G, int v) {
    // TODO: Return whether G is non-NULL and v is in the range 1..num_vertices.
    (void)G;
    (void)v;
    return false;
}

/*
 * create_neighbor
 * Allocates and initializes a NeighborNode.
 */
static NeighborNode* create_neighbor(int vertex, int weight) {
    // TODO: Allocate a new NeighborNode and initialize its fields.
    (void)vertex;
    (void)weight;
    return NULL;
}

/*
 * free_adj_list
 * Frees every NeighborNode in one adjacency list.
 */
static void free_adj_list(NeighborNode* head) {
    // TODO: Walk the linked list and free every node.
    (void)head;
}

/*
 * find_neighbor
 * Returns a pointer to the neighbor node whose vertex field equals v.
 * Returns NULL if v is not found.
 */
static NeighborNode* find_neighbor(NeighborNode* head, int v) {
    // TODO: Search the linked list for vertex v.
    (void)head;
    (void)v;
    return NULL;
}

/*
 * insert_neighbor_sorted
 * Inserts a new neighbor into the list pointed to by pHead.
 *
 * The list must remain sorted by increasing vertex label.
 * If the neighbor already exists, do not insert a duplicate.
 *
 * Returns true if a node was inserted.
 * Returns false if allocation fails or the neighbor already exists.
 */
static bool insert_neighbor_sorted(NeighborNode** pHead, int vertex, int weight) {
    // TODO: Insert a new NeighborNode into the correct sorted position.
    (void)pHead;
    (void)vertex;
    (void)weight;
    return false;
}

/*
 * list_length
 * Returns the number of nodes in one adjacency list.
 */
static int list_length(NeighborNode* head) {
    // TODO: Count and return the number of nodes in this linked list.
    (void)head;
    return 0;
}

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
    return NULL;
}

void graph_destroy(Graph* pG) {
    // TODO:
    // 1. Check pG and *pG.
    // 2. Free every adjacency list.
    // 3. Free the adjacency-list array.
    // 4. Free the graph object.
    // 5. Set *pG to NULL.
    (void)pG;
}

/* access functions ---------------------------------------------------------- */

int graph_order(Graph G) {
    // TODO: Return the number of vertices, or 0 if G is NULL.
    (void)G;
    return 0;
}

int graph_size(Graph G) {
    // TODO: Return the number of logical edges/arcs, or 0 if G is NULL.
    (void)G;
    return 0;
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
