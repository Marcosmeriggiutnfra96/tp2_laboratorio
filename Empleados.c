
#include "Empleados.h"
#include "entradas.h"

/** \brief iguala cada posicion de manera que este libre (0) para poder ubicar un empleado en esa posicion
 *
 * \param vec[] eEmpleado
 * \param tam int tamanio del vector
 * \return void
 *
 */


void iniciarlizarempleados(eEmpleado vec[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {

        vec[i].isEmpty=0;

    }
}

/** \brief muestra los datos del empleado
 *
 * \param sectores[] eSector lista de sectores
 * \param tam int tamaño
 * \param emp eEmpleado lista de empleados
 * \return void
 *
 */

void mostrarEmpleado(eSector sectores[], int tam, eEmpleado emp)
{
    char nombreSector[20];
    char consigoNombre;

    consigoNombre = obtenerSector(sectores,tam, emp.Sector, nombreSector);
    if(!consigoNombre)
    {
        strcpy(nombreSector,"Sin Definir");
    }
    printf("\n%d    %10s      %10s     %10.2f   %10s\n ",emp.id, emp.nombre, emp.apellido, emp.sueldo,nombreSector);
}
/** \brief busca un lugar donde esté ubicado un empleado y lo muestra
 *
 * \param vec[] eEmpleado lista de empleados
 * \param tam int tamaño
 * \param sectores[] eSector lista de sectores
 * \param tamSector int tamaño del sector
 * \return void
 *
 */

void mostrartodosEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamSector)
{
    int i;
    int contador = 0;

    printf("\nLegajo     Nombre       Apellido          Sueldo       Sector  \n\n");
    for(i = 0; i < tam; i++)
    {
        if(vec[i].isEmpty == 1)
        {
            mostrarEmpleado(sectores, tamSector, vec[i]);
            contador++;
        }
    }
    if(contador == 0)
    {
        printf("\n no hay empleados para mostrar \n");
    }
}

/** \brief busca un lugar libre en los indices
 *
 * \param vec[] eEmpleado lista de empleados
 * \param tam int tamaño de la lista
 * \return int devuelve el indice libre
 *
 */
int lugarLibre(eEmpleado vec[], int tam)
{
    int i;
    int indice = -1;

    for (i = 0; i < tam; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/** \brief busca un empleado por si nse necesita para verificar en otra funcion, como modificacion, que no este ingresado previamente
 *
 * \param [] eEmpleado vec lista de empleados
 * \param tam int tamaaño de la lista
 * \param id int valor de id que luego será asignado al id de la estructura empleado
 * \return int devuelve la posicion donde el empleado está ubicado
 *
 */
int buscarEmpleado(eEmpleado vec [], int tam, int id)
{
    int i;
    int indice = -1;

    for(i = 0; i < tam; i++)
    {
        if((vec[i].isEmpty == 1)&&(vec[i].id == id))
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/** \brief se hace un alta del empleado y se piden sus datos para guardarlo
 *
 * \param vec[] eEmpleado lista de empleados
 * \param tam int tamaño de la lista
 * \param sectores[] eSector lista de sectores
 * \param tamSector int tamaño de la lista de sectores
 * \return void
 *
 */
void altaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSector)
{
    int indice;
    int id;
    char auxNombre[50];
    char auxApellido[50];
    char auxSector[50];
    char auxSueldo[50];

    indice = lugarLibre(vec, tam);

    if(indice == -1)
    {
        printf("\n no hay lugar disponible en el sistema\n");
    }
    else
    {
        id = indice + 1;

        vec[indice].id = id;

        while(!getStringLetras("ingrese el nombre: \n", auxNombre))
        {
            printf("intente de nuevo...\n");
        }
        strcpy(vec[indice].nombre, auxNombre);

        while(!getStringLetras("ingrese el apellido: \n", auxApellido))
        {
            printf("intente de nuevo...\n");
        }
        strcpy(vec[indice].apellido, auxApellido);

        while(!getStringNumeros("ingrese el sueldo: \n", auxSueldo))
        {
            printf("intente de nuevo...\n");
        }

        vec[indice].sueldo = atoi(auxSueldo);
        while(!getStringNumeros("ingrese el sector: \n( 1,sistemas \n 2,RRHH \n 3,compras \n 4,ventas \n 5,legales) \n", auxSector))
        {
            printf("intente de nuevo...\n ");
        }

        vec[indice].Sector = atoi(auxSector);

        vec[indice].isEmpty = 1;

        printf("Alta del empleado exitosa!!!\n\n");
    }
}

/** \brief en caso de error o cambio, se ejecuta una modificacion donde se acceden a los datos del empleado
 *
 * \param vec[] eEmpleado lista de empleados
 * \param tam int tamaño de la lista
 * \param sectores[] eSector lista de sectores
 * \param tamSector int tamaño de la lista de sectores
 * \return void
 *
 */
void modificarEmpleado(eEmpleado vec[], int tam, eSector sectores[],int tamSector)
{
    int esta;
    int id;
    int opcion;
    char seguir = 's';
    char confirmar;
    char auxOpcion[50];
    char auxId[50];
    char auxNombre[50];
    char auxApellido[50];
    char auxSector[50];
    char auxSueldo[50];

    while(!getStringNumeros("ingrese el legajo del empleado a modificar: \n", auxId))
    {
        printf("intente de nuevo...\n");
    }
    id = atoi(auxId);
    esta = buscarEmpleado(vec, tam, id);

    if(esta != -1)
    {


        do
        {
            system("cls");
            printf("            ::M O D I F I C A C I O N::          \n");
            printf("  1_ Modificar  Nombre       2_Modificar Sueldo  \n");
            printf("  3_ Modificar Apellido      4_ Modificar sector \n");
            printf("  5_ Salir....                                   \n");

            while(!getStringNumeros("ingrese una opcion: \n", auxOpcion))
            {
                printf("intente de nuevo...\n");
            }
            opcion = atoi(auxOpcion);

            switch(opcion)
            {

                case 1:
                    printf("\n usted ha seleccionado al empleado : \n");
                    mostrarEmpleado(sectores,tamSector,vec[esta]);

                    vec[esta].id = id;

                    while(!getStringLetras("ingrese el nombre: \n", auxNombre))
                    {
                        printf("intente de nuevo...\n");
                    }

                    strcpy(vec[esta].nombre, auxNombre);

                    printf("Modifiacion de empleado exitosa!!!\n\n");

                    vec[esta].isEmpty = 1;
                    system("pause");
                    break;

                case 2:
                    printf("\n usted ha seleccionado al empleado : \n");
                    mostrarEmpleado(sectores,tamSector,vec[esta]);

                    vec[esta].id = id;

                    while(!getStringNumeros("ingrese el sueldo: \n", auxSueldo))
                    {
                        printf("intente de nuevo...\n");
                    }
                    vec[esta].sueldo = atoi(auxSueldo);

                    printf("Modifiacion de empleado exitosa!!!\n\n");

                    vec[esta].isEmpty = 1;
                    system("pause");
                    break;

                case 3:
                    printf("\n usted ha seleccionado al empleado : \n");
                    mostrarEmpleado(sectores,tamSector,vec[esta]);

                    vec[esta].id = id;

                    while(!getStringLetras("ingrese el apellido: \n", auxApellido))
                    {
                        printf("intente de nuevo...\n");
                    }
                    strcpy(vec[esta].apellido, auxApellido);

                    printf("Modifiacion de empleado exitosa!!!\n\n");

                    vec[esta].isEmpty = 1;
                    system("pause");
                    break;

                case 4:
                    printf("\n usted ha seleccionado al empleado : \n");
                    mostrarEmpleado(sectores,tamSector,vec[esta]);

                    vec[esta].id = id;

                    while(!getStringNumeros("ingrese el sector: \n( 1,sistemas \n 2,RRHH \n 3,compras \n 4,ventas \n 5,legales) \n", auxSector))
                    {
                        printf("intente de nuevo...\n ");
                    }

                    vec[esta].Sector = atoi(auxSector);

                    printf("Modifiacion de empleado exitosa!!!\n\n");

                    vec[esta].isEmpty = 1;
                    system("pause");
                    break;

                case 5:
                    printf("\n confirmar salida s/n?...\n");
                    fflush(stdin);
                    confirmar = getche();

                    if( tolower(confirmar)== 's')
                    {
                        seguir = 'n';
                    }
                    break;

                default:
                    printf("\n Opcion invalida, intente de nuevo...");
                    system("pause");
                    system("break");

                }
            }
            while(seguir == 's');

        }
        else
        {
            printf("no hay ningun empleado ingresado con ese id...\n");
        }
}

void bajaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSector)
{
    int indice;
    int esta;
    int id;
    char confirmar;
    char auxId[50];

    indice = lugarLibre(vec, tam);

    if(indice == -1)
    {
        printf("\n no hay lugar disponible en el sistema\n");
    }
    else
    {
        while(!getStringNumeros("ingrese el id del empleado a dar de baja: \n", auxId))
        {
            printf("intente de nuevo...\n");

        }
        id = atoi(auxId);
        esta=buscarEmpleado(vec, tam, id);

        if(esta != -1)
        {
            printf("\n usted ha seleccionado al empleado : \n");
            mostrarEmpleado(sectores,tamSector,vec[esta]);

            printf("\n confirmar la baja? (s/n)...");
            fflush(stdin);
            confirmar = getche();

            if( tolower(confirmar == 's'))
            {
                vec[esta].id = id;

                vec[esta].isEmpty = 0;
                printf("\n Baja de empleado exitosa!!!\n\n");
            }
            else
            {
                printf("\n Baja de empleado cancelada \n\n");
            }
        }
        else
        {
            printf("no hay empleados ingresados con ese id...\n");
        }
    }
}

/** \brief se hace un orden por sectores y por apellido de los empleados
 *
 * \param vec[] eEmpleado lista de empleados
 * \param tam int tamaño de la lista
 * \return void
 *
 */
void ordenarEmpleados(eEmpleado vec[], int tam)
{
    int i;
    int j;
    eEmpleado aux;

    for(i = 0; i < tam-1; i++)
    {
        for(j = i+1; j< tam; j++)
        {
            if(vec[i].isEmpty > vec[j].isEmpty)
            {
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }

    for(i = 0 ; i < tam - 1  ; i++)
    {
        for(j = i + 1 ; j < tam  ; j++)
        {
            if(( vec[i].isEmpty == vec[j].isEmpty))
            {
                if(strcmp(vec[i].apellido, vec[j].apellido))
                {
                    aux = vec[i];
                    vec[i] = vec[j];
                    vec[j] = aux;
                }
            }
        }
    }
}

/** \brief se informan los sueldos incluyendo su promedio y el mayor
 *
 * \param vec[] eEmpleado lista de empleados
 * \param tam int tamaño de la lista
 * \return void
 *
 */
void informarSueldos(eEmpleado vec[],int tam)
{
    float promedio = 0;
    float acumulador = 0;
    int contador = 0;
    int i;

    for(i = 0; i < tam; i++)
    {
        if(vec[i].isEmpty)
        {
            acumulador += vec[i].sueldo;
        }
    }

    promedio = acumulador /(i-1);

    for(i = 0; i < tam; i++)
    {
        if(vec[i].isEmpty)
        {
            if(vec[i].sueldo > promedio)
            {
                contador++;
            }
        }

    }
    printf("Suma total de los salarios :%.2f\nPromedio de los salarios :%.2f\nCantidad de empleados que superan el promedio :%d\n",acumulador,promedio,contador);

}

/** \brief es un submenu donde podemos elegir si ver la lista de los empleados o sus sueldos
 *
 * \param vec[] eEmpleado lista de empleados
 * \param tam int tamaño de la lista
 * \param sector[] eSector lista de sectores
 * \param tamSector int tamaño de la lista de sectores
 * \return void
 *
 */
void listarEmpleados(eEmpleado vec[], int tam, eSector sector[], int tamSector)
{
    int opcion;
    char auxOpcion[50];
    char confirmar;
    char seguir = 's';

    do
    {
        system("cls");
        printf(" 1_Mostrar informacion de empleados\n 2_Mostrar informacion de salarios\n 3_Salir...\n");
        while(!getStringNumeros("ingrese una opcion: \n",auxOpcion ))
        {
            printf("intente de nuevo...\n");
        }
        opcion = atoi(auxOpcion);
        switch(opcion)
        {
            case 1:
                ordenarEmpleados(vec,tam);
                mostrartodosEmpleados(vec,tam, sector,tamSector);
                system("pause");
                break;
            case 2:
                informarSueldos(vec,tam);
                system("pause");
                break;
            case 3:
                printf("\n confirmar salida s/n?...\n");
                fflush(stdin);
                confirmar = getche();

                if( tolower(confirmar)== 's')
                {
                    seguir = 'n';
                }

                break;
            default:
                printf("\n Opcion invalida, intente de nuevo...\n");
                system("pause");
                system("break");
            break;
        }
    }while(seguir == 's');
}
