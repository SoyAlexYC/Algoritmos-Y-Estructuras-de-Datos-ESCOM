#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <math.h>

void imprimirarreglo(int*, int);
void selectionsort(int*, int);

int main(int argc, char *argv[])
{
   int i, n;
   n = atoi(argv[1]);
   int* arreglo;
   arreglo = (int*)calloc(n, sizeof(int));

   if(arreglo != NULL)
   {
      FILE *f;

      f = fopen("numeros10millones.txt", "r");
      if(f == NULL)
      {
         printf("No se ha podido abrir el archivo\n");
         exit(1);
      }
   
      for(i = 0; i < n; i++)
      {
         fscanf(f, "%d", &arreglo[i]);
      }

      printf("El arreglo desordenado es: \n");
      //imprimirarreglo(arreglo, n);

      selectionsort(arreglo, n);

      printf("El arreglo ordenado es: \n");
      //imprimirarreglo(arreglo, n);

      rewind(f);
      fclose(f);
      free(arreglo);
   }
   else
   {
      printf("No se pudo generar la memoria dinamica\n");
   }

   return 0;
}

void imprimirarreglo(int* array, int size)
{
   int i;
   
   for(i = 0; i < size; i++)
   {
      printf(" %d ", array[i]);
   }
   printf("\n");
}

void selectionsort(int* A, int n)
{
   clock_t tiempo_inicio, tiempo_final;
   double segundos, milisegundos;
   int i, j, menor, x;

   tiempo_inicio = clock();
   for(i = 0; i <= n-2; i++)
   {
      menor = i;
      for(j = i + 1; j <= n-1; j++)
      {
         if(A[j]<A[menor])
         {
            menor = j;
         }
      }
      if( i!= menor)
      {
         x = A[i];
         A[i] = A[menor];
         A[menor] = x;
      }
   }
   tiempo_final = clock();
   
   segundos = (double)(tiempo_final - tiempo_inicio) / CLOCKS_PER_SEC;
   milisegundos = segundos * 1000;
   printf("El tiempo que se tardo en ejecutar selectionsort en segundos es: %2.3f\n", segundos);
   printf("El tiempo que se tardo en ejecutar selectionsort en milisegundos es: %f\n", milisegundos);
}
