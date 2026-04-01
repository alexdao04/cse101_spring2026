#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define MAX 100

typedef struct {
    int items[MAX];
    int top;
} Stack;

void initStack(Stack *s);
bool isFull(Stack *s);
bool isEmpty(Stack *s);
void push(Stack *s, int val);
int pop(Stack *s);
int peek(Stack *s);

#endif