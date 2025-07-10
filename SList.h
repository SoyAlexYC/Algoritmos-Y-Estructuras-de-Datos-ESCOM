#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define ERROR -1

typedef int element;

typedef struct nodeL
{
    element e;
    struct nodeL *next;
} nodeL;

typedef nodeL *slist;

void createList(slist *f)
{
    *f = NULL;
}

void insertAtFirst(slist *f, element ele)
{
    nodeL *nuevo;
    nuevo = (nodeL *)malloc(sizeof(nodeL));
    nuevo->e = ele;
    nuevo->next = *f;
    *f = nuevo;
}

void insertAtLast(slist *f, element ele)
{
    if (*f == NULL)
    {
        insertAtFirst(f, ele);
    }
    else
    {
        nodeL *nuevo;
        nuevo = (nodeL *)malloc(sizeof(nodeL));
        nuevo->e = ele;
        nodeL *aux;
        aux = *f;
        while (aux->next != NULL)
        {
            aux = aux->next;
        }
        aux->next = nuevo;
        nuevo->next = NULL;
    }
}

int insertAfterE(slist *f, int n, element ele)
{
    int cont = 1;
    slist nuevo, aux;
    nuevo = (nodeL *)malloc(sizeof(nodeL));
    nuevo->e = ele;
    aux = *f;
    while (aux != NULL)
    {
        if (cont == n)
        {
            nuevo->next = aux->next;
            aux->next = nuevo;
            return 1;
        }
        cont++;
        aux = aux->next;
    }
    return 0;
}

int deleteNodeEl(slist *f, element ele)
{
    if (*f != NULL)
    {
        slist aux, auxbef;
        aux = *f;
        while ((aux != NULL) && (aux->e != ele))
        {
            auxbef = aux;
            aux = aux->next;
        }
        if (aux == NULL)
        {
            printf("elemento no existe\n");
        }
        else if (auxbef == NULL)
        {
            *f = (*f)->next;
            free(aux);
        }
        else
        {
            auxbef->next = aux->next;
        }
    }
}

void deleteList(slist *f)
{
    nodeL *aux;
    while (*f != NULL)
    {
        aux = *f;
        *f = (*f)->next;
        free(aux);
    }
    printf("lista eliminada");
}

nodeL *searchEle(slist *f, element ele)
{
    nodeL *aux;
    aux = *f;
    if (*f != NULL)
    {
        while (aux != NULL)
        {
            if (aux->e == ele)
            {
                printf("El elemento buscado es: %d\n", *aux);
                return aux;
            }
            aux = aux->next;
        }
        printf("elemento no encontrado\n");
        return NULL;
    }
    else
    {
        printf("La lista esta vacia \n");
    }
}

element deleteatFirst(slist *f)
{
    if (*f == NULL)
    {
        printf("La lista esta vacia \n");
    }
    else
    {
        nodeL *aux;
        element aux_ele;
        aux = *f;
        *f = (*f)->next;
        aux_ele = aux->e;
        free(aux);
        return aux_ele;
    }
}

int is_EmptySL(slist *f)
{
    if (*f == NULL)
    {
        printf("La lista esta vacia \n");
        return 1;
    }
    printf("La lista no esta vacia \n");
    return 0;
}

void printL(slist *f)
{
    slist aux;
    aux = *f;
    printf("Imprimiendo lista:\n");
    while (aux != NULL)
    {
        printf("%d \n", aux->e);
        aux = aux->next;
    }
}

element deleteAtEnd2(slist *first){
    if (*first != NULL)
    {
        slist aux, auxbef;
        aux = *first;
        while (aux->next != NULL)
        {
            auxbef = aux;
            aux = aux->next;
            
        }
        if (auxbef == NULL)
        {
            *first = (*first)->next;
            free(aux);
        }
        else
        {
            auxbef->next = aux->next;
        }
    }
}