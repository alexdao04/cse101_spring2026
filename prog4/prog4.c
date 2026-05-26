#include "Graph.h"
#include "pathfinder.h"

#include <stdio.h>

/*
 * prog4.c
 *
 * Main client for Prog 4.
 *
 * Prog 4 is framed as a small campus route finder. The graph uses integer
 * vertex labels to represent locations, and edge weights represent travel
 * times or costs.
 *
 * Usage:
 *   ./prog4 graph.txt < commands.in
 */

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <graph file>\n", argv[0]);
        return 1;
    }

    Graph G = NULL;

    if (!pathfinder_read_graph_file(argv[1], &G)) {
        fprintf(stderr, "Error: could not read graph file\n");
        return 1;
    }

    pathfinder_process_commands(stdin, stdout, G);

    graph_destroy(&G);
    return 0;
}
