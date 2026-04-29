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
    *temp = NULL; // set to null at the end for dangling pointer when done
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
}

/* ==================== Public ADT Functions ==================== */

void pq_init(PriorityQueue *pq, Comparator cmp) {
    // TODO:
    // 1. set size to 0
    // 2. set capacity to INITIAL_CAPACITY
    // 3. store cmp
    // 4. allocate pq->data using malloc
}

void pq_insert(PriorityQueue *pq, void *item) {
    // TODO:
    // 1. grow array if needed
    // 2. place new item at index size
    // 3. increment size
    // 4. restore heap property with heapify_up
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

    return NULL;
}

int pq_is_empty(PriorityQueue *pq) {
    // TODO: return 1 if size == 0, else return 0
    return 1;
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
}

void pq_destroy(PriorityQueue *pq) {
    // TODO:
    // 1. free the internal data array
    // 2. set data to NULL
    // 3. set size to 0
    // 4. set capacity to 0
    // 5. set cmp to NULL
}