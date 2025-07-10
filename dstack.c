#include "dstack.h"
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

void replaceDS(NodeDS **ds, element nuevo, element viejo){
	NodeDS * dsaux;
	createDS(&dsaux);
	element ele;
	while(*ds != NULL){ 
		if((*ds)->e == viejo) //O(n)
		{
			(*ds)->e = nuevo;
		}
		ele=pop(ds);
		push(&dsaux,ele);
	}

	while(dsaux != NULL){
		ele=pop(&dsaux);
		push(ds,ele);
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
	replaceDS(&ds, 8, 4);
	printf("imprimiendo lista con elemento reemplazado\n");
	printDS(ds);
	deleteDS(&ds);
	return 0;
}