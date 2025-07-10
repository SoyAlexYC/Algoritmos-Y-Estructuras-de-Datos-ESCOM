#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;

typedef struct nodeT
{
    element e;
    char nombre[50];
    struct nodeT *l;
    struct nodeT *r;
} nodeT;

typedef nodeT *Tree;

void insert(Tree *r, Tree le, Tree ri, element ele, char *n);
void inOrder(Tree r);
void preOrder(Tree r);
void postOrder(Tree r);
Tree create_node(int key, char n[]);
void createT(Tree *r);
void insert_node(Tree *r, int key, char n[]);
void removeT(Tree *r);
Tree search(Tree r, int key);
void buscarporkey(Tree r, int key);

void insert(Tree *r, Tree le, Tree ri, element ele, char *n)
{
    Tree new = (Tree)malloc(sizeof(nodeT));
    new->e = ele;
    strcpy(new->nombre, n);
    new->l = le;
    new->r = ri;
    *r = new;
}

void inOrder(Tree r)
{
    if (r != NULL)
    {
        inOrder(r->l);
        printf("Clave: %d\n", r->e);
        printf("Escuela: %s \n", r->nombre);
        inOrder(r->r);
    }
}

void preOrder(Tree r)
{
    if (r != NULL)
    {
        printf("Clave: %d\n", r->e);
        printf("Escuela: %s \n", r->nombre);
        preOrder(r->l);
        preOrder(r->r);
    }
}

void postOrder(Tree r)
{
    if (r != NULL)
    {
        postOrder(r->l);
        postOrder(r->r);
        printf("Clave: %d\n", r->e);
        printf("Escuela: %s \n", r->nombre);
    }
}

Tree create_node(int key, char n[])
{
    Tree new = (Tree)malloc(sizeof(nodeT));
    new->e = key;
    strcpy(new->nombre, n);
    new->l = new->r = NULL;
    return new;
}

void createT(Tree *r)
{
    *r = NULL;
}

void insert_node(Tree *r, int key, char n[])
{
    if (*r == NULL)
    {
        Tree nuevo = create_node(key, n);
        *r = nuevo;
    }
    else if (key < (*r)->e)
    {
        insert_node(&(*r)->l, key, n);
    }
    else
    {
        insert_node(&(*r)->r, key, n);
    }
}

void removeT(Tree *r)
{
    if (*r != NULL)
    {
        removeT(&(*r)->l);
        removeT(&(*r)->r);
        free(*r);
    }
}

Tree search(Tree r, int key)
{
    if (r == NULL)
    {
        return r;
    }
    else if (r->e == key)
    {
        return r;
    }
    else if (key < r->e)
    {
        search(r->l, key);
    }
    else
    {
        search(r->r, key);
    }
}

void buscarporkey(Tree r, int key)
{
    Tree b;
    createT(&b);
    b = search(r, key);
    if (b != NULL)
    {
        printf("\nEl nodo buscado tiene clave: %d", b->e);
        printf("\nEl nodo buscado es la escuela: %s", b->nombre);
    }
    else{
        printf("\nNodo %d no encontrado", key);
    }
}