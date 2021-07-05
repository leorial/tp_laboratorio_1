/*
 * parser.h
 *
 *  Created on: 24 jun. 2021
 *      Author: Leo
 */

#ifndef SRC_PARSER_H_
#define SRC_PARSER_H_
#include <stdio.h>
#include "../inc/LinkedList.h"

/**
 * @fn int parser_VuelosFromText(FILE*, LinkedList*)
 * @brief carga los datos de un archivo a una LinkedList.
 *
 * @param pFile ruta al archivo abierto.
 * @param pArrayVuelos LinkedList a cargar los datos.
 * @return [1]si se logro leer y cargar correctamente [0]si el LL o el archivo son NULL
 */
int parser_VuelosFromText(FILE* pFile, LinkedList* pArrayVuelos);

/**
 * @fn int parser_PilotosFromText(FILE*, LinkedList*)
 * @brief carga los datos de un archivo a una LinkedList.
 *
 * @param pFile ruta al archivo abierto.
 * @param pArrayPilotos LinkedList a cargar los datos.
 * @return [1]si se logro leer y cargar correctamente [0]si el LL o el archivo son NULL
 */
int parser_PilotosFromText(FILE* pFile, LinkedList* pArrayPilotos);

#endif /* SRC_PARSER_H_ */
