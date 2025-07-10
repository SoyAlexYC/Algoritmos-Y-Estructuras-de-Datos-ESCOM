#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main()
{
    Tree a;
    createT(&a);
    insert_node(&a, 605, "ESCA");
    insert_node(&a, 789, "ESIME TICOMAN");
    insert_node(&a, 611, "ESCOM");
    insert_node(&a, 101, "EST");
    insert_node(&a, 500, "ESIQIE");
    insert_node(&a, 211, "ESE");
    printf("imprimiendo arbol in-order\n");
    inOrder(a);
    printf("imprimiendo arbol pre-order\n");
    preOrder(a);
    printf("imprimiendo arbol post-order\n");
    postOrder(a);
    buscarporkey(a, 611);
    buscarporkey(a, 230);
    buscarporkey(a, 211);
    removeT(&a);
    return 0;
}