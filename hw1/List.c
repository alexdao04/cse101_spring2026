#include <stdio.h>
#include <stdlib.h>
#include "List.h"

//----------------------------------------------------
// List.c
// Implementation file for List ADT
//
// You must complete all functions marked TODO.
//----------------------------------------------------


// Private Node structure ----------------------------

typedef struct NodeObj {
    ListElement data;
    struct NodeObj* next;
    struct NodeObj* prev;
} NodeObj;

typedef NodeObj* Node;


// Private List structure ----------------------------

typedef struct ListObj {
    Node front;
    Node back;
    Node cursor;
    int length;
    int index;   // cursor position, -1 if undefined
} ListObj;


// Helper: create new node ---------------------------

static Node newNode(ListElement data) {
    Node N = malloc(sizeof(NodeObj));
    N->data = data;
    N->next = NULL;
    N->prev = NULL;
    return N;
}


// Constructors --------------------------------------

List newList(void) {
    List L = malloc(sizeof(ListObj));
    L->front = NULL;
    L->back = NULL;
    L->cursor = NULL;
    L->length = 0;
    L->index = -1;
    return L;
}


/**
 * TODO:
 * - Free all nodes
 * - Free list object
 * - Set *pL = NULL
 */
void freeList(List* pL) {
    // TODO
}


// Access functions ----------------------------------

int length(List L) {
    return L->length;
}

int position(List L) {
    return L->index;
}


/**
 * TODO:
 * Return front->data
 */
ListElement front(List L) {
    // TODO
    return 0;
}


/**
 * TODO:
 * Return back->data
 */
ListElement back(List L) {
    // TODO
    return 0;
}


/**
 * TODO:
 * Return cursor->data
 */
ListElement get(List L) {
    // TODO
    return 0;
}


/**
 * TODO:
 * Compare elements one by one
 */
bool equals(List A, List B) {
    // TODO
    return false;
}


// Manipulation procedures ----------------------------

/**
 * TODO:
 * Delete all nodes, reset fields
 */
void clear(List L) {
    // TODO
}


/**
 * TODO:
 * Set cursor->data = x
 */
void set(List L, ListElement x) {
    // TODO
}


/**
 * TODO:
 * If non-empty → cursor = front
 */
void moveFront(List L) {
    // TODO
}


/**
 * TODO:
 * If non-empty → cursor = back
 */
void moveBack(List L) {
    // TODO
}


/**
 * TODO:
 * Move cursor backward
 */
void movePrev(List L) {
    // TODO
}


/**
 * TODO:
 * Move cursor forward
 */
void moveNext(List L) {
    // TODO
}


/**
 * TODO:
 * Insert at front
 */
void prepend(List L, ListElement x) {
    // TODO
}


/**
 * TODO:
 * Insert at back
 */
void append(List L, ListElement x) {
    // TODO
}


/**
 * TODO:
 * Insert before cursor
 */
void insertBefore(List L, ListElement x) {
    // TODO
}


/**
 * TODO:
 * Insert after cursor
 */
void insertAfter(List L, ListElement x) {
    // TODO
}


/**
 * TODO:
 * Delete front node
 */
void deleteFront(List L) {
    // TODO
}


/**
 * TODO:
 * Delete back node
 */
void deleteBack(List L) {
    // TODO
}


/**
 * TODO:
 * Delete cursor node
 */
void delete(List L) {
    // TODO
}


// Output --------------------------------------------

void printList(FILE* out, List L) {
    Node N = L->front;
    fprintf(out, "(");
    while (N != NULL) {
        fprintf(out, "%d", N->data);
        if (N->next != NULL) fprintf(out, ", ");
        N = N->next;
    }
    fprintf(out, ")");
}