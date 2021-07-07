#include "LinkedList.h"
#ifndef PAIS_H_INCLUDED
#define PAIS_H_INCLUDED
typedef struct
{
    int id;
    char nombre[20];
    int vac1dosis;
    int vac2dosis;
    int sinVacunar;

}ePais;

#endif // PAIS_H_INCLUDED
/** \brief aplica estadisticas
 *
 * \param pais void* puntero a pais
 * \return void*
 *
 */
void* aplicarEstadisticas(void* pais);
/** \brief filtra por paises exitosos
 *
 * \param element void* puntero a pais
 * \return int retorna uno si se cumple la condicion, si hubo un error retorna 0
 *
 */
int pais_filtrarPaisesExitosos(void* element);
/** \brief  filtra por paises en el horno
 *
 * \param element void* puntero a pais
 * \return int  retorna uno si se cumple la condicion, si hubo un error retorna 0
 *
 */
int pais_filtrarPaisesEnElHorno(void* element);

/** \brief compara si los elementos son iguales, menor a o mayor a
 *
 * \param a void*
 * \param b void*
 * \return int devuelve 0 si son iguales, 1 si la cadena uno es mayor a la segunda, -1  si la cadena uno es menor a la segunda
 *
 */
int pais_cmpVacunados(void* a,void* b);
/** \brief verifica que todos los get sean correctos
 *
 * \param this ePais* puntero a pais
 * \param id int* puntero a id
 * \param nombre char* puntero a cadena nombre
 * \param int*vac1dosis puntero a primer dosis
 * \param int*vac2dosis  puntero a segunda dosis
 * \param int*sinVacunar puntero a sin vacunar
 * \return int retorna 1 si salio todo bien de lo contrario 0
 *
 */
int pais_getVerificar(ePais* this,int* id,char* nombre, int*vac1dosis,int*vac2dosis,int*sinVacunar);
/** \brief imprime lista de paises
 *
 * \param listaPaises LinkedList* puntero a lista de paises
 * \return int retorna 1 si salio todo bien de lo contrario 0
 *
 */
int pais_printPaises(LinkedList* listaPaises);
/** \brief elimina pais
 *
 * \param this ePais* puntero a pais que se liberara
 * \return void
 *
 */
void pais_delete(ePais* this);
/** \brief permite acceder al valor del atributo sin vacunar de la identidad
 *
 * \param this ePais* puntero a pais
 * \param sinVacunar int* puntero a sin vacunar
 * \return int retorna 1 si salio todo bien de lo contrario 0
 *
 */
int pais_getSinVacunar(ePais* this,int* sinVacunar);
/** \brief permite acceder al valor del atributo nombre de la identidad
 *
 * \param this ePais* puntero a pais
 * \param nombre char*  puntero a nombre
 * \return int retorna 1 si salio todo bien de lo contrario 0
 *
 */
int pais_getNombre(ePais* this,char* nombre);
/** \brief muestra menu de opciones
 *
 * \return int retorna 1 si salio todo bien de lo contrario 0
 *
 */
int menuListaPaises();
/** \brief permite reservar memoria para un empleado y dar valor inicial a varios campos de la entidad
 *
 * \param idStr char*  puntero a id
 * \param nombreStr char*  puntero a nombre
 * \param vac1dosisStr char*  puntero a primer dosis
 * \param vac2dosisStr char*  puntero a segunda dosis
 * \param sinVacunarStr char*  puntero a sin vacunar
 * \return ePais* retorna puntero a pais si consiguio espacio sino NULL
 *
 */
ePais* pais_newParametros(char* idStr,char* nombreStr,char* vac1dosisStr,char* vac2dosisStr,char* sinVacunarStr);

