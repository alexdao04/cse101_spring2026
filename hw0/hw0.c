#include <stdio.h>
#include "stack.h"

int main(void) {
    // Write required program output to file named "output".
    FILE *f = fopen("output", "w");
    if (!f) { // when file doesnt exist
        return 1;
    }

    // Demonstrate Stack ADT usage.
    Stack *s = stack_create(5);

    // Push characters; pop order will be reversed (LIFO behavior).
    stack_push(s, 'H');
    stack_push(s, 'W');
    stack_push(s, '0');

    // Output is guaranteed non-empty string.
    fprintf(f, "Stack pop order: ");
    while (!stack_empty(s)) {
        fputc(stack_pop(s), f);
    }
    fprintf(f, "\n");

    // Clean up resources.
    stack_delete(&s);
    fclose(f);

    return 0;
}