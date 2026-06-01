#include "pathfinder.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * pathfinder.c
 *
 * Starter file for Prog 4.
 *
 * Prog 4 is framed as a campus route finder, but the implementation still uses
 * the same weighted graph and Dijkstra shortest-path logic.
 *
 * Complete the TODOs in this file.
 * Do not modify pathfinder.h.
 */

/* result management --------------------------------------------------------- */

PathResult* path_result_create(int n) {
    // TODO:
    // 1. Reject n <= 0.
    // 2. Allocate a PathResult.
    // 3. Allocate dist, parent, and visited arrays with length n + 1.
    // 4. Initialize fields and return the result.
    (void)n;

    PathResult* result = malloc(sizeof(PathResult));

    if(n <= 0 || result == NULL) {
        return NULL; // base condition as specced in TODO
    }

    PathResult* dist = malloc(sizeof(int) * (n + 1));

    PathResult* parent = malloc(sizeof(int) * (n + 1));

    PathResult* visited = malloc(sizeof(bool) * (n + 1));

    if(dist == NULL || parent == NULL || visited == NULL) {
        // guard for malloc failure
        free(dist);

        free(parent);

        free(visited);

        free(result); // free the PathResult object last
        return NULL;
    }

    return result;
}

void path_result_destroy(PathResult** pResult) {
    // TODO:
    // 1. Check pResult and *pResult.
    // 2. Free dist, parent, and visited arrays.
    // 3. Free the PathResult object.
    // 4. Set *pResult to NULL.

    if(pResult == NULL || *pResult == NULL) {
        return;
    }
    
    free((*pResult)->dist);

    free((*pResult)->parent);

    free((*pResult)->visited);

    free(*pResult);

    *pResult = NULL;
}

void path_result_reset(PathResult* result, int source) {
    // TODO:
    // Reset all arrays:
    //   dist[v] = INF
    //   parent[v] = NIL
    //   visited[v] = false
    // Then set:
    //   dist[source] = 0
    //   result->source = source
    (void)result;
    (void)source;
}

/* graph loading ------------------------------------------------------------- */

bool pathfinder_read_graph_file(const char* filename, Graph* pG) {
    // TODO:
    // 1. Open filename for reading.
    // 2. Read the number of vertices.
    // 3. Create a Graph.
    // 4. Read lines of the form: u v weight
    // 5. Stop when the line is: 0 0 0
    // 6. Add each edge as an undirected edge using graph_add_edge.
    // 7. Store the graph in *pG and return true.
    //
    // On failure, clean up and return false.
    (void)filename;
    (void)pG;
    return false;
}

/* private shortest-path helpers -------------------------------------------- */

/*
 * choose_min_unvisited
 * Returns the unvisited vertex with the smallest distance.
 *
 * Tie-breaking:
 * If multiple unvisited vertices have the same smallest distance, return the
 * smaller vertex label.
 *
 * Returns NIL if there is no reachable unvisited vertex left.
 */
static int choose_min_unvisited(PathResult* result) {
    // TODO: Implement the min-distance selection step for O(V^2) Dijkstra.
    (void)result;
    return NIL;
}

/* shortest paths ------------------------------------------------------------ */

void pathfinder_dijkstra(Graph G, int source, PathResult* result) {
    // TODO:
    // Implement the simple O(V^2) version of Dijkstra's algorithm.
    //
    // Required behavior:
    // 1. Reset result for the given source.
    // 2. Repeatedly choose the unvisited vertex u with smallest dist[u].
    // 3. Mark u visited.
    // 4. For each possible vertex v from 1 to graph_order(G):
    //      - if v is unvisited and edge u->v exists:
    //          try to relax the edge.
    //
    // Use graph_get_weight(G, u, v) to inspect edge weights.
    // Do not use negative weights.
    (void)G;
    (void)source;
    (void)result;
}

bool pathfinder_build_path(PathResult* result, int destination,
                           int path_out[], int* path_len) {
    // TODO:
    // Build the path from result->source to destination using parent links.
    //
    // Hints:
    // - If destination is unreachable, return false.
    // - First collect vertices backward from destination to source.
    // - Then reverse them into path_out.
    // - Store the number of path vertices in *path_len.
    (void)result;
    (void)destination;
    (void)path_out;
    (void)path_len;
    return false;
}

/* command output helpers ---------------------------------------------------- */

void pathfinder_print_dist(FILE* out, Graph G, int source, int destination) {
    // TODO:
    // Print exactly:
    //
    // DIST s d: X
    //
    // or:
    //
    // DIST s d: infinity
    //
    // Run Dijkstra from source before checking the destination distance.
    (void)out;
    (void)G;
    (void)source;
    (void)destination;
}

void pathfinder_print_path(FILE* out, Graph G, int source, int destination) {
    // TODO:
    // Print exactly:
    //
    // PATH s d: v1 v2 v3
    //
    // or:
    //
    // PATH s d: no path
    //
    // Run Dijkstra from source, then reconstruct the path.
    (void)out;
    (void)G;
    (void)source;
    (void)destination;
}

void pathfinder_print_reachable(FILE* out, Graph G, int source) {
    // TODO:
    // Print exactly:
    //
    // REACHABLE s: v1(d1) v2(d2) v3(d3)
    //
    // Reachable vertices must be printed in increasing vertex label order.
    // The source should be included with distance 0.
    (void)out;
    (void)G;
    (void)source;
}

void pathfinder_process_commands(FILE* in, FILE* out, Graph G) {
    // TODO:
    // Read commands from in until EOF.
    //
    // Supported commands:
    //   PRINT
    //   DIST source destination
    //   PATH source destination
    //   REACHABLE source
    //
    // PRINT should output:
    //   PRINT:
    //   <graph printed by graph_print>
    //
    // Other command output should be delegated to the helper functions above.
    (void)in;
    (void)out;
    (void)G;
}
