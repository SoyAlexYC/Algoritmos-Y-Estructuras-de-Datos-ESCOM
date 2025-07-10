#include <stdio.h>
#include <stdlib.h>
#include "SList.h"

void createList(slist *f);
void insertAtFirst(slist *f, element ele);
void insertAtLast(slist *f, element ele);
int insertAfterE(slist *f, int n, element ele);
int deleteNodeEl(slist *f, element ele);
void deleteList(slist *f);
nodeL *searchEle(slist *f, element ele);
element deleteatFirst(slist *f);
int is_EmptySL(slist *f);
void printL(slist *f);
element deleteAtEnd2(slist *first);

int main()
{
    int vacia;
    slist lista;
    createList(&lista);
    vacia=is_EmptySL(&lista);
    printf("La lista esta vacia: %d\n",vacia);
    insertAtFirst(&lista,1);
    printL(&lista);
    insertAtLast(&lista,5);
    printL(&lista);
    insertAfterE(&lista,1,2);
    printL(&lista);
    insertAfterE(&lista,2,3);
    printL(&lista);
    insertAfterE(&lista,3,4);
    printL(&lista);
    searchEle(&lista,3);
    searchEle(&lista,7);
    deleteatFirst(&lista);
    printL(&lista);
    deleteNodeEl(&lista,4);
    printL(&lista);
    deleteAtEnd2(&lista);
    printL(&lista);
    deleteList(&lista);
    return 0;
}
