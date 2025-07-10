#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <math.h>

void imprimirarreglo(int*, int);
void mergesort(int*, int, int);
void merge(int*, int, int, int);

int main(int argc, char *argv[])
{
   clock_t tiempo_inicio, tiempo_final;
   double segundos, milisegundos;
   int i, n, ini, fin;

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

      ini = 0;
      fin = n - 1;

      tiempo_inicio = clock();
      mergesort(arreglo, ini, fin);
      tiempo_final = clock();
   
      segundos = (double)(tiempo_final - tiempo_inicio) / CLOCKS_PER_SEC;
      milisegundos = segundos * 1000;
      printf("El tiempo que se tardo en ejecutar mergesort en segundos es: %2.3f\n", segundos);
      printf("El tiempo que se tardo en ejecutar mergesort en milisegundos es: %f\n", milisegundos);

      printf("El arreglo ordenado es: \n");
      //imprimirarreglo(arreglo, n);

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

void mergesort(int* A, int ini, int fin)
{
   int mit;

   if(ini < fin)
   {
      mit = (ini+fin)/2;
      mergesort(A, ini, mit);
      mergesort(A, (mit + 1), fin);
      merge(A, ini, mit, fin);
   }
}

void merge(int* A, int ini, int mit, int fin)
{
   int tizq, tder, j, k, i;

   tizq = mit - ini + 1;
   tder = fin - mit;

   int* I;
   int* D;
   I = (int*)calloc(tizq + 1, sizeof(int));
   D = (int*)calloc(tder + 1, sizeof(int));

   /*if(I == NULL || D == NULL)
   {
      printf("No se pudo generar el arreglo dinamico I o D u ambos");
      exit(1);
   }*/

   for(j = 0; j <= tizq - 1; j++)
   {
      I[j] = A[ini + j];
   }
   for(j = 0; j<= tder - 1; j++)
   {
      D[j] = A[mit + j + 1];
   }
   I[tizq] = 2147483645;
   D[tder] = 2147483645;
   i = 0;
   j = 0;
   for(k = ini; k <= fin; k++)
   {
      if(I[i] <= D[j])
      {
         A[k] = I[i];
         i++;
      }
      else
      {
         A[k] = D[j];
         j++;
      }
   }

   free(I);
   free(D);
}
