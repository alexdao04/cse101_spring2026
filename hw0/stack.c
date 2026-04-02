#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// Creates a new Stack with specified capacity
Stack *stack_create(int capacity) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    assert(s != NULL);
    s->items = (int *)malloc(capacity * sizeof(int));
    assert(s->items != NULL);
    s->capacity = capacity;
    s->top = -1;
    return s;
}

// Frees all memory associated with the Stack
void stack_delete(Stack **s) {
    if (*s != NULL) {
        free((*s)->items);
        free(*s);
        *s = NULL;
    }
}

// Pushes x onto the Stack
void stack_push(Stack *s, int x) {
    assert(s != NULL);
    assert(!stack_full(s));
    s->items[++s->top] = x;
}

// Pops and returns the top element from the Stack
int stack_pop(Stack *s) {
    assert(s != NULL);
    assert(!stack_empty(s));
    return s->items[s->top--];
}

// Returns the top element without removing it
int stack_peek(Stack *s) {
    assert(s != NULL);
    assert(!stack_empty(s));
    return s->items[s->top];
}

// Returns 1 if Stack is empty, 0 otherwise
int stack_empty(Stack *s) {
    return s->top == -1;
}

// Returns 1 if Stack is full, 0 otherwise
int stack_full(Stack *s) {
    return s->top == s->capacity - 1;
}

// Prints all elements in the Stack
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