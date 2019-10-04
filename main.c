#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "Empleados.h"
#define tam 100
#define tamSec 5

int main()
{
    int opcion;
    char auxOpcion[10];

    eEmpleado listaEmpleado[tam];
    iniciarlizarempleados(listaEmpleado,tam);
    eSector sectores[]=
     {
        {1,"sistemas"},
        {2,"RRHH"},
        {3,"compras"},
        {4,"ventas"},
        {5,"legales"},
    };

    do {


    printf("     ---     A B M Empleados     ----\n\n");

    printf("\nOPCION 1: ALTA \nOPCION 2: BAJA \nOPCION 3: MODIFICACION \nOPCION 4: LISTAR \nOPCION 5: SALIR \n");

    while(!getStringNumeros("\nESCOJA UNA OPCION \n",auxOpcion))
    {
    }
    opcion = atoi(auxOpcion);

    switch(opcion)
    {
    case 1:

         altaEmpleado(listaEmpleado, tam , sectores , tamSec);

         break;
    case 2:
        bajaEmpleado(listaEmpleado, tam , sectores, tamSec);

        break;
    case 3:
        modificarEmpleado(listaEmpleado, tam , sectores, tamSec);
        break;
    case 4:
        listarEmpleados(listaEmpleado,tam, sectores, tamSec);
        break;

    case 5:
        printf(" bye");
        break;

    default:
        printf("la opcion ingresada no existe\n");
        break;
    }

    system("pause");
    system("cls");

    }while(opcion != 5 );

    return 0;
}
