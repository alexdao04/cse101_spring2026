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
    if(pL == NULL || *pL == NULL) return; // empty list case
    clear(*pL); // call clear helper function
    free(*pL); // call free on the list object when done
    *pL = NULL; // set pL (the pointer to the list) to null
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
    if(A==NULL || B==NULL) return false;
    if(A->length != B->length) return false; // check if lists have the same length
    Node tempA = A->front; // load tempA with the front of list A
    Node tempB = B->front; // do the same thing so we can set up a comparison
    while(tempA != NULL && tempB != NULL) {
        if(tempA->data != tempB->data) { // double check if the data is the same
            return false;
        }
        tempA = tempA->next; // move forward
        tempB = tempB->next; // same thing
    }
    return true;
}


// Manipulation procedures ----------------------------

/**
 * TODO:
 * Delete all nodes, reset fields
 */
void clear(List L) {
    // TODO
    if(L->length == 0) {
        return; // empty list
    } else {
        Node temp = L->front; // start at front of list
        while(temp != NULL) { // when list is not empty
            Node next = temp->next; // store the next node before freeing temp
            free(temp); // free temp from memory
            temp = next; // temp moves to the next node in the list to remove the next node present
        }
        // we need to reset front, back, cursor, length, and index fields
        L->front = NULL;
        L->back = NULL;
        L->cursor = NULL;
        L->length = 0;
        L->index = -1; // cursor undefined, first element is 0 (remember that!)
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
    if(L->length == 0 || L->cursor == NULL) return; // length and cursor pos check
    if(L->cursor == L->front) {
        L->cursor = NULL;
        L->index = -1; // cursor is undefined because we're at the front
    } else {
        L->cursor = L->cursor->prev;
        L->index--; // move back index position
    }
}


/**
 * TODO:
 * Move cursor forward
 */
void moveNext(List L) {
    // TODO
    if(L->length == 0 || L->cursor == NULL) return; // length and cursor pos check
    if(L->cursor == L->back) {
        L->cursor = NULL;
        L->index = -1;
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
    if(L==NULL) return; // empty list case
    Node N = newNode(x);
    if(L->length == 0) { // empty list case
        L->front = N;
        L->back = N; // front and back are the same node if empty list
    } else {
        N->next = L->front;
        L->front->prev = N;
        L->front = N;
        if(L->index != -1) {
            L->index++; // if cursor is defined, we need to move it forward since we're inserting at the front
        }
    }
    L->length++; // increment length of list
}


/**
 * TODO:
 * Insert at back
 */
void append(List L, ListElement x) {
    // TODO
    if(L->length == 0) {
        Node N = newNode(x); // front and back are the same node when we have an empty list
        L->length++; // increment length of list, we're adding a node
        L->front = N;
        L->back = N;
    } else {
        Node N = newNode(x); // create new node with data x
        L->length++; // increment length of list since we're adding a node
        L->back->next = N; // append at the end of the list
        N->prev = L->back; // set the node before N to become back
        L->back = N; // set back to become N since we're inserting at the back
    } // come back to this part
}


/**
 * TODO:
 * Insert before cursor
 */
void insertBefore(List L, ListElement x) {
    // TODO
    if(L->length == 0 || L == NULL || L->index < 0) return; // empty list case
    if(L->cursor == L->front) {
        prepend(L,x); 
        return; // use prepend as helper function here
    }
    Node N = newNode(x);
    N->prev = L->cursor->prev; // stage prev at the node before cursor
    N->next = L->cursor; // set N's next to where cursor points
    L->cursor->prev->next = N; // if so then that prev's next becomes N, right?
    L->cursor->prev = N; // front and back would be the same if prev is null
    // if prev null then cursor is at front of list and N should become the new front
    L->length++; // increment length of list since we're adding a node
    L->index++; // move cursor forward since we're inserting before the cursor
    }


/**
 * TODO:
 * Insert after cursor
 */
void insertAfter(List L, ListElement x) {
    // TODO
    if(L->length == 0 || L->index < 0) return;
    if(L->cursor == L->back) {
        append(L,x);
        return; // use append as helper function here
    }
        Node N = newNode(x);
        L->length++;
        N->next = L->cursor->next; // N points to the node after cursor
        N->prev = L->cursor;
        L->cursor->next->prev = N; // set the node after cursor's prev to N
        L->cursor->next = N; // if node after cursor is null then we're at the end of the list
}


/**
 * TODO:
 * Delete front node
 */
void deleteFront(List L) {
    // TODO
    if(L->length == 0 || L==NULL) return;
    Node temp = L->front; // point temp to front of list
        // we want to do some pointer manipulation before we free temp
    if(L->length == 1) { // when theres only one element in the list
        L->front = NULL;
        L->back = NULL; // front and back would be the same here
    } else {
        L->front = temp->next;
        L->front->prev = NULL;
    }
    if(L->cursor == temp) { // if the cursor is at the front, we need to move it to the next node since we're deleting the front node
        L->cursor = NULL;
        L->index = -1; // cursor becomes undefined since we're deleting the front node
    } else if(L->index != -1) {
        L->index--; // if cursor defined and not at front, move it back
    }
    free(temp); // free temp from memory
    L->length--; // decrement length of list since we're deleting a node
}


/**
 * TODO:
 * Delete back node
 */
void deleteBack(List L) {
    // TODO
    if(L->length == 0 || L == NULL) return;
    Node temp = L->back; // start by pointing temp to the back of the list
    if(L->length==1) {
        L->front = NULL;
        L->back = NULL; // front and back would be the same here
    } else {
        L->back = temp->prev;
        L->back->next = NULL; // opposite operation of deleteFront
    }
    if(L->cursor == temp) { // if the cursor is at the back, we need to move it to the previous node since we're deleting the back node
        L->cursor = NULL;
        L->index = -1; // cursor becomes undefined since we're deleting the back node
    }
    free(temp); // free temp from memory
    L->length--; // decrement length of list since we're deleting a node
}


/**
 * TODO:
 * Delete cursor node
 */
void delete(List L) {
    // TODO
    if(L->length == 0 || L==NULL || L->index < 0) return; // base case condition
    if(L->cursor == L->front) {
        deleteFront(L); 
        return;
    }
    if(L->cursor == L->back) {
        deleteBack(L);
        return;
    }
    Node temp = L->cursor;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev; // set the next and prev of the nodes around temp to point to each other, effectively removing temp from the list
    free(temp); // free temp from memory
    L->cursor = NULL; // cursor becomes undefined since we're deleting the cursor node
    L->index = -1;
    L->length--; // decrement length of list since we're deleting a node
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