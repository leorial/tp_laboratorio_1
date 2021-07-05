
#ifndef SRC_EPILOTOS_H_
#define SRC_EPILOTOS_H_
typedef struct
{
	int idPiloto;
	char nombre[30];
}ePilotos;

/**
 * @fn ePilotos NewPiloto*()
 * @brief reserva espacio en memoria para nuevo elemnto ePiloto
 *
 * @return elemento ePiloto con espacio en memoria reservado
 */
ePilotos* NewPiloto();

/**
 * @fn ePilotos piloto_NewParametros*(char*, char*)
 * @brief crea elemento ePiloto y setea en el las variables recibidas
 *
 * @param idPilotosStr id de piloto
 * @param nombreStr nombre de piloto
 * @return ePiloto con las variables seteadas
 */
ePilotos* piloto_NewParametros(char* idPilotosStr, char* nombreStr);

/**
 * @fn int piloto_setId(ePilotos*, int*)
 * @brief setea id de un ePiloto
 *
 * @param this variable ePiloto
 * @param id id a setear
 * @return [1]si se realizo con exito [0]si id es menor a 0 o NULL
 */
int piloto_setId(ePilotos* this, int* id);

/**
 * @fn int piloto_setNombre(ePilotos*, char*)
 * @brief setea nombre del piloto
 *
 * @param this variable ePiloto
 * @param nombre nombre a setear
 * @return [1]si se realizo con exito [0]si this es NULL
 */
int piloto_setNombre(ePilotos* this, char* nombre);

/**
 * @fn int piloto_getId(ePilotos*, int*)
 * @brief guarda en un puntero el id del ePiloto recibido
 *
 * @param this variable ePiloto
 * @param id puntero donde se guarda el id
 * @return [1]si se realizo con exito [0]si el puntero o el ePiloto son NULL
 */
int piloto_getId(ePilotos* this, int* id);

/**
 * @fn int piloto_getNombre(ePilotos*, char*)
 * @brief guarda en un puntero el nombre del ePiloto recibido
 *
 * @param this variable ePiloto
 * @param nombre puntero donde se guarda el nombre
 * @return [1]si se realizo con exito [0]si el puntero o el ePiloto son NULL
 */
int piloto_getNombre(ePilotos* this, char* nombre);




#endif /* SRC_EPILOTOS_H_ */
