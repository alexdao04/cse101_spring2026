**LIST ADT IMPLEMENTATION** <br>
**CSE 101** <br>
**Prof. Alex Pang** <br>
**Alexander Dao** <br>
<br>
<br>
We have a bunch of functions in here. <br>
Take a look at the following. These were pulled straight out of list.h.<br>
I'll comment them out and detail my thinking of how I will implement each. <br>


/**
 * TODO:
 * - Free all nodes
 * - Free list object
 * - Set *pL = NULL
 */
void freeList(List* pL) {
    // TODO
    // start by setting up base case; when LL is pointing to an empty list
    // return said empty list and exit out
    // if list is not empty, we do the following:
    // 
    return 0;
}


/**
 * TODO:
 * Return front->data
 */
ListElement front(List L) {
    // TODO
    // the overarching idea here is that we need to figure out a way to iterate
    // through each element present in the list.
    // although this is just for the front i think the core logic
    // stays the same; recurse through a for loop to the target node (whether front, back, or Nth), 
    // provide a base case and then we should be good
    return 0;
}


/**
 * TODO:
 * Return back->data
 */
ListElement back(List L) {
    // TODO
    // same thing here. reference front to get an idea
    return 0;
}


/**
 * TODO:
 * Return cursor->data
 */
ListElement get(List L) {
    // TODO
    // sliding pointer concept; we can review what we know from class for this one
    return 0;
}


/**
 * TODO:
 * Compare elements one by one
 */
bool equals(List A, List B) {
    // TODO
    // i'll figure out what this does later
    return false;
}


// Manipulation procedures ----------------------------

/**
 * TODO:
 * Delete all nodes, reset fields
 */
void clear(List L) {
    // TODO
    // delete all nodes and reset the fields
    // not just free memory like earlier 
    // (although that could become a helper function)
}


/**
 * TODO:
 * Set cursor->data = x
 */
void set(List L, ListElement x) {
    // TODO
    // figure this one out later
}


/**
 * TODO:
 * If non-empty → cursor = front
 */
void moveFront(List L) {
    // TODO
    // what do they mean by cursor?
}


/**
 * TODO:
 * If non-empty → cursor = back
 */
void moveBack(List L) {
    // TODO
    // what does this do
}


/**
 * TODO:
 * Move cursor backward
 */
void movePrev(List L) {
    // TODO
    // not sure what this does
}


/**
 * TODO:
 * Move cursor forward
 */
void moveNext(List L) {
    // TODO
    // same thing here
}


/**
 * TODO:
 * Insert at front
 */
void prepend(List L, ListElement x) {
    // TODO
    // prepend should add a node at the beginning of the list
}


/**
 * TODO:
 * Insert at back
 */
void append(List L, ListElement x) {
    // TODO
    // we saw this one in class. review whatever notes you have on that one
    // add a node at the nth node type stuff
}


/**
 * TODO:
 * Insert before cursor
 */
void insertBefore(List L, ListElement x) {
    // TODO
    // likely needs a prev (for DLL)
}


/**
 * TODO:
 * Insert after cursor
 */
void insertAfter(List L, ListElement x) {
    // TODO
    // insert at next from last element, have last element point to NULL
}


/**
 * TODO:
 * Delete front node
 */
void deleteFront(List L) {
    // TODO
    // delete front.
}


/**
 * TODO:
 * Delete back node
 */
void deleteBack(List L) {
    // delete the last node in the list
    // recall the CDLL concept
}


/**
 * TODO:
 * Delete cursor node
 */
void delete(List L) {
    // delete the node currently pointed to
}