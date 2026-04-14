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
    if(pL == NULL || *pL == NULL);
        // TODO
        return 0;
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