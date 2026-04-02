#ifndef STACK_H
#define STACK_H

#include <stdint.h>

typedef struct {
    int *items;
    int capacity;
    int top;
} Stack;

Stack *stack_create(int capacity);
void stack_delete(Stack **s);
void stack_push(Stack *s, int x);
int stack_pop(Stack *s);
int stack_peek(Stack *s);
int stack_empty(Stack *s);
int stack_full(Stack *s);
void stack_print(Stack *s);

#endif