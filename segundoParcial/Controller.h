#include "LinkedList.h"

/** \brief Carga los datos de los paises desde el archivo pandemia.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPaises LinkedList* lista de paises
 * \return int retorna 1 sino hubo ningun error de lo contrario 0
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPaises);

/** \brief Listar paises
 *
 * \param path char*
 * \param pArrayPaises LinkedList* lista de paises
 * \return int retorna 1 sino hubo ningun error de lo contrario 0
 *
 */
int controller_ListPais(LinkedList* pArrayPaises);
/** \brief Ordenar paises
 *
 * \param path char*
 * \param pArrayPaises LinkedList* lista de paises
 * \return int retorna 1 sino hubo ningun error de lo contrario 0
 *
 */
int controller_sortPais(LinkedList* pArrayPaises);

/** \brief Guarda los datos de los paises en modo texto
 *
 * \param path char*
 * \param pArrayPaises LinkedList* lista de paises
 * \return int retorna 1 sino hubo ningun error de lo contrario 0
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayPaises);


/** \brief asigna estadisticas a paises
 *
 * \param LinkedList*pArrayPaises puntero a lista de paises
 * \return  int retorna 1 sino hubo ningun error de lo contrario 0
 *
 */
int controller_asignarEstadisticas(LinkedList*pArrayPaises);
/** \brief permite filtrar los paises exitosos
 *
 * \param listaPaises LinkedList* lista de paises
 * \return int retorna 1 sino hubo ningun error de lo contrario 0
 *
 */
int controller_FiltrarExitosos(LinkedList* listaPaises);
/** \brief permite filtrar los paises en el horno
 *
 * \param listaPaises LinkedList* lista de paises
 * \return int retorna 1 sino hubo ningun error de lo contrario 0
 *
 */
int controller_FiltrarEnElHorno(LinkedList* listaPaises);
/** \brief permite filtrar pais mas castigado
 *
 * \param listaPaises LinkedList* lista de paises
 * \return int int retorna 1 sino hubo ningun error de lo contrario 0
 *
 */
int controller_paisMasCastigado(LinkedList* listaPaises);


