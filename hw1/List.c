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
    if(pL == NULL || *pL == NULL) { 
        // handle empty list case
        return;
    } while(*pL != NULL) {
        Node *temp = *pL -> front; // point temp to front of list
        while(temp != NULL) {
            Node *next = temp -> next; // create pointer to next node before freeing temp
            free(temp);
            temp = next;
        }
    }
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
    if(L->length == 0) {
        return 0; // handles empty list
    }
    else {
        return L->front->data;
    }
    return 0;
}


/**
 * TODO:
 * Return back->data
 */
ListElement back(List L) {
    // TODO
    if(L->length == 0) {
        return 0; // empty list case
    }
    else {
        return L->back->data;
    }
    return 0;
}


/**
 * TODO:
 * Return cursor->data
 */
ListElement get(List L) {
    // TODO
    if(L->length == 0 || L->index < 0) { // empty list or undefined cursor (index at -1)
        return 0;
    } else {
        return L->cursor->data;
    }
    return 0;
}


/**
 * TODO:
 * Compare elements one by one
 */
bool equals(List A, List B) {
    // TODO
    if(A->length != B->length) {
        return false;
    } else {

    }
    return false;
}


// Manipulation procedures ----------------------------

/**
 * TODO:
 * Delete all nodes, reset fields
 */
void clear(List L) {
    // TODO
    if(length(L) == 0) {
        return; // empty list
    } else {
        Node *temp = L->front; // start at front of list
        while(temp != NULL) { // when list is not empty
            Node *next = temp -> next; // store the next node before freeing temp
            free(temp); // free temp from memory
            temp = next; // temp moves to the next node in the list to remove the next node present
        }
    }
}


/**
 * TODO:
 * Set cursor->data = x
 */
void set(List L, ListElement x) {
    // TODO
    if(L->length == 0 || L->index < 0) {
        return; // empty list/undefined index
    } else {
        L->cursor->data = x; // else set cursor -> data = x as required
    }
    
}


/**
 * TODO:
 * If non-empty → cursor = front
 */
void moveFront(List L) {
    // TODO
    if(L->length == 0) {
        return; // empty list case
    } else {
        L->cursor = L->front;
        L->index = 0; // set index to 0 where the front is
    }
}


/**
 * TODO:
 * If non-empty → cursor = back
 */
void moveBack(List L) {
    // TODO
    if(L->length == 0) {
        return;
    } else {
        L->cursor = L->back;
        L->index = L->length - 1; // move back index (length -1 is like i-- incrementing)
    }
}


/**
 * TODO:
 * Move cursor backward
 */
void movePrev(List L) {
    // TODO
    if(L->length == 0 || L->index <= 0) {
        return;
    } else {
        L->cursor = L->cursor->prev;
        L->index--; // move back index
    }
}


/**
 * TODO:
 * Move cursor forward
 */
void moveNext(List L) {
    // TODO
    if(L->length == 0 || L->index >= L->length - 1) {
        return;
    } else {
        L->cursor = L->cursor->next;
        L->index++; // move forward index
    }
}


/**
 * TODO:
 * Insert at front
 */
void prepend(List L, ListElement x) {
    // TODO
    if(L->length == 0) { // empty list case
        Node N = newNode(x);
        L->front = N;
        L->back = N; // front and back are the same node if empty list

    }
}


/**
 * TODO:
 * Insert at back
 */
void append(List L, ListElement x) {
    // TODO
    if(L->length == 0) {
        Node N = newNode(x);
        L->front = N;
        L->back = N;
    }
}


/**
 * TODO:
 * Insert before cursor
 */
void insertBefore(List L, ListElement x) {
    // TODO
    if(L->length == 0 || L->index < 0) {
        return;
    }
}


/**
 * TODO:
 * Insert after cursor
 */
void insertAfter(List L, ListElement x) {
    // TODO
    if(L->length == 0 || L->index < 0) {
        return;
    }
}


/**
 * TODO:
 * Delete front node
 */
void deleteFront(List L) {
    // TODO
    if(L->length == 0) {
        return;
    }
}


/**
 * TODO:
 * Delete back node
 */
void deleteBack(List L) {
    // TODO
    if(L->length == 0) {
        return;
    }
}


/**
 * TODO:
 * Delete cursor node
 */
void delete(List L) {
    // TODO
    if(L->length == 0 || L->index < 0) {
        return;
    }
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