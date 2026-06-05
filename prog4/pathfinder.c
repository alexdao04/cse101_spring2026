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

    result->dist = malloc(sizeof(int) * (n + 1));

    result->parent = malloc(sizeof(int) * (n + 1));

    result->visited = malloc(sizeof(bool) * (n + 1));

    if(n <= 0 || result == NULL ||result->dist == NULL || 
        result->parent == NULL || result->visited == NULL) {
        // massive guard for malloc failure
        // covers step 1, and guards 2 and 3 
        free(result->dist);

        free(result->parent);

        free(result->visited);

        free(result);

        return NULL;
    }

    return result; // step 4
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

    if(result == NULL) {
        return;

    } else {
        for(int i = 0; i < result->num_vertices + 1; i++) {
            result->dist[i] = INF;

            result->parent[i] = NIL;

            result->visited[i] = false;
        }

        result->dist[source] = 0;

        result->source = source;
    }
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

    if(filename == NULL || pG == NULL) {
        return false;
    }

    FILE* in = fopen(filename, "r");

    if(in == NULL) {
        fprintf(stderr, "Error: could not open %s\n", filename);

        return false;
    }

    int num_vertices = 0;

    if(fscanf(in, "%d", &num_vertices) != 1 || num_vertices <= 0) {
        fprintf(stderr, "Error: invalid graph file format\n");

        fclose(in);

        return false;
    }

    *pG = graph_create(num_vertices);

    if(*pG == NULL) {
        fprintf(stderr, "Error: could not create graph\n");

        fclose(in);

        return false;
    }

    int u, v, weight;

    while(true) {
        if(fscanf(in, "%d %d %d", &u, &v, &weight) != 3) {
            fprintf(stderr, "Error: invalid graph file format\n");
            
            graph_destroy(pG);

            fclose(in);

            return false;
        }

        if(u == 0 && v == 0 && weight == 0) {
            break;
        }

        if(!graph_add_edge(*pG, u, v, weight)) {
            fprintf(stderr, "Error: invalid edge in graph file\n");

            graph_destroy(pG);

            fclose(in);

            return false;
        }

    }

    fclose(in);
    return true;
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
    
    int min_vertex = NIL; // initialize vertex w/ the smallest distance

    for(int i = 1; i <= result->num_vertices; i++) { // check all vertices and their associated distances
        if(!result->visited[i]) { // only consider unvisited vertices
            if(min_vertex == NIL || result->dist[i] < result->dist[min_vertex]) { // if the current min_vertex is NIL or if a new vertex has a smaller distance than the current min_vertex
                min_vertex = i; // update min_vertex as a smaller distance is found
            }
        }
    }

    return min_vertex; 
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

    if(G == NULL || result == NULL) {
        return;
    }

    path_result_reset(result, source); // step 1

    for(int i = 1; i <= result->num_vertices; i++) {
        int u = choose_min_unvisited(result);

        if(u == NIL) {
            break;
        }

        result->visited[u] = true; // step 3

        for(int v = 1; v <= result->num_vertices; v++) { // step 4
            if(!result->visited[v]) {
                int weight = graph_get_weight(G, u, v);

                if(weight > 0) { // check if edge u->v exists (and if its positive weight)
                    int new_dist = result->dist[u] + weight;

                    if(new_dist < result->dist[v]) { // relax the edge if a shorter path is found
                        result->dist[v] = new_dist;

                        result->parent[v] = u;
                    }
                }
            }
        }
    }
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

    if(result == NULL || path_out == NULL || path_len == NULL) {
        return false;
    }

    int backward_vertices_temp[result->num_vertices]; // pass by reference array that stores the path vertices backward

    int count = 0;

    int curr_vertex = destination; // start from destination and work backwards to source (as our array is backwards)

    while(curr_vertex != NIL) {
        backward_vertices_temp[count] = curr_vertex;

        count++;

        curr_vertex = result->parent[curr_vertex];
    }

    for(int i = 0; i < count; i++) { // reverse the path into path_out
        path_out[i] = backward_vertices_temp[count - 1 - i];
    }

    *path_len = count;

    return true; // 
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

    for(int i = 1; i <= graph_order(G); i++) {
        if(i == source) {
            fprintf(out, "DIST %d %d: 0\n", source, destination);

            return;
        }
    }

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

    for(int i = 1; i <= graph_order(G); i++) {
        if(i == source) {
            fprintf(out, "PATH %d %d: %d\n", source, destination, source);

            return;
        }
    }

    fprintf(out, "PATH %d %d: no path\n", source, destination);
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

    for(int i = 1; i <= graph_order(G); i++) {
        if(i == source) {
            fprintf(out, "REACHABLE %d: %d(0)\n", source, source);

            return;
        }
    }
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

    if(in == NULL) {
        fprintf(stderr, "Error: could not open commands.in\n");

        return;
    }

    if(out == NULL) {
        fprintf(stderr, "Error: could not open prog4.out\n");

        return;
    }

    for(int i = 0; i < 100; i++) {
        char command[20];

        if(fscanf(in, "%s", command) != 1) {
            break; // EOF or read error
        }

        if(strcmp(command, "PRINT") == 0) {
            fprintf(out, "PRINT:\n");

            graph_print(out, G);
        }
        else if(strcmp(command, "DIST") == 0) {
            int source, destination;

            if(fscanf(in, "%d %d", &source, &destination) != 2) {
                fprintf(stderr, "Error: invalid DIST command format\n");

                continue;
            }

            pathfinder_print_dist(out, G, source, destination);
        }
        else if(strcmp(command, "PATH") == 0) {
            int source, destination;

            if(fscanf(in, "%d %d", &source, &destination) != 2) {
                fprintf(stderr, "Error: invalid PATH command format\n");

                continue;
            }

            pathfinder_print_path(out, G, source, destination);
        }
        else if(strcmp(command, "REACHABLE") == 0) {
            int source;

            if(fscanf(in, "%d", &source) != 1) {
                fprintf(stderr, "Error: invalid REACHABLE command format\n");

                continue;
            }

            pathfinder_print_reachable(out, G, source);
        }
        else {
            fprintf(stderr, "Error: unknown command '%s'\n", command);
        }
    }
}
