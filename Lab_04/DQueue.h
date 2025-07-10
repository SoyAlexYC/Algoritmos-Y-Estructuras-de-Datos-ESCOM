#include <stdio.h>
#include <stdlib.h>
#define TRUE 1;
#define FALSE 0;

typedef int element;

typedef struct nodeQ
{
    element e;
    struct nodeQ *next;
} nodeq;

typedef struct DQueue
{
    nodeq *tail;
    nodeq *head;
} DQueue;

void createDQ(DQueue *dq)
{
    dq->head = NULL;
    dq->tail = NULL;
}

int is_EmptyDQ(DQueue dq)
{
    if (dq.head == NULL)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
void enqueueDQ(DQueue *dq, element el)
{
    nodeq *nuevo;
    nuevo = (nodeq *)malloc(sizeof(nodeq));
    nuevo->e = el;
    nuevo->next = NULL;
    if (is_EmptyDQ(*dq))
    {
        dq->head = nuevo;
    }
    else
    {
        dq->tail->next = nuevo;
    }
    dq->tail = nuevo;
}
int dequeueDQ(DQueue *dq)
{
    if (is_EmptyDQ(*dq))
    {
        printf("Error de underflow\n");
    }
    else
    {
        nodeq *aux = dq->head;
        element e = aux->e;
        if (dq->head == dq->tail)
        {
            dq->tail=NULL;
        }
        dq->head = dq->head->next;
        free(aux);
        return e;
    }
}
void printDQ(DQueue *dq)
{
    element e, vacia;
    DQueue qaux;
    createDQ(&qaux);
    while (!is_EmptyDQ(*dq))
    {
        e = dequeueDQ(dq);
        enqueueDQ(&qaux, e);
        printf("%d \n", e);
    }

    while (!is_EmptyDQ(qaux))
    {
        e = dequeueDQ(&qaux);
        enqueueDQ(dq, e);
    }
}

int copyDQ(DQueue *dq,DQueue *dq2)
{
    element e;
    DQueue qaux;
    createDQ(&qaux);
    if(is_EmptyDQ(*dq)){
        printf("Cola vacia\n");
        return FALSE;
    }
    else{
        while(!is_EmptyDQ(*dq)){
            e=dequeueDQ(dq);
            enqueueDQ(&qaux,e);
            enqueueDQ(dq2,e);
        }
        while(!is_EmptyDQ(qaux)){
            e=dequeueDQ(&qaux);
            enqueueDQ(dq,e);
        }
    }
}

void deleteDQ(DQueue *dq)
{
    element e;
    while (!is_EmptyDQ(*dq))
    {
        e = dequeueDQ(dq);
        printf("elemento eliminado %d \n", e);
    }
}
