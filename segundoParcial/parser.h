#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

/** \brief Parsea los datos los datos de los paises desde el archivo pandemia.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPaises LinkedList* lista de paises
 * \return int retorna 1 sino hubo ningun error de lo contrario 0
 *
 */

int parser_PaisesFromText(FILE* pFile, LinkedList* pArrayListPaises);

#endif // PARSER_H_INCLUDED
