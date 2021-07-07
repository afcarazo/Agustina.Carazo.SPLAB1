#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "pais.h"
#include "Controller.h"
#include "input.h"
#include "LinkedList.h"
#include "parser.h"


int main()
{
    LinkedList* listaPaises = ll_newLinkedList();

    char salir= 'n';
    int flagTexto=0; //carga no realizada
    int opcion;
    int flagMap=0;
    char respuesta[2];
    do
    {

        switch(menuListaPaises())
        {

        case 1:

            if(ll_isEmpty(listaPaises) || flagTexto==0)
            {
                system("cls");
                printf("\n\nEleccion del archivo que se cargara:\n\n");

                utn_getNumero(&opcion,"\n1.Cargar desde la lista original.\n\n2.Cargar lo ultimo guardado.\n\nSeleccione opcion: ","\nError,opcion invalida\n",1,2,3);

                if(opcion==1)
                {
                    if(controller_loadFromText("vacunas.csv",listaPaises))
                    {
                        flagTexto=1; //carga realizada
                    }
                    else
                    {
                        printf("\nNo se ha cargado el archivo\n\n");
                    }
                }
                else if(opcion==2)
                {

                    if(controller_loadFromText("vacunas2.csv",listaPaises))
                    {
                        flagTexto=1; //carga realizada
                    }
                    else
                    {
                        printf("\nNo se ha cargado el archivo\n\n");
                    }
                }
            }
            else
            {
                printf("\nNo puedes cargar dos veces el archivo\n\n");
            }
            system("pause");

            break;

        case 2:
            if(!ll_isEmpty(listaPaises))
            {
                controller_ListPais(listaPaises);
            }
            else
            {
                printf("\nNo hay paises para mostrar\n\n");
            }
            system("pause");
            break;
        case 3:
            if(!ll_isEmpty(listaPaises))
            {
                if(controller_asignarEstadisticas(listaPaises))
                {
                    printf("\nAgregado con exito!!\n");
                    flagMap=1;
                }
            }
            else
            {
                printf("\nLa lista de paises esta vacia\n");
            }
            system("pause");
            break;

        case 4:
            if(!ll_isEmpty(listaPaises))
            {
                if(flagMap==0)
                {
                    printf("Todavia no se han cargado las estadisticas\n");
                }
                else
                {
                    controller_FiltrarExitosos(listaPaises);
                }
            }
            else
            {
                printf("\nLa lista de paises esta vacia\n");
            }
            system("pause");
            break;


        case 5:
            if(!ll_isEmpty(listaPaises))
            {
                if(flagMap==0)
                {
                    printf("Todavia no se han cargado las estadisticas\n");
                }
                else
                {
                    controller_FiltrarEnElHorno(listaPaises);
                }
            }
            else
            {
                printf("\nLa lista de paises esta vacia\n");
            }
            system("pause");
            break;


        case 6:
            if(!ll_isEmpty(listaPaises))
            {
                if(flagMap==0)
                {
                    printf("Todavia no se han cargado las estadisticas\n");
                }
                else
                {
                    controller_sortPais(listaPaises);
                }
            }
            else
            {
                printf("\nLa lista de paises esta vacia\n");
            }
            system("pause");
            break;
         case 7:
            if(!ll_isEmpty(listaPaises))
            {
                if(flagMap==0)
                {
                    printf("Todavia no se han cargado las estadisticas\n");
                }
                else
                {
                  if(!controller_paisMasCastigado(listaPaises)){
                   printf("\nOcurrio un problema");
                  }
                }
            }
            else
            {
                printf("\nLa lista de paises esta vacia\n");
            }
            system("pause");
            break;

        case 8:
            utn_getChar(respuesta,2,"\nEsta seguro de que desea salir? Ingrese s/n: ","\nError, ingrese s/n\n",3);
            if(!strcmp(respuesta,"s"))
            {
                printf("\nHa abandonado el programa\n");
                salir = 's';
            }
            system("pause");
            break;

        default:
            printf("Opcion invalida.\n");
            system("pause");
            break;

        }
    }
    while(salir=='n');
    return 0;
}

