#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// Create a new integer stack with fixed capacity.
Stack *stack_create(int capacity) {
    assert(capacity > 0);
    Stack *s = (Stack *)malloc(sizeof(Stack));
    assert(s != NULL);
    s->items = (int *)malloc(capacity * sizeof(int));
    assert(s->items != NULL);
    s->capacity = capacity;
    s->top = -1;
    return s;
}

// Free all memory associated with the stack.
void stack_delete(Stack **s) {
    assert(s != NULL);
    if (*s != NULL) {
        free((*s)->items);
        free(*s);
        *s = NULL;
    }
}

// Push x onto stack top.
void stack_push(Stack *s, int x) {
    assert(s != NULL);
    assert(!stack_full(s));
    s->items[++s->top] = x;
}

// Pop and return the current top value.
int stack_pop(Stack *s) {
    assert(s != NULL);
    assert(!stack_empty(s));
    return s->items[s->top--];
}

// Read top value without removing it.
int stack_peek(Stack *s) {
    assert(s != NULL);
    assert(!stack_empty(s));
    return s->items[s->top];
}

// Return 1 when empty, else 0.
int stack_empty(Stack *s) {
    return s->top == -1;
}

// Return 1 when full, else 0.
int stack_full(Stack *s) {
    return s->top == s->capacity - 1;
}

// Print stack as [a, b, c] from bottom to top.
void stack_print(Stack *s) {
    assert(s != NULL);
    printf("[");
    for (int i = 0; i <= s->top; i++) {
        printf("%d", s->items[i]);
        if (i < s->top) {
            printf(", ");
        }
    }
    printf("]\n");
}