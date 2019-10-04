#include "sectore.h"

int obtenerSector(eSector sectores[], int tam, int idSector, char desc[])
{
    int todoOk;
    int i;

    for(i=0; i<tam; i++)
    {
        if(idSector==sectores[i].id)
        {
            strcpy(desc, sectores[i].desc);
            todoOk=1;
            break;
        }
    }
    return todoOk;
}

