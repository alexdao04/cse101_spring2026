#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

/*
 * priority_queue.h
 * 
 * Interface for a generic Priority Queue ADT implemented using
 * an array-based binary min-heap.
 *
 * Do not modify this file.
 */

/*
 * Comparator function type.
 *
 * Should return:
 *   < 0 if first argument has HIGHER priority than second
 *   = 0 if they are equal in priority
 *   > 0 if first argument has LOWER priority than second
 *
 * Example for integers in a min-heap:
 *   return (*(int*)a - *(int*)b);
 *
 * In that case, smaller integer value = higher priority.
 */
typedef int (*Comparator)(void *, void *);

/*
 * PriorityQueue
 *
 * data     : dynamically allocated array of pointers to items
 * capacity : total number of slots currently allocated
 * size     : number of items currently stored
 * cmp      : comparator function used to determine priority
 */
typedef struct {
    void **data;
    int capacity;
    int size;
    Comparator cmp;
} PriorityQueue;

/*
 * pq_init()
 *
 * Initializes the priority queue.
 *
 * Responsibilities:
 * - set initial size to 0
 * - set an initial capacity
 * - allocate the data array
 * - store the provided comparator
 *
 * Precondition:
 * - pq is not NULL
 * - cmp is not NULL
 */
void pq_init(PriorityQueue *pq, Comparator cmp);

/*
 * pq_insert()
 *
 * Inserts a new item into the priority queue while preserving
 * the heap property.
 *
 * Typical strategy:
 * - place new item at the end of the array
 * - restore heap order using heapify-up
 *
 * Precondition:
 * - pq is not NULL
 * - pq has been initialized
 * - item is not NULL
 */
void pq_insert(PriorityQueue *pq, void *item);

/*
 * pq_delete()
 *
 * Removes and returns the item with the highest priority.
 * In a min-heap, this is the root element at index 0.
 *
 * Typical strategy:
 * - save the root item
 * - move the last item into the root position
 * - reduce size
 * - restore heap order using heapify-down
 *
 * Returns:
 * - pointer to removed item if queue is non-empty
 * - NULL if queue is empty
 *
 * Precondition:
 * - pq is not NULL
 * - pq has been initialized
 */
void *pq_delete(PriorityQueue *pq);

/*
 * pq_is_empty()
 *
 * Returns:
 * - 1 if the queue contains no elements
 * - 0 otherwise
 *
 * Precondition:
 * - pq is not NULL
 */
int pq_is_empty(PriorityQueue *pq);

/*
 * print_queue()
 *
 * Prints the current contents of the priority queue in array order
 * (which corresponds to level-order for the heap).
 *
 * This function is intended for testing/debugging.
 *
 * Note:
 * - For this homework, the provided test client uses integer data.
 * - You may assume items are int* when printing in the provided client.
 *
 * Precondition:
 * - pq is not NULL
 */
void print_queue(PriorityQueue *pq);

/*
 * pq_destroy()
 *
 * Frees all memory owned by the priority queue itself.
 *
 * Important:
 * - This should free the internal array allocated by pq_init().
 * - It should NOT automatically free the user data items unless the
 *   assignment explicitly says the queue owns those items.
 *
 * After destroy, the queue should be left in a safe empty state.
 *
 * Precondition:
 * - pq is not NULL
 */
void pq_destroy(PriorityQueue *pq);

#endif