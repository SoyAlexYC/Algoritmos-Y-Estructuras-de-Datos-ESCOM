//2CV7 Yescas Carrillo Alejandro Gabriel	
//Practica 2: busqueda binaria
	#include<stdio.h>
	#include<stdlib.h>
	#include<time.h>

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
	
	void printArray(int array[], int size) {
  		for (int i = 0; i < size; i++) {
    		printf("%d ", array[i]);
  		}
  		printf("\n");
	}

	void insertionSort(int array[], int size) {
  		int flag=0; //bandera que nos indica si hubo un intercambio
  		for (int step = 1; step < size; step++) {
    		int key = array[step];
    		int j = step - 1;
    		while (key < array[j] && j >= 0) {
     			array[j + 1] = array[j];
      			j--;
      			flag=1;
    		}
    	
    		array[j + 1] = key;
    		if(flag==1){
    		//printArray(array, size);
    		flag=0;
    		}
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
 		int res = busquedabinaria(arreglo, target, 0, n - 1);
  		if (res == -1){
    		printf("No se encontro el numero solicitado");
  			}
		else{
    		printf("El elemento esta en el indice %d", res);
  			}
		  free(arreglo);
  		}
  		else{
  			printf("Error, tamaño de arreglo invalido\n");
  		}
  		return 0;
	}
