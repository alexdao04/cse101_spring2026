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
        Node *temp = (*pL) -> front; // point temp to front of list
        while(temp != NULL) {
            Node *next = (*temp) -> next; // create pointer to next node before freeing temp
            free(temp); // go through each node and free them one by one
            temp = next; // temp is now pointing to the next node in the list once that node was freed
            // this repeats until we reach the end where all nodes are freed and temp is null
            // you set temp to point the next node before freeing what was stored there to maintain the rest of the list structure
        }
        free(*pL); // free list object once all nodes freed
        *pL = NULL; // pointer set to null after freed (no dangling ptrs)
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
            Node *next = (*temp) -> next; // store the next node before freeing temp
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
    } else {
        Node N = newNode(x);
        L->back->next = N; // append at the end of the list
        N->prev = L->back; // set the node before N to become back
    } // come back to this part
}


/**
 * TODO:
 * Insert before cursor
 */
void insertBefore(List L, ListElement x) {
    // TODO
    if(L->length == 0 || L->index < 0) {
        return;
    } else {
        Node N = newNode(x);
        N->next = L->cursor; // set N's next to where cursor points
        N->prev = L->cursor->prev; // stage prev at the node before cursor
        if(L->cursor->prev != NULL) { // check if node before cursor is not null
            L->cursor->prev->next = N; // if so then that prev's next becomes N, right?
        } else {
            L->front = N; // front and back would be the same if prev is null
            // if prev null then cursor is at front of list and N should become the new front
        }
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
    } else {
        Node N = newNode(x);
        N->prev = L->cursor;
        N->next = L->cursor->next; // N points to the node after cursor
        if(L->cursor->next != NULL) { // if node after cursor not null
            L->cursor->next->prev = N; // set the node after cursor's prev to N
        } else {
            L->back = N; // if node after cursor is null then we're at the end of the list
        }
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
    } else {
        Node *temp = L->front; // point temp to front of list
        // we want to do some pointer manipulation before we free temp
        if(L->front->next != NULL) { // if there's a node after the front
        // that means that we're not at the end of the list
            L->front->next->prev = NULL; // uhhhh set the node before front next to null since we're deleting the front
            // that was the old front node
            free(temp);
            L->front = L->front->next; // point the empty front to the next node in the list 
        }
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
    } else {
        Node *temp = L->back; // start by pointing temp to the back of the list
        if(L->back->prev != NULL) { // we're assuming that theres a node before the back node
            // this tells us we're not at the front of the list
            L->back->prev->next = NULL; // same logic as deleteFront kind of but reversed
            free(temp);
            L->back = L->back->prev; // point empty back to the previous node in the list
            // back node should now be the node before it (removing the last element)
        }
    }
}


/**
 * TODO:
 * Delete cursor node
 */
void delete(List L) {
    // TODO
    if(L->length == 0 || L->index < 0) { // base case
        return;
    } else { // if the list is not empty and the cursor is valid
        Node *temp = L->cursor; // temp points to where the cursor is
        if(L->cursor->prev != NULL) { // if there's node before the cursor (we're not at the front)
            L->cursor->prev->next = L->cursor->next; // remember what the prof was saying in class about "marching" pointers
            // if there's a node before cursor, that node's next points to the node after cursor (skipping what's at cursor)
        } else {
            L->front = L->cursor->next; // if there's no nodes before the front one
            // the cursor would be at front currently and would point to the next node that cursor's next points to
        }
        if(L->cursor->next != NULL) { // same idea; if there's nodes after the back (we're not at the end)
            L->cursor->next->prev = L->cursor->prev; // remember what the prof was saying in class about "marching" pointers
            // if there's a node after cursor, that node's prev points to the node before cursor (skipping what's at cursor)
            // works backwards instead
        } else {
            L->back = L->cursor->prev; // if there's no nodes after the back one
            // the cursor would be at back currently and would point to the previous node that cursor's prev points to
        }
        free(temp);
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