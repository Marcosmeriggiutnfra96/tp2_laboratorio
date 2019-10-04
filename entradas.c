
#include "entradas.h"

/** \brief verifica que el dato ingresado sea un numero
 *
 * \param let[] char dato ingresado
 * \return int devuelve 1 si es numerico
 *
 */
int esNum(char let[])
{
   int i=0;
   while(let[i] != '\0')
   {
       if(let[i] < '0' || let[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

/** \brief verifica que el dato ingresado sea compuesto solo por letras
 *
 * \param let[] char dato ingresado
 * \return int devuelve 1 si son solo letras
 *
 */
int esSoloLetras(char let[])
{
   int i=0;
   while(let[i] != '\0')
   {
       if((let[i] != ' ') && (let[i] < 'a' || let[i] > 'z') && (let[i] < 'A' || let[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}

/** \brief obtiene un mensaje
 *
 * \param mensaje[] char mensaje para el ingreso
 * \param input[] char datos ingresados por la persona
 * \return void
 *
 */
void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}

/** \brief verifica que el ingreso de atos este compuesto por letras
 *
 * \param mensaje[] char mensaje para el ingreso
 * \param input[] char datos ingresados por la persona
 * \return int devuelve 1 si son solo letras
 *
 */
int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    int retorno;
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        retorno = 1;
    }
    else
    {
        printf("debe usar letras...\n");
        retorno = 0;
    }
    return retorno;
}

/** \brief verifica que el ingreso de datos este compuesto por numeros
 *
 * \param mensaje[] char mensaje para el ingreso
 * \param input[] char datos ingresados por la persona
 * \return int devuelve 1 si son solo numeros
 *
 */
int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    int retorno;
    if(esNum(aux))
    {
        strcpy(input,aux);
        retorno = 1;
    }
    else
    {
        printf("debe usar numeros...\n");
        retorno = 0;
    }

    return retorno;
}
