#include <stdio.h>
#include "stack.h"

int main(void) {
    FILE *f = fopen("output", "w");
    if (!f) {
        return 1;
    }

    Stack *s = stack_create(5);

    stack_push(s, 'H');
    stack_push(s, 'W');
    stack_push(s, '0');

    fprintf(f, "Stack pop order: ");
    while (!stack_empty(s)) {
        fputc(stack_pop(s), f);
    }
    fprintf(f, "\n");

    stack_delete(&s);
    fclose(f);

    return 0;
}