#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "pais.h"
#include "input.h"

int parser_PaisesFromText(FILE* pFile, LinkedList* pArrayListPaises)
{
    ePais* auxPais= NULL;
    char buffer[4][20];
    int retorno=0;
    int cant=0;
    int flag=0;

    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

    while(!feof(pFile))
    {

        cant= fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

        if(cant==4)
        {
            auxPais=pais_newParametros(buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
            if(auxPais!=NULL)
            {
                ll_add(pArrayListPaises,auxPais);
                auxPais=NULL;
                retorno=1;
            }
            else
            {
                pais_delete(auxPais);
                flag= 2; // problema para crear el pais
                break;
            }
        }
        else
        {
            flag=3; // problema al leer el pais
            break;
        }
    }

    if(flag==2)
    {
        printf("\nNo se pudo crear al pais\n");
    }
    else if(flag==3)
    {
        printf("\nProblema al leer el pais\n");
    }

    return retorno;
}



