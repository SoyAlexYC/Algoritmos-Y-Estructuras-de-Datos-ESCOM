#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tablah.h"

Empleado altaEmpleado(char nombre[], char puesto[], int calve, int salario);

int main()
{
    tablah diccionario_empleados;
    create(&diccionario_empleados);
    insertar(&diccionario_empleados, altaEmpleado("Alejandro", "Jefatura", 4371, 1000));
    insertar(&diccionario_empleados, altaEmpleado("Gabriel", "Administracion", 1324, 600));
    insertar(&diccionario_empleados, altaEmpleado("Fabricio", "Jefatura", 6173, 1000));
    insertar(&diccionario_empleados, altaEmpleado("Juan", "Administracion", 4199, 500));
    insertar(&diccionario_empleados, altaEmpleado("Manuel", "Humanidades", 4344, 200));
    insertar(&diccionario_empleados, altaEmpleado("Diego", "Humanidades", 1990, 100)); //6 NECESARIOS
    insertar(&diccionario_empleados, altaEmpleado("Sergio", "Transporte", 3457, 100));
    insertar(&diccionario_empleados, altaEmpleado("Max", "Transporte", 3458, 100));
    insertar(&diccionario_empleados, altaEmpleado("Hector", "Administracion", 3460, 500));
    insertar(&diccionario_empleados, altaEmpleado("Ivan", "Ingenieria", 3562, 800));
    insertar(&diccionario_empleados, altaEmpleado("Mariana", "Ingenieria", 3565, 800));
    insertar(&diccionario_empleados, altaEmpleado("Irma", "Transporte", 3464, 100));
    insertar(&diccionario_empleados, altaEmpleado("Vanessa", "Jeftura", 3478, 1000));
    insertar(&diccionario_empleados, altaEmpleado("Sofia", "Administracion", 3689, 500));
    insertar(&diccionario_empleados, altaEmpleado("Diana", "Humanidades", 3791, 200));

    printTablah(&diccionario_empleados);

    eliminar(&diccionario_empleados, 4344);
    eliminar(&diccionario_empleados, 1990);

    printTablah(&diccionario_empleados);
    buscar(4371, diccionario_empleados);
    buscar(1990, diccionario_empleados);
    buscar(4199, diccionario_empleados);

    vaciartablah(&diccionario_empleados);
}

Empleado altaEmpleado(char nombre[], char puesto[], int clave, int salario)
{
    Empleado emp;
    emp.clave= clave;
    emp.salario= salario;
    strcpy(emp.nombre, nombre);
    strcpy(emp.puesto, puesto);
    return emp;
}