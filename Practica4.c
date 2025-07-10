#include <stdio.h>
#include <stdlib.h>
#include "DQueue.h"
void createDQ(DQueue *dq);
void enqueueDQ(DQueue *dq, element el);
int is_EmptyDQ(DQueue dq);
int dequeueDQ(DQueue *dq);
void printDQ(DQueue *dq);
int copyDQ(DQueue *dq,DQueue *dq2);
void deleteDQ(DQueue *dq);

int main()
{
    int vacia;
    DQueue dque;
    createDQ(&dque);
    vacia= is_EmptyDQ(dque);
    printf("Esta vacia?: %d \n", vacia);
    enqueueDQ(&dque, 4);
    dequeueDQ(&dque);
    printDQ(&dque);
    enqueueDQ(&dque, 5);
    enqueueDQ(&dque, 6);
    printDQ(&dque);
    DQueue dque2;
    createDQ(&dque2);
    copyDQ(&dque,&dque2);
    printf("la original es:");
    printDQ(&dque);
    printf("la copia es:");
    printDQ(&dque2);
    dequeueDQ(&dque);
    printDQ(&dque);
    deleteDQ(&dque);
    return 0;
}