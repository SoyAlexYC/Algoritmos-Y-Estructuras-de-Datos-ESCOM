#include "dstack2.h"
#include <stdlib.h>
#include <stdio.h>
typedef int element; 

void createDS(NodeDS **ds){
	*ds=NULL;
}

int isEmptyDS(NodeDS *ds){
	if(ds==NULL)
		return 1;
	else
		return 0;
}

void push(NodeDS **ds,element ele){
	NodeDS *new;
   new=(NodeDS*)malloc(sizeof(NodeDS));
	new->e=ele;
	new->next=*ds;
	*ds=new;
}

element pop (NodeDS **ds){
	NodeDS * nodeaux;
	element eaux;
	if (isEmptyDS(*ds)){
		printf("Underflow");
		eaux=-1;//←valor error
	}
	else{
		nodeaux = *ds;
		*ds = nodeaux -> next;
		eaux = nodeaux -> e;
		free(nodeaux);
	}
      return eaux;
}

void deleteDS(NodeDS **ds){
	while(!isEmptyDS(*ds)){
		printf("\nDel %i",pop(ds));
	}
}

void printDS(NodeDS *ds){
	NodeDS * dsaux;
	createDS(&dsaux);
	element ele;
    printf("imprimiendo lista\n");
	while(ds != NULL){
		ele=pop(&ds);
		push(&dsaux,ele);
		printf("%d\n", ele);
	}
	while(dsaux != NULL){
		ele=pop(&dsaux);
		push(&ds,ele);
	}
	
}

void deleteduplicatesDS(NodeDS **ds, element e){
	NodeDS * dsaux1;
	createDS(&dsaux1);
	element ele,cont;
    cont=0;
	while(*ds != NULL){
		if((*ds)->e == e) //O(n)
		{
			pop(ds);
            cont++;
		}
        else{
        ele=pop(ds);
		push(&dsaux1,ele);
        }
	}
	while(dsaux1 != NULL){
		ele=pop(&dsaux1);
		push(ds,ele);
	}
    if (cont==0)
    {
        printf("el elemento no ha sido encontrado\n");
    }
    
}

int main(){
	NodeDS *ds;
	createDS(&ds);
	push(&ds, 4);
	push(&ds, 5);
	push(&ds, 6);
    push(&ds, 6);
    push(&ds, 4);
    push(&ds, 7);
    push(&ds, 4);
	printDS(ds);
	deleteduplicatesDS(&ds, 4);
    printf("lista sin elemento dado: \n");
    printDS(ds);
    deleteduplicatesDS(&ds, 12);
    printf("lista sin elemento dado: \n");
	printDS(ds);
	deleteDS(&ds);
	return 0;
}
