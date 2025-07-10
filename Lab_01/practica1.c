//2CV7 Yescas Carrillo Alejandro Gabriel	

	#include<stdio.h>
	#include<stdlib.h>
	#include<time.h>

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
    		printArray(array, size);
    		flag=0;
    		}
  		}
	}

	int main(int argc, char ** argv){
		/*if(argc!=2){
			printf("ha olvidado su nombre \n");
			exit (1);
		}
		printf("Hola %s \n",argv[1]);*/
		int i, n;
		n=atoi(argv[1]);
		int* arreglo;
		arreglo = (int*)calloc(n,sizeof(int));


		if(arreglo != NULL){
			srand (time(NULL));

			for(i=0; i<n ; i++){
				arreglo[i]=rand()%500001;
			}	
 		printArray(arreglo, n);
 		insertionSort(arreglo, n);
  		 printf("Sorted array in ascending order:\n");
  		printArray(arreglo, n);
  		free(arreglo);
  		}
  		else{
  			printf("Error, tamaño de arreglo invalido\n");
  		}
  		return 0;
	}
