#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

/*
 * hw2.c
 *
 * Simple client program for testing the Priority Queue ADT.
 *
 * You should use this file to verify correctness of your implementation.
 * You are encouraged to add more tests, especially edge cases.
 */

/*
 * compare_ints(a, b)
 *
 * Comparator for integer data in a min-heap.
 *
 * Returns:
 *   < 0 when *a < *b   -> a has higher priority
 *   = 0 when *a == *b
 *   > 0 when *a > *b   -> b has higher priority
 */
int compare_ints(void *a, void *b) {
    int x = *(int *)a;
    int y = *(int *)b;
    return x - y;
}

int main(void) {
    PriorityQueue pq;
    pq_init(&pq, compare_ints);

    /* Allocate some integer items dynamically for testing. */
    int *a = malloc(sizeof(int));
    int *b = malloc(sizeof(int));
    int *c = malloc(sizeof(int));
    int *d = malloc(sizeof(int));
    int *e = malloc(sizeof(int));

    if (a == NULL || b == NULL || c == NULL || d == NULL || e == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        free(a); free(b); free(c); free(d); free(e);
        return 1;
    }

    *a = 10;
    *b = 30;
    *c = 20;
    *d = 50;
    *e = 60;

    /* Insert items and print heap state. */
    pq_insert(&pq, a);
    pq_insert(&pq, b);
    pq_insert(&pq, c);
    pq_insert(&pq, d);
    pq_insert(&pq, e);

    printf("Initial queue:\n");
    print_queue(&pq);

    printf("\nDeleting items in priority order:\n");
    while (!pq_is_empty(&pq)) {
        int *val = (int *)pq_delete(&pq);
        if (val != NULL) {
            printf("Deleted: %d\n", *val);
            free(val);
        }
        print_queue(&pq);
    }

    pq_destroy(&pq);
    return 0;
}