#ifndef Sectores_H_INCLUDED
#define Sectores_H_INCLUDED

typedef struct
{
    int id;
    char desc[20];
} eSector;

#include "Empleados.h"
#endif // Sectores_H_INCLUDED

int obtenerSector(eSector sectores[], int tam, int id, char desc[]);
/*
void mostrarSectoresConEmpleados(eEmpleado empleados[], int tam, eSector sectores[], int tamSec);
void mostrarCantEmpleadosXSector(eEmpleado empleados[], int tam, eSector sectores[], int tamSec);
*/
