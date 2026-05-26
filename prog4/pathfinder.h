#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "Graph.h"

#include <stdbool.h>
#include <stdio.h>

/*
 * pathfinder.h
 *
 * Public interface for the Prog 4 shortest-path application.
 *
 * The application is framed as a campus route finder. Vertices represent
 * locations, edges represent paths, and weights represent travel times or costs.
 *
 * Do not modify this file.
 */

#define NIL -1

typedef struct PathResult {
    int source;
    int num_vertices;
    int* dist;
    int* parent;
    bool* visited;
} PathResult;

/* result management --------------------------------------------------------- */

/*
 * path_result_create
 * Allocates a PathResult for a graph with n vertices.
 * Arrays should be allocated with length n + 1 so vertex labels can be used
 * directly as array indices.
 *
 * Returns NULL if n <= 0 or memory allocation fails.
 */
PathResult* path_result_create(int n);

/*
 * path_result_destroy
 * Frees all heap memory associated with *pResult and sets *pResult to NULL.
 */
void path_result_destroy(PathResult** pResult);

/*
 * path_result_reset
 * Resets result arrays before running Dijkstra from source.
 *
 * dist[v] should become INF.
 * parent[v] should become NIL.
 * visited[v] should become false.
 * dist[source] should become 0.
 * source should be stored in result->source.
 */
void path_result_reset(PathResult* result, int source);

/* graph loading ------------------------------------------------------------- */

/*
 * pathfinder_read_graph_file
 * Reads one weighted undirected graph from filename.
 *
 * Input format:
 *   <num_vertices>
 *   <u> <v> <weight>
 *   <u> <v> <weight>
 *   ...
 *   0 0 0
 *
 * On success:
 *   - stores the newly created graph in *pG
 *   - returns true
 *
 * On failure:
 *   - frees any partially created graph
 *   - stores NULL in *pG
 *   - returns false
 */
bool pathfinder_read_graph_file(const char* filename, Graph* pG);

/* shortest paths ------------------------------------------------------------ */

/*
 * pathfinder_dijkstra
 * Runs the simple O(V^2) version of Dijkstra's algorithm from source.
 *
 * Tie-breaking rules:
 *   - When choosing the next unvisited vertex with smallest distance, choose
 *     the smaller vertex label if there is a tie.
 *   - Process possible neighbors in increasing vertex label order.
 *   - Only update parent[v] when a strictly shorter path is found.
 */
void pathfinder_dijkstra(Graph G, int source, PathResult* result);

/*
 * pathfinder_build_path
 * Builds the path from result->source to destination using result->parent.
 *
 * The path should be written into path_out in source-to-destination order.
 * The number of vertices in the path should be stored in *path_len.
 *
 * Returns true if a path exists.
 * Returns false if destination is unreachable or arguments are invalid.
 */
bool pathfinder_build_path(PathResult* result, int destination,
                           int path_out[], int* path_len);

/* command output helpers ---------------------------------------------------- */

/*
 * pathfinder_print_dist
 * Prints output for:
 *   DIST <source> <destination>
 */
void pathfinder_print_dist(FILE* out, Graph G, int source, int destination);

/*
 * pathfinder_print_path
 * Prints output for:
 *   PATH <source> <destination>
 */
void pathfinder_print_path(FILE* out, Graph G, int source, int destination);

/*
 * pathfinder_print_reachable
 * Prints output for:
 *   REACHABLE <source>
 */
void pathfinder_print_reachable(FILE* out, Graph G, int source);

/*
 * pathfinder_process_commands
 * Reads commands from in until EOF and writes command output to out.
 *
 * Supported commands:
 *   PRINT
 *   DIST <source> <destination>
 *   PATH <source> <destination>
 *   REACHABLE <source>
 */
void pathfinder_process_commands(FILE* in, FILE* out, Graph G);

#endif
