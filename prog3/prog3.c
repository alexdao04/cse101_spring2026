#include "search_engine.h"

#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s documents.txt\n", argv[0]);
        return 1;
    }

    SearchEngine *engine = create_search_engine(argv[1]);
    if (engine == NULL) {
        fprintf(stderr, "Error: could not create search engine\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), stdin) != NULL) {
        process_command(engine, line);
    }

    destroy_search_engine(&engine);

    return 0;
}
