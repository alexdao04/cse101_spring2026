#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

/*
 * priority_queue.c
 *
 * Partial implementation of a generic Priority Queue ADT using
 * an array-based binary min-heap.
 *
 * You must implement all required functions.
 *
 * You may add private helper functions in this file if needed.
 * Do not change the public function signatures from priority_queue.h.
 */

#define INITIAL_CAPACITY 16

/* ==================== Private Helper Functions ==================== */

/*
 * parent(i)
 *
 * Returns the index of the parent of node i in a 0-based heap array.
 *
 * Example:
 *   i = 1 -> parent = 0
 *   i = 2 -> parent = 0
 *   i = 5 -> parent = 2
 *
 * Precondition:
 * - i > 0
 */
static int parent(int i) {
    // TODO: return the parent index of i
    // parent of index i = (i-1) / 2
    return (i - 1) / 2;
}

/*
 * left(i)
 *
 * Returns the index of the left child of node i in a 0-based heap array.
 */
static int left(int i) {
    // TODO: return the left child index of i
    // left child of index i = (2*i)+1
    return (2 * i) + 1;
}

/*
 * right(i)
 *
 * Returns the index of the right child of node i in a 0-based heap array.
 */
static int right(int i) {
    // TODO: return the right child index of i
    // right child of index i = (2*i)+2
    return (2 * i) + 2;
}

/*
 * swap(a, b)
 *
 * Swaps two pointers stored in the heap array.
 */
static void swap(void **a, void **b) {
    // TODO: swap the pointer values stored at a and b
    // we make a temp variable to hold values when we swap
    void *temp = *a; // temp holds value of A (void pointer)
    *a = *b; // B now holds the value of A
    *b = temp; // B now holds the value of temp which was A
    // and that should be done!
    temp = NULL; // set to null at the end for dangling pointer when done
}

/*
 * resize_if_needed(pq)
 *
 * If the array is full, grow the underlying array before inserting
 * a new item.
 *
 * Required behavior:
 * - if size == capacity, allocate a new array with capacity * 2
 * - use realloc()
 * - update pq->data and pq->capacity
 *
 * If the array is not full, do nothing.
 */
static void resize_if_needed(PriorityQueue *pq) {
    // TODO: if pq->size == pq->capacity, double the capacity using realloc()
    pq->capacity *= 2; // double capacity
    if(pq->size == pq->capacity) {
        pq->data = realloc(pq->data, pq->capacity * sizeof(void*)); // use a temp variable to hold the new array
        // we use a double pointer to point to the void pointer a layer below since the array is storing those 
        // (we have no values in the queue yet)

    }
}

/*
 * heapify_up(pq, idx)
 *
 * Restores the heap property by repeatedly comparing a node with its parent
 * and swapping upward while the node has higher priority.
 *
 * Used after insertion.
 */
static void heapify_up(PriorityQueue *pq, int idx) {
    // TODO:
    // While idx is not the root and data[idx] has higher priority than parent,
    // swap them and continue moving upward.
    // start with an empty base case
    if(pq->cmp(pq->data[idx], pq->data[parent(idx)]) < 0) { // use comparator to compare node to whats above it
        // earlier we were comparing the values manually but we're supposed to use cmp instead
        swap(&pq->data[idx], &pq->data[parent(idx)]); // swap the node below with the parent node above depending on its priority
        // we're starting at the bottom so each node will only have one parent node above it
        // thats why in heapify down we compare the left and right children, but in heapify up we just compare the current node to its parent above it
        heapify_up(pq, parent(idx)); // call the function again with the parent index and the node next up the tree
    } else {
        return; // this is self explanatory
        // we stop when the node is the root or when parent priority > node 
        // (meaning the node should be in the right place and the root at highest priority)
    }
}

/*
 * heapify_down(pq, idx)
 *
 * Restores the heap property by repeatedly comparing a node with its children
 * and swapping downward with the higher-priority child.
 *
 * Used after deletion.
 */
static void heapify_down(PriorityQueue *pq, int idx) {
    // TODO:
    // Repeatedly:
    // 1. find left/right child indices
    // 2. determine which child has higher priority
    // 3. if a child should come before the current node, swap and continue
    // 4. otherwise stop
    if(pq->cmp(pq->data[left(idx)], pq->data[right(idx)]) < 0) { // compare left to right off the jump
        if(pq->cmp(pq->data[left(idx)], pq->data[idx]) < 0) { // compare left to current node above children
            swap(&pq->data[left(idx)], &pq->data[idx]); // swap the left child with current node if left priority > current node
            heapify_down(pq, left(idx)); // call function again similar to what we did in heapify up
            // only difference is we're moving DOWN not up
        } else {
            return; // exit condition similar to heapify up
        }
    }
}

/* ==================== Public ADT Functions ==================== */

void pq_init(PriorityQueue *pq, Comparator cmp) {
    // TODO:
    // 1. set size to 0
    // 2. set capacity to INITIAL_CAPACITY
    // 3. store cmp
    // 4. allocate pq->data using malloc
    pq->size = 0; // set size to 0 (step 1)
    pq->capacity = INITIAL_CAPACITY; // set capacity to initial capacity (step 2)
    pq->cmp = cmp; // store pq contents in cmp variable
    pq->data = malloc(INITIAL_CAPACITY * sizeof(void*)); // void pointer array of size times initial capacity
}

void pq_insert(PriorityQueue *pq, void *item) {
    // TODO:
    // 1. grow array if needed
    // 2. place new item at index size
    // 3. increment size
    // 4. restore heap property with heapify_up
    resize_if_needed(pq);
    pq->data[pq->size] = item; // data inside the queue at pq's index size = new item
    pq->size++; // increment size when we add an item to the queue
    heapify_up(pq, pq->size - 1); // set bounds for heapify up between 0 and size - 1 
    // (we added an item to the end of the queue, size would be out of bounds/NULL whereas size - 1 is the last element)
}

void *pq_delete(PriorityQueue *pq) {
    // TODO:
    // If queue is empty, return NULL.
    //
    // Otherwise:
    // 1. save root item
    // 2. move last item to root
    // 3. decrement size
    // 4. restore heap property with heapify_down (if needed)
    // 5. return removed root item
    if(pq->size == 0) { // if the queue is empty, return NULL (base case)
        return NULL;
    } else { // we gotta move the last item to the root, decrement size, and then heapify down to restore the heap after deleting
        void *temp = pq->data[0]; // save the root item in a temp variable for the moment
        pq->data[0] = pq->data[pq->size - 1]; // last item to root (pq -> size - 1, refer to heapify functions)
        pq->size--; // decrement size
        heapify_down(pq, 0); // restore heap property with heapify down from root 0
        return temp; // return the temp variable which was the originally removed root item
    }
}

int pq_is_empty(PriorityQueue *pq) {
    // TODO: return 1 if size == 0, else return 0
    if(pq->size == 0) {
        return 1;
    } else {
        return 0;
    }
}

void print_queue(PriorityQueue *pq) {
    /*
     * For the provided homework client, items are integers stored as int*.
     *
     * Print the heap array from index 0 to size-1 in one line.
     * Example style:
     *   [10 20 30]
     *
     * If empty, print:
     *   []
     */
    // TODO
    if(pq->size == 0) { // if the size is 0 we print empty brackets
        printf("[]\n");
    } else { // if the size is not 0 we print the items in the queue plus brackets
        printf("[");
        for(int i = 0; i < pq->size; i++) {
            void *item = pq->data[i];
            int *int_item = (int*) item; // void pointer to int pointer conversion
            printf("%d ", *int_item);
        }
        printf("]\n");
    }
}

void pq_destroy(PriorityQueue *pq) {
    // TODO:
    // 1. free the internal data array
    // 2. set data to NULL
    // 3. set size to 0
    // 4. set capacity to 0
    // 5. set cmp to NULL
    free(pq->data);
    pq->data = NULL;
    pq->size = 0;
    pq->capacity = 0;
    pq->cmp = NULL;
}