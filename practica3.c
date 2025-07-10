//2CV7 Yescas Carrillo Alejandro Gabriel	
//Practica 3: busqueda indexada
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct grupos{
	int indice;
	int elemento;
} grupos;	
	
int busquedabinaria(int arreglo[], int s, int ini, int fin) {
  // while para repetir hasta que ini>fin y por tanto no hayamos encontrado el numero 
  while (ini <= fin) {
    int mit = (ini + fin) / 2;

    if (s == arreglo[mit])
      return mit;

    else if (s < arreglo[mit])
      fin = mit - 1;

    else
      ini = mit + 1;
  }
  return -1;
}

int indexsearch(int A[], int n, int x){
    int G = 7; //numero de grupos
    int GN=n/G;
    grupos tabla[G];
    int ini, fin;
    int j = 0;
    int i= 0;
    int set= 0;
    
    while(i<n){
    	tabla[j].indice=i;
    	tabla[j].elemento=A[i];
    	i+=GN;
    	j++;
    }
    if(x<tabla[0].elemento){
    	return -1;
    }
    else{
    	for (i = 1; i < G; i++){
            if (x < tabla[i].elemento){
                set=1;
                ini = tabla[i-1].indice;
                fin = tabla[i].indice-1;
                break;
                }
            }
        if (set == 0) {
        ini = tabla[G - 1].indice;
        fin = n-1;        
    	}
    	printf("La segunda busqueda se hara en el grupo %d \n",i);
    }	
    return busquedabinaria(A,x,ini,fin);
}
	
void printArray(int array[], int size) {
  		for (int i = 0; i < size; i++) {
    		printf("%d ", array[i]);
  		}
  		printf("\n");
}

void insertionSort(int array[], int size) {
  		for (int step = 1; step < size; step++) {
    		int key = array[step];
    		int j = step - 1;
    		while (key < array[j] && j >= 0) {
     			array[j + 1] = array[j];
      			j--;
  		}
    	
    		array[j + 1] = key;
  		}
}

int main(int argc, char ** argv){
		int i, n, target;
		n=atoi(argv[1]);
		int* arreglo;
		arreglo = (int*)calloc(n,sizeof(int));


		if(arreglo != NULL){
			srand (time(NULL));
			for(i=0; i<n ; i++){
				arreglo[i]=(rand() % (5001)) + 10000;
			}	
		
 		insertionSort(arreglo, n);
		printArray(arreglo, n);	
 		printf("ingrese el numero a buscar:\n");
 		scanf("%d",&target);
 		int res = indexsearch(arreglo, n, target);
  		if (res == -1){
    		printf("No se encontro el numero solicitado");
  			}
		else{
    		printf("El elemento esta en el indice %d \n", res);
  			}
		  free(arreglo);
  		}
  		else{
  			printf("Error, tamaño de arreglo invalido\n");
  		}
  		return 0;
}

