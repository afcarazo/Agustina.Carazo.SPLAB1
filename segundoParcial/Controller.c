#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "input.h"
#include "pais.h"
#include "parser.h"
#include <string.h>

int controller_loadFromText(char* path, LinkedList* pArrayListPaises)
{
    FILE *pArchivo= NULL;
    int retorno = 0;
    system("cls");
    printf("\n------------------------------------------------------\n");
    printf("               Cargar archivo modo texto");
    printf("\n------------------------------------------------------\n\n");

    if(path!=NULL && pArrayListPaises!=NULL)
    {
        pArchivo= fopen(path, "r");
        if(pArchivo!=NULL)
        {
            if(parser_PaisesFromText(pArchivo,pArrayListPaises))
            {
                printf("\nSe ha cargado con exito\n\n");
                retorno=1;

            }
        }
        else
        {
            printf("No se pudo abrir el archivo\n\n");
            system("pause");
            exit(1);
        }
        fclose(pArchivo);
    }

    return retorno;
}

int controller_ListPais(LinkedList* pArrayPaises)
{
    int retorno=0;
    system("cls");
    printf("\n-------------------------------------------------------------------------");
    printf("\n                             Listar paises         ");
    printf("\n-------------------------------------------------------------------------\n");
    if(pArrayPaises!=NULL)
    {
        if(pais_printPaises(pArrayPaises))
        {

            printf("\n-------------------------------------------------------------------------\n");
            retorno=1;

        }
    }
    return retorno;
}


int controller_asignarEstadisticas(LinkedList*pArrayPaises)
{
    int retorno=0;
    LinkedList* auxLista=NULL;//retorno de map

    if(pArrayPaises!=NULL)
    {
        auxLista=ll_map(pArrayPaises,aplicarEstadisticas);
        if(auxLista!=NULL)
        {
            pArrayPaises=auxLista;
            ll_deleteLinkedList(auxLista);
            retorno=1;
        }
    }

    return retorno;
}




int controller_FiltrarExitosos(LinkedList* listaPaises)
{
    int retorno = 0;
    LinkedList* listaNueva=NULL;
    listaNueva= ll_filter(listaPaises,pais_filtrarPaisesExitosos);
    if(listaNueva!=NULL)
    {
        controller_saveAsText("PaisesExitosos.csv",listaNueva);
        printf("Archivo filtrado por paises exitosos realizado. \n");
        retorno=1;
    }
    else
    {
        printf("\nNo se pudo crear el archivo");
    }

return retorno;
}


int controller_FiltrarEnElHorno(LinkedList* listaPaises)
{
    int retorno = 0;
    LinkedList* listaNueva=NULL;
    listaNueva= ll_filter(listaPaises,pais_filtrarPaisesEnElHorno);
    if(listaNueva!=NULL)
    {
        controller_saveAsText("PaisesEnElHorno.csv",listaNueva);
        printf("Archivo filtrado por paises en el horno realizado. \n");
        retorno=1;
    }
    else
    {
        printf("\nNo se pudo crear el archivo");
    }

return retorno;
}


int controller_saveAsText(char* path, LinkedList* pArrayPaises)
{
    FILE* pArchivo;
    ePais* auxPais = NULL;
    int retorno = 0;


    int auxId;
    char nombre[20];
    int primerDosis;
    int segundaDosis;
    int sinVacunar;

    int cantidadCargados=0;

    system("cls");
    printf("\n------------------------------------------------------\n");
    printf("             Guardar archivo modo texto");
    printf("\n------------------------------------------------------\n\n");

    if(path!=NULL && pArrayPaises!=NULL)
    {

        pArchivo = fopen(path, "w");

        if(pArchivo==NULL)
        {
            printf("No se pudo abrir el archivo\n");
            system("pause");
            exit(1);
        }
        else
        {

            fprintf(pArchivo,"id, nombre, vac1dosis, vac2dosis, sinVacunar\n");

            for(int i =0; i<ll_len(pArrayPaises); i++)
            {
                auxPais= (ePais*)ll_get(pArrayPaises,i);
                if(auxPais!=NULL)
                {
                    if(pais_getVerificar(auxPais,&auxId,nombre,&primerDosis,&segundaDosis,&sinVacunar)==1)
                    {
                        fprintf(pArchivo,"%d,%s,%d,%d,%d\n",auxId,nombre,primerDosis,segundaDosis,sinVacunar);
                        cantidadCargados++;
                    }
                    else
                    {
                        pais_delete(auxPais);
                        printf("\nNo se pudo guardar");
                    }
                }
                auxPais= NULL;
            }
            if(cantidadCargados == ll_len(pArrayPaises))
            {
                retorno=1;
            }
        }

    }
    fclose(pArchivo);


    return retorno;
}


int controller_sortPais(LinkedList* pArrayPaises)
{
    int retorno = 0;
    system("cls");
    printf("\n------------------------------------------------------\n");
    printf("              Ordenar Paises");
    printf("\n------------------------------------------------------\n\n");

    if(pArrayPaises!=NULL)
    {
        if(!ll_sort(pArrayPaises,pais_cmpVacunados,1))
        {
            controller_ListPais(pArrayPaises);
            retorno=1;
        }
    }

    return retorno;
}
int controller_paisMasCastigado(LinkedList* listaPaises)
{

    void* pElement = NULL;
    int maximoSinVac;
    int cantidadSinVac;
    int tam;
    char auxNombre[25];
    int retorno= 0;

    printf("\n------------------------------------------------------\n");
    printf("              Pais/paises mas castigados");
    printf("\n------------------------------------------------------\n\n");
    if(listaPaises!= NULL)
    {
        tam=ll_len(listaPaises);
        for(int i=0; i<tam; i++)
        {
            pElement=(ePais*)ll_get(listaPaises,i);
            if(pais_getSinVacunar(pElement,&cantidadSinVac))
            {
                if(i==0 || cantidadSinVac>maximoSinVac)
                {
                    maximoSinVac=cantidadSinVac;
                }
            }
        }

        for(int i=0; i<tam; i++)
        {
            pElement=(ePais*)ll_get(listaPaises,i);
            if(pElement!=NULL)
            {
                if(pais_getSinVacunar(pElement,&cantidadSinVac))
                {
                    if(maximoSinVac==cantidadSinVac)
                    {
                        pais_getNombre(pElement,auxNombre);
                        printf(" %20s %d\n",auxNombre,cantidadSinVac);
                        retorno=0;

                    }
                }
            }
        }
    }

return retorno;
}

