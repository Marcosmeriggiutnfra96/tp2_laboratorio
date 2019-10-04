#ifndef Empleado_H_INCLUDED
#define Empleado_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

typedef struct{

int id;
char nombre[51];
char apellido[51];
float sueldo;
int isEmpty;
int Sector;
}eEmpleado;

#include "sectore.h"
#endif // Empleado_h_INCLUDED
#include "entradas.h"

void iniciarlizarempleados(eEmpleado vec[], int tam);
void mostrarEmpleado(eSector sectores[], int tam, eEmpleado emp);
void mostrartodosEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamSector);
int  lugarLibre(eEmpleado vec[],int tam);
int buscarEmpleado(eEmpleado vec [], int tam, int id);
void altaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSector);
void modificarEmpleado(eEmpleado vec[], int tam, eSector sectores[],int tamSector);
void bajaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSector);
void ordenarEmpleados(eEmpleado vec[], int tam);
void informarSueldos(eEmpleado vec[],int tam);
void listarEmpleados(eEmpleado vec[], int tam, eSector sector[], int tamSector);
