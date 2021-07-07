#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pais.h"
#include "input.h"



ePais* pais_new()
{
    ePais* nuevoPais = (ePais*) malloc(sizeof(ePais));

    if(nuevoPais!=NULL)
    {
        nuevoPais->id = 0;
        strcpy(nuevoPais->nombre, " ");
        nuevoPais->sinVacunar= 0;
        nuevoPais->vac2dosis =0;
        nuevoPais->vac1dosis= 0;
    }
    return nuevoPais;
}


int pais_printPais(ePais* this)
{
    int retorno=0;
    int id;
    char nombre[20];
    int vac1dosis;
    int vac2dosis;
    int sinVacunar;
    if(this!=NULL && pais_getVerificar(this,&id,nombre,&vac1dosis,&vac2dosis,&sinVacunar)
      )
    {
        printf(" %2d   %20s   %5d       %5d          %5d \n",
               id,
               nombre,
               vac1dosis,
               vac2dosis,
               sinVacunar);
        retorno=1;
    }

    return retorno;
}

int pais_printPaises(LinkedList* listaPaises)
{
    int retorno=0;
    int tam;
    ePais* auxPais= NULL;

    tam= ll_len(listaPaises);
    if(listaPaises!=NULL && tam>0)
    {
        printf("ID                  NOMBRE      VAC1DOSIS  VAC2DOSIS   SIN VACUNAR");
        printf("\n-------------------------------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            auxPais= (ePais*)ll_get(listaPaises,i);
            pais_printPais(auxPais);
        }
        printf("\n");
        retorno=1;
    }
    return retorno;
}

int pais_setId(ePais* this,int id)
{
    int retorno = 0;

    if(this!=NULL && id>=0)
    {
        this->id = id;
        retorno=1;
    }

    return retorno;
}
int pais_getId(ePais* this,int* id)
{
    int retorno = 0;
    if(this!=NULL && id!=NULL && id>0)
    {
        *id= this->id;
        retorno=1;
    }
    return retorno;
}
/** \brief verifica si se trata de un nombre valido
 *
 * \param char*cadena cadena que sera evaluada
 * \param tam int tamanio del array cadena
 * \return int retorna 1 si es una cadena valida de lo contrario 0
 *
 */
static int esNombreValido(char*cadena, int tam)
{

    int retorno = 0;

    if(cadena!=NULL && tam>0)
    {
        for(int i=0 ; cadena[i] != '\0' && i < tam; i++)
        {

            if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' || cadena[i] > ' ' || cadena[i] > '-'))
            {
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}
int pais_setNombre(ePais* this,char* nombre)
{
    int retorno = 0;

    if(this!=NULL && nombre!=NULL)
    {
        if(esNombreValido(nombre,20)==1)
        {
            strcpy(this->nombre, nombre);
            retorno=1;
        }
    }

    return retorno;
}
int pais_getNombre(ePais* this,char* nombre)
{
    int retorno = 0;
    if(this!=NULL && nombre !=NULL)
    {
        strcpy(nombre, this->nombre);
        retorno= 1;

    }
    return retorno;
}

int pais_setSinVacunar(ePais* this,int sinVacunar)
{
    int retorno = 0;

    if(this!=NULL && sinVacunar>=0)
    {
        this->sinVacunar = sinVacunar;
        retorno=1;
    }

    return retorno;
}
int pais_getSinVacunar(ePais* this,int* sinVacunar)
{
    int retorno = 0;
    if(this!=NULL && sinVacunar!=NULL)
    {
        *sinVacunar= this->sinVacunar;
        retorno=1;
    }
    return retorno;
}

int pais_setVac1dosis(ePais* this,int vac1dosis)
{
    int retorno = 0;

    if(this!=NULL && vac1dosis>=0)
    {
        this->vac1dosis = vac1dosis;
        retorno=1;
    }

    return retorno;
}
int pais_getVac1dosis(ePais* this,int* vac1dosis)
{
    int retorno = 0;
    if(this!=NULL && vac1dosis!=NULL)
    {
        *vac1dosis= this->vac1dosis;
        retorno=1;
    }
    return retorno;
}

int pais_setVac2dosis(ePais* this,int vac2dosis)
{
    int retorno = 0;

    if(this!=NULL && vac2dosis>=0)
    {
        this->vac2dosis = vac2dosis;
        retorno=1;
    }

    return retorno;
}

int pais_getVac2dosis(ePais* this,int* vac2dosis)
{
    int retorno = 0;
    if(this!=NULL && vac2dosis!=NULL)
    {
        *vac2dosis= this->vac2dosis;
        retorno=1;
    }
    return retorno;
}


int pais_getVerificar(ePais* this,int* id,char* nombre, int*vac1dosis,int*vac2dosis,int*sinVacunar)
{
    int retorno = 0;
    if(this!=NULL)
    {
        if(pais_getId(this, id) &&pais_getNombre(this,nombre) && pais_getVac1dosis(this,vac1dosis)&&pais_getVac2dosis(this, vac2dosis) && pais_getSinVacunar(this, sinVacunar))
        {
            retorno=1;
        }
    }

    return retorno;
}


int pais_setVerificar(ePais* this,int id,char* nombre, int vac1dosis,int vac2dosis,int sinVacunar)
{
    int retorno = 0;
    if(this!=NULL)
    {
        if(pais_setId(this,id) && pais_setNombre(this,nombre)&& pais_setVac1dosis(this,vac1dosis)&&pais_setVac2dosis(this, vac2dosis) && pais_setSinVacunar(this, sinVacunar))
        {
            retorno=1;
        }
    }

    return retorno;
}

void pais_delete(ePais* this)
{

    if(this!=NULL)
    {
        free(this);
    }

}
ePais* pais_newParametros(char* idStr,char* nombreStr,char* vac1dosisStr,char* vac2dosisStr,char* sinVacunarStr )
{
    ePais* nuevoPais = pais_new();
    int flagOk=0;

    if(nuevoPais!=NULL )
    {
        if(pais_setId(nuevoPais, atoi(idStr)) && pais_setNombre(nuevoPais,nombreStr) && pais_setVac1dosis(nuevoPais, atoi(vac1dosisStr))&& pais_setVac2dosis(nuevoPais, atoi(vac2dosisStr))&& pais_setSinVacunar(nuevoPais, atoi(sinVacunarStr)))
        {
            flagOk=1;
        }
    }

    if(flagOk==0)
    {
        pais_delete(nuevoPais);
        nuevoPais=NULL;
    }

    return nuevoPais;
}

int menuListaPaises()
{
    int option;
    system("cls");
    printf("\n\n -------------------------------------------------------------------------------\n");
    printf("                                MENU DE OPCIONES");
    printf("\n -------------------------------------------------------------------------------\n\n");
    printf(" 1. Cargar los datos de los paises desde el archivo vacunas.csv (modo texto).\n");
    printf(" 2. Listar \n");
    printf(" 3. Agregar estadisticas\n");
    printf(" 4. Filtrar por paises exitosos\n");
    printf(" 5. Filtrar por paises en el horno\n");
    printf(" 6. Ordenar por nivel de vacunación:\n");
    printf(" 7. Mostrar mas castigado\n");
    printf(" 8. Salir\n");

    printf("\n\n -------------------------------------------------------------------------------\n");

    utn_getNumero(&option, "\nIngrese opcion: ","\nERROR, opcion invalida. \n",1,10,3);

    return option;

}

void* aplicarEstadisticas(void* pais)
{
    ePais* auxPais = (ePais*) pais;

    int numero1;
    int numero2;
    int numero3;
    int max1 = 60;
    int min1 = 1;
    int max2 = 40;
    int min2 = 1;


    if(auxPais != NULL )
    {

        numero1 = rand() % (max1 - min1 + 1) + min1;
        pais_setVac1dosis(pais,numero1);

        numero2 = rand() % (max2 - min2 + 1) + min2;
        pais_setVac2dosis(pais,numero2);

        numero3 = 100 - numero1 - numero2;
        pais_setSinVacunar(pais,numero3);
    }
       return pais;
}


int pais_filtrarPaisesExitosos(void* element)
{
    int retorno=0;
    int vac2dosis;
    ePais* pais= NULL;

    if(element!=NULL)
    {
        pais= (ePais*)element;
        pais_getVac2dosis(pais,&vac2dosis);

        if(vac2dosis>30)
        {
            retorno=1;
        }

    }
    return retorno;
}

int pais_filtrarPaisesEnElHorno(void* element)
{
    int retorno=0;
    int vac1dosis;
    int vac2dosis;
    int sinVac;
    ePais* pais= NULL;

    if(element!=NULL)
    {
        pais= (ePais*)element;
        pais_getVac1dosis(pais,&vac1dosis);
        pais_getVac2dosis(pais,&vac2dosis);
        pais_getSinVacunar(pais,&sinVac);


        if(sinVac>(vac1dosis+vac2dosis))
        {
            retorno=1;
        }

    }
    return retorno;
}





int pais_cmpVacunados(void* a,void* b)
{
    int retorno=0;
    ePais* pais1 = NULL;
    ePais* pais2=NULL;
    int cantVac1dosis1;
    int cantVac1dosis2;

    if(a!=NULL&&b!=NULL)
    {
        pais1= (ePais*)a;
        pais2= (ePais*)b;
        pais_getVac1dosis(pais1,&cantVac1dosis1);
        pais_getVac1dosis(pais2,&cantVac1dosis2);

        if(cantVac1dosis1<cantVac1dosis2)
        {
            retorno=-1;
        }
        else if(cantVac1dosis1>cantVac1dosis2)
        {
            retorno=1;
        }
    }

    return retorno;
}



