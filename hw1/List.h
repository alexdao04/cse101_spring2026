#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <stdio.h>

//----------------------------------------------------
// List.h
// Header file for List ADT (CSE 101 HW1)
// ---------------------------------------------------
//
// This ADT represents a doubly linked list with a cursor.
// The cursor is used to traverse the list.
//
// You MUST NOT modify this file.
//----------------------------------------------------


// Exported types ------------------------------------

typedef int ListElement;

typedef struct ListObj* List;


// Constructors-Destructors --------------------------

/**
 * @brief Creates and returns a new empty List.
 * 
 * @return List pointer to newly created list.
 */
List newList(void);


/**
 * @brief Frees all heap memory associated with *pL,
 *        and sets *pL to NULL.
 * 
 * @param pL pointer to List pointer
 */
void freeList(List* pL);


// Access functions ----------------------------------

/**
 * @brief Returns the number of elements in the list.
 * 
 * @param L list
 * @return int length of list
 */
int length(List L);


/**
 * @brief Returns the position of the cursor.
 * 
 * If cursor is undefined, returns -1.
 * 
 * @param L list
 * @return int cursor index or -1
 */
int position(List L);


/**
 * @brief Returns the front element.
 * 
 * Precondition: length(L) > 0
 */
ListElement front(List L);


/**
 * @brief Returns the back element.
 * 
 * Precondition: length(L) > 0
 */
ListElement back(List L);


/**
 * @brief Returns the element at the cursor.
 * 
 * Precondition: length(L) > 0, position(L) >= 0
 */
ListElement get(List L);


/**
 * @brief Returns true if lists A and B contain the same sequence of elements.
 * 
 * Cursor positions are ignored.
 */
bool equals(List A, List B);


// Manipulation procedures ----------------------------

/**
 * @brief Resets list to empty state.
 */
void clear(List L);


/**
 * @brief Overwrites the cursor element with x.
 * 
 * Precondition: length(L) > 0, position(L) >= 0
 */
void set(List L, ListElement x);


/**
 * @brief Moves cursor to front element.
 */
void moveFront(List L);


/**
 * @brief Moves cursor to back element.
 */
void moveBack(List L);


/**
 * @brief Moves cursor one step toward front.
 * 
 * If cursor is at front → becomes undefined.
 */
void movePrev(List L);


/**
 * @brief Moves cursor one step toward back.
 * 
 * If cursor is at back → becomes undefined.
 */
void moveNext(List L);


/**
 * @brief Inserts new element at front.
 */
void prepend(List L, ListElement x);


/**
 * @brief Inserts new element at back.
 */
void append(List L, ListElement x);


/**
 * @brief Inserts element before cursor.
 * 
 * Precondition: length(L) > 0, position(L) >= 0
 */
void insertBefore(List L, ListElement x);


/**
 * @brief Inserts element after cursor.
 * 
 * Precondition: length(L) > 0, position(L) >= 0
 */
void insertAfter(List L, ListElement x);


/**
 * @brief Deletes front element.
 * 
 * Precondition: length(L) > 0
 */
void deleteFront(List L);


/**
 * @brief Deletes back element.
 * 
 * Precondition: length(L) > 0
 */
void deleteBack(List L);


/**
 * @brief Deletes cursor element.
 * 
 * Cursor becomes undefined.
 * 
 * Precondition: length(L) > 0, position(L) >= 0
 */
void delete(List L);


// Other operations ----------------------------------

/**
 * @brief Prints list in format:
 * (1, 2, 3)
 */
void printList(FILE* out, List L);

#endif