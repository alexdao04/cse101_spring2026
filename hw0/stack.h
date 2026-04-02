#ifndef STACK_H
#define STACK_H

// Array-backed stack ADT for integers.
// top == -1 means empty stack.

typedef struct {
    int *items;
    int capacity;
    int top;
} Stack;

// Allocate and initialize a stack with the given capacity.
Stack *stack_create(int capacity);

// Free stack memory and set caller's pointer to NULL.
void stack_delete(Stack **s);

// Push value x onto the stack. Requires stack is not full.
void stack_push(Stack *s, int x);

// Remove and return top value. Requires stack is not empty.
int stack_pop(Stack *s);

// Return top value without removing it. Requires non-empty stack.
int stack_peek(Stack *s);

// Return 1 if empty, 0 otherwise.
int stack_empty(Stack *s);

// Return 1 if full, 0 otherwise.
int stack_full(Stack *s);

// Print stack contents from bottom to top.
void stack_print(Stack *s);

#endif