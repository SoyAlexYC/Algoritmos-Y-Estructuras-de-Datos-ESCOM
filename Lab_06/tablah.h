#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 17
 
typedef struct empleado{
    int clave;
    char nombre[100];
    int salario;
    char puesto[50];
    int esAlta;
} Empleado;

typedef struct tabla_hash{
    Empleado * emp_tabla[M];
    int nempleados;
} tablah;

void create(tablah *de);
int fh_modular(int clave);
int obtener_indice(int clave, tablah de);
void insertar(tablah *de, Empleado emp);
Empleado *buscar(int clave, tablah de);
Empleado eliminar(tablah *de, int clave);
void printTablah(tablah *de);
void vaciarTablah(tablah *de);

void create(tablah *de){
    int i;
    de->nempleados=0;
    for(i=0 ;i<M - 1; i++){
        de->emp_tabla[i]=NULL;
    }
}

int fh_modular(int clave){
    return clave%M;
}

int obtener_indice(int clave, tablah de){
    int p, i = 1;
    p = fh_modular(clave);
    while((de.emp_tabla[p] != NULL) && (clave != (de.emp_tabla[p]->clave))){
        p = p+(i*i);
        p%=M;
        i++;
    }
    return p;
}

void insertar(tablah *de, Empleado emp){
    int p;
    Empleado *ne;
    ne =(Empleado*)malloc(sizeof(Empleado));
    ne->clave= emp.clave;
    strcpy(ne->nombre, emp.nombre);
    strcpy(ne->puesto, emp.puesto);
    ne->salario=emp.salario;
    ne->esAlta=1;
    de->nempleados++;
    p = obtener_indice(ne->clave, *de);
    de->emp_tabla[p]=ne;
    printf("SE HIZO\n");
}

Empleado *buscar(int clave, tablah de){
    Empleado *aux;
    int p=obtener_indice(clave, de);
    if(de.emp_tabla[p] != NULL){
        if(de.emp_tabla[p]->esAlta == 1){
            aux=de.emp_tabla[p];
            printf("Empleado encontrado en la direccion: %p\n", aux);
        }
        else{
            printf("Empleado no encontrado\n");
            aux=NULL;
        }
    }
    else{
        printf("Empleado no encontrado\n");
        aux = NULL;
    }
    return aux;
}

Empleado eliminar(tablah *de, int clave){
    Empleado *e;
    Empleado emp;
    e = buscar(clave, *de);
    if(e!=NULL){
        e->esAlta=0;
        emp=*e;
        printf("Empleado dado de baja EXITOSAMENTE\n");
    }
    else{
        printf("No se encontro esa clave\n");
        emp.clave=-1;
    }
    return emp;
}

void printTablah(tablah *de)
{
    int i = 0;
    printf("#### DICCIONARIO DE EMPLEADOS ###\n");
    printf("Posicion \tClave \t\t Nombre\t\t Salario\t\t Puesto\t\t Alta o Baja\n");
    for(i = 0 ;i < (M - 1); i++){
        if(de->emp_tabla[i] != NULL)
        {
            printf("%d \t\t%d \t\t %s\t\t %d\t\t %s\t\t %d\n", i, de->emp_tabla[i]->clave, de->emp_tabla[i]->nombre, de->emp_tabla[i]->salario, de->emp_tabla[i]->puesto, de->emp_tabla[i]->esAlta);
        }
    }
    printf("\n");
}

void vaciarTablah(tablah *de)
{
    int i;
    for(i = 0; i < M-1; i++)
    {
        Empleado *aux;
        aux = de->emp_tabla[i];
        free(aux);
    }
    printf("Tabla eliminada\n");
}