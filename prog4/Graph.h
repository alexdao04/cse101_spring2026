#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>
#include <stdio.h>

/*
 * Graph.h
 *
 * Public interface for the Weighted Graph ADT.
 *
 * Do not modify this file.
 *
 * Vertices are labeled from 1 to n.
 * Vertex 0 is not a valid vertex.
 * Self-loops are not allowed, so u and v must be different vertices.
 * All valid edge weights are positive integers.
 */

#define INF 2147483647

typedef struct GraphObj* Graph;

/* constructors / destructors ------------------------------------------------ */

/*
 * graph_create
 * Returns a new graph with n vertices and no edges.
 * Returns NULL if n <= 0 or memory allocation fails.
 */
Graph graph_create(int n);

/*
 * graph_destroy
 * Frees all heap memory associated with *pG and sets *pG to NULL.
 * Does nothing if pG == NULL or *pG == NULL.
 */
void graph_destroy(Graph* pG);

/* access functions ---------------------------------------------------------- */

/*
 * graph_order
 * Returns the number of vertices in G.
 * Returns 0 if G == NULL.
 */
int graph_order(Graph G);

/*
 * graph_size
 * Returns the number of logical edges/arcs successfully added to G.
 * A successful graph_add_arc call counts as 1.
 * A successful graph_add_edge call counts as 1 logical edge, even though it
 * creates two adjacency-list entries.
 * Returns 0 if G == NULL.
 */
int graph_size(Graph G);

/*
 * graph_has_edge
 * Returns true if there is an edge/arc from u to v.
 * Returns false if G == NULL, if either vertex is invalid, or if no such edge exists.
 */
bool graph_has_edge(Graph G, int u, int v);

/*
 * graph_get_weight
 * Returns the weight of the edge/arc from u to v.
 * Returns INF if G == NULL, if either vertex is invalid, or if no such edge exists.
 */
int graph_get_weight(Graph G, int u, int v);

/*
 * graph_degree
 * Returns the number of outgoing neighbors of vertex v.
 * For an undirected graph, this is the usual degree.
 * Returns -1 if G == NULL or v is invalid.
 */
int graph_degree(Graph G, int v);

/* manipulation procedures --------------------------------------------------- */

/*
 * graph_add_arc
 * Adds one directed weighted edge from u to v.
 *
 * Returns true if the arc was added.
 * Returns false if:
 *   - G == NULL
 *   - u or v is invalid
 *   - u == v
 *   - weight <= 0
 *   - an arc from u to v already exists
 *
 * The adjacency list for u must remain sorted by increasing vertex label.
 */
bool graph_add_arc(Graph G, int u, int v, int weight);

/*
 * graph_add_edge
 * Adds one undirected weighted edge between u and v.
 *
 * This should create both:
 *   u -> v
 *   v -> u
 *
 * Returns true if the edge was added.
 * Returns false if:
 *   - G == NULL
 *   - u or v is invalid
 *   - u == v
 *   - weight <= 0
 *   - an edge/arc from u to v or v to u already exists
 *
 * If either direction already exists because of a previous graph_add_arc call,
 * graph_add_edge must reject the insertion and return false.
 *
 * Both affected adjacency lists must remain sorted by increasing vertex label.
 */
bool graph_add_edge(Graph G, int u, int v, int weight);

/* output -------------------------------------------------------------------- */

/*
 * graph_print
 * Prints the adjacency-list representation of G to out.
 *
 * Required format:
 *
 * 1: (2, 5) (3, 2)
 * 2: (1, 5)
 * 3:
 *
 * If a vertex has no outgoing neighbors, print only:
 *
 * 3:
 *
 * Do not print trailing spaces at the end of any line.
 *
 * Does nothing if G == NULL or out == NULL.
 */
void graph_print(FILE* out, Graph G);

#endif
