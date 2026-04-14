#include <stdio.h>
#include "List.h"

int main() {
    List L = newList();

    append(L, 1);
    append(L, 2);
    append(L, 3);

    printList(stdout, L);
    printf("\n");

    moveFront(L);
    moveNext(L);
    insertBefore(L, 10);

    printList(stdout, L);
    printf("\n");

    deleteFront(L);
    printList(stdout, L);
    printf("\n");

    freeList(&L);
    return 0;
}