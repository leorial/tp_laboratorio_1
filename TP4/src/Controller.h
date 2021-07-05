
#ifndef SRC_CONTROLLER_H_
#define SRC_CONTROLLER_H_
#include "../inc/LinkedList.h"
#include "eVuelos.h"

/**
 * @fn int controller_loadVuelosFromText(char*, LinkedList*)
 * @brief abre el archivo de vuelos. lee y carga a una LL los datos contenidos.
 *
 * @param path ruta al archivo a abrir.
 * @param pArrayListVuelos LL a cargar los datos
 * @return [1]si se lee y carga correctamente. [0]si el archivo o la LL son NULL
 */
int controller_loadVuelosFromText(char* path , LinkedList* pArrayListVuelos);

/**
 * @fn int controller_loadPilotosFromText(char*, LinkedList*)
 * @brief abre el archivo de pilotos. lee y carga a una LL los datos contenidos.
 *
 * @param path ruta al archivo a abrir.
 * @param pArrayListPilotos LL a cargar los datos
 * @return [1]si se lee y carga correctamente. [0]si el archivo o la LL son NULL
 */
int controller_loadPilotosFromText(char* path , LinkedList* pArrayListPilotos);

/**
 * @fn int controller_PrintVuelo(eVuelo*, LinkedList*)
 * @brief imprime en pantalla un vuelo.
 *
 * @param this estructura de vuelo a imprimir
 * @param pArrayPilotos array con datos de pilotos
 * @return [1] si se imprime correctamente [0]si la estructura o el array son NULL
 */
int controller_PrintVuelo(eVuelo* this, LinkedList* pArrayPilotos);

/**
 * @fn int controller_ListVuelos(LinkedList*, LinkedList*)
 * @brief itera e imprime toda la LL de vuelos.
 *
 * @param pArrayVuelos LL de vuelos
 * @param pArrayPilotos LL de pilotos
 * @return [1] si se imprime correctamente [0]si algun LL es NULL
 */
int controller_ListVuelos(LinkedList* pArrayVuelos, LinkedList* pArrayPilotos);

/**
 * @fn int controller_CounterPassengers(LinkedList*)
 * @brief cuenta la totalidad de pasajeros y lo imprime en pantalla
 *
 * @param pArrayVuelos LL de vuelos
 * @return [1]si cuenta correctamente [0]si la LL es NULL
 */
int controller_CounterPassengers(LinkedList* pArrayVuelos);

/**
 * @fn int controller_CounterPassengersToChina(LinkedList*)
 * @brief cuenta la totalidad de pasajeros a china y lo imprime en pantalla
 *
 * @param pArrayVuelos LL de vuelos
 * @return [1]si cuenta correctamente [0]si la LL es NULL
 */
int controller_CounterPassengersToChina(LinkedList* pArrayVuelos);

/**
 * @fn void controller_ProgramDown(LinkedList*, LinkedList*)
 * @brief finaliza el programa eliminando de memoria las LL
 *
 * @param pArrayVuelos LL a eliminar
 * @param pArrayPilotos LL a eliminar
 */
void controller_ProgramDown(LinkedList* pArrayVuelos, LinkedList* pArrayPilotos);
int controller_saveAsText(char* path , LinkedList* pArrayVuelos);
int controller_FilterLongFlys(LinkedList* pArrayVuelos);
int controller_ListFlysToPortugal (LinkedList* pArrayVuelos, LinkedList* pArrayPilotos);


#endif /* SRC_CONTROLLER_H_ */
