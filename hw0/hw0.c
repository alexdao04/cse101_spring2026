#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(void) {
    Stack s;
    FILE *fp;

    initStack(&s);

    push(&s, 10);
    push(&s, 20);

    fp = fopen("output", "w");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open output file\n");
        return 1;
    }

    fprintf(fp, "Top element: %d\n", peek(&s));
    fprintf(fp, "Popped: %d\n", pop(&s));

    fclose(fp);
    return 0;
}