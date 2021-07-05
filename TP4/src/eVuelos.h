#ifndef SRC_EVUELOS_H_
#define SRC_EVUELOS_H_

typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;


typedef struct
{
	int idVuelo;
	int idAvion;
	int idPiloto;
	eFecha fecha;
	char destino[20];
	int cantPasajeros;
	int horaDespegue;
	int horaLlegada;
}eVuelo;

/**
 * @fn eVuelo NewVuelo*()
 * @brief reserva espacio en memoria para nuevo elemento eVuelo
 *
 * @return elemento eVuelo con espacio reservado en memoria
 */
eVuelo* NewVuelo();

/**
 * @fn eVuelo vuelo_NewParametros*(char*, char*, char*, char*, char*, char*, char*, char*, char*, char*)
 * @brief crea elemento eVuelo y setea en el las variables recibidas
 *
 * @param idVueloStr id de vuelo a setear
 * @param idAvionStr id de avion a setear
 * @param idPilotoStr id de piloto a setear
 * @param diaStr dia a setear
 * @param mesStr mes a setear
 * @param anioStr año a setear
 * @param destinoStr destino a setear
 * @param cantPasajerosStr cantidad de pasajeros a setear
 * @param horaDespegueStr hora de despegue a setear
 * @param horaLlegadaStr hora de llegada a setear
 * @return elemento eVuelo con variables seteadas
 */
eVuelo* vuelo_NewParametros(char* idVueloStr, char* idAvionStr,char* idPilotoStr,char* diaStr,char* mesStr,char* anioStr,char* destinoStr,char* cantPasajerosStr,char* horaDespegueStr,char* horaLlegadaStr);

/**
 * @fn int vuelo_SetIdVuelo(eVuelo*, int*)
 * @brief  setea un id de vuelo en un eVuelo
 *
 * @param this elemento eVuelo
 * @param IdVuelo id de vuelo a setear
 * @return [1]si se realizo con exito [0]si id es menor a 0 o NULL
 */
int vuelo_SetIdVuelo(eVuelo* this, int* IdVuelo);

/**
 * @fn int vuelo_SetIdAvion(eVuelo*, int*)
 * @brief setea un id de avion en un eVuelo
 *
 * @param this puntero a elemento eVuelo
 * @param IdAvion id de avion a setear
 * @return [1]si se realizo con exito [0]si id es menor a 0 o NULL
 */
int vuelo_SetIdAvion(eVuelo* this, int* IdAvion);

/**
 * @fn int vuelo_SetIdPiloto(eVuelo*, int*)
 * @brief setea un id de piloto en un eVuelo
 *
 * @param this puntero a elemento eVuelo
 * @param IdPiloto id de piloto a setear
 * @return [1]si se realizo con exito [0]si id es menor a 0 o NULL
 */
int vuelo_SetIdPiloto(eVuelo* this, int* IdPiloto);

/**
 * @fn int vuelo_SetFecha(eVuelo*, int*, int*, int*)
 * @brief setea una fecha en un eVuelo
 *
 * @param this puntero a elemento eVuelo
 * @param dia dia a setear
 * @param mes mes a setear
 * @param anio año a setear
 * @return
 */
int vuelo_SetFecha(eVuelo* this, int* dia, int* mes, int* anio);

/**
 * @fn int vuelo_SetDestino(eVuelo*, char*)
 * @brief setea un destino en un eVuelo
 *
 * @param this puntero a elemento eVuelo
 * @param destino destino a setear
 * @return [1]si se realizo con exito [0]si this es NULL
 */
int vuelo_SetDestino(eVuelo* this, char* destino);

/**
 * @fn int vuelo_SetCantPasajeros(eVuelo*, int*)
 * @brief setea una cantidad de pasajeros en un eVuelo
 *
 * @param this puntero a elemento eVuelo
 * @param CantPasajeros cantidad de pasajeros a setear
 * @return [1]si se realizo con exito [0]si this es NULL
 */
int vuelo_SetCantPasajeros(eVuelo* this, int* CantPasajeros);

/**
 * @fn int vuelo_SetHoraDespegue(eVuelo*, int*)
 * @brief setea un horario de despegue en un eVuelo
 *
 * @param this puntero a elemento eVuelo
 * @param HoraDespegue horario de despegue a setear
 * @return [1]si se realizo con exito [0]si this es NULL
 */
int vuelo_SetHoraDespegue(eVuelo* this, int* HoraDespegue);

/**
 * @fn int vuelo_SetHoraLlegada(eVuelo*, int*)
 * @brief setea un horarios de llegada en un eVuelo
 *
 * @param this puntero a elemento eVuelo
 * @param HoraLlegada horario de llegada a setear
 * @return [1]si se realizo con exito [0]si this es NULL
 */
int vuelo_SetHoraLlegada(eVuelo* this, int* HoraLlegada);

/**
 * @fn int vuelo_GetIdVuelo(eVuelo*, int*)
 * @brief guarda en un puntero el id de vuelo del eVuelo recibido
 *
 * @param this puntero a elemento eVuelo
 * @param IdVuelo puntero donde se guarda el id de vuelo
 * @return [1]si se realizo con exito [0]si this o punteros son NULL
 */
int vuelo_GetIdVuelo(eVuelo* this, int* IdVuelo);

/**
 * @fn int vuelo_GetIdAvion(eVuelo*, int*)
 * @brief guarda en un puntero el id de avion del eVuelo recibido
 *
 * @param this puntero a elemento eVuelo
 * @param IdAvion puntero donde se guarda el el id de avion
 * @return [1]si se realizo con exito [0]si this o punteros son NULL
 */
int vuelo_GetIdAvion(eVuelo* this, int* IdAvion);

/**
 * @fn int vuelo_GetIdPiloto(eVuelo*, int*)
 * @brief guarda en un puntero el id  de piloto del eVuelo recibido
 *
 * @param this puntero a elemento eVuelo
 * @param IdPiloto puntero donde se guarda el id de piloto
 * @return [1]si se realizo con exito [0]si this o punteros son NULL
 */
int vuelo_GetIdPiloto(eVuelo* this, int* IdPiloto);

/**
 * @fn int vuelo_GetDia(eVuelo*, int*)
 * @brief guarda en un puntero el dia del eVuelo recibido
 *
 * @param this puntero a elemento eVuelo
 * @param dia puntero donde se guarda el dia del vuelo
 * @return [1]si se realizo con exito [0]si this o punteros son NULL
 */
int vuelo_GetDia(eVuelo* this, int* dia);

/**
 * @fn int vuelo_GetMes(eVuelo*, int*)
 * @brief guarda en un puntero el mes del eVuelo recibido
 *
 * @param this puntero a elemento eVuelo
 * @param mes puntero donde se guarda el mes del vuelo
 * @return [1]si se realizo con exito [0]si this o punteros son NULL
 */
int vuelo_GetMes(eVuelo* this, int* mes);

/**
 * @fn int vuelo_GetAnio(eVuelo*, int*)
 * @brief guarda en un puntero el año del eVuelo recibido
 *
 * @param this puntero a elemento eVuelo
 * @param anio puntero donde se guarda el año del vuelo
 * @return [1]si se realizo con exito [0]si this o punteros son NULL
 */
int vuelo_GetAnio(eVuelo* this, int* anio);

/**
 * @fn int vuelo_GetDestino(eVuelo*, char*)
 * @brief guarda en un puntero el destino del eVuelo recibido
 *
 * @param this elemento eVuelo
 * @param destino puntero donde se guarda el destino
 * @return [1]si se realizo con exito [0]si this o punteros son NULL
 */
int vuelo_GetDestino(eVuelo* this, char* destino);

/**
 * @fn int vuelo_GetCantPasajeros(eVuelo*, int*)
 * @brief guarda en un puntero el la cantidad de pasajeros del eVuelo recibido
 *
 * @param this elemento eVuelo
 * @param CantPasajeros puntero donde se guarda la cantidad de pasajeros
 * @return [1]si se realizo con exito [0]si this o punteros son NULL
 */
int vuelo_GetCantPasajeros(eVuelo* this, int* CantPasajeros);

/**
 * @fn int vuelo_GetHoraDespegue(eVuelo*, int*)
 * @brief guarda en un puntero la hora de despegue del eVuelo recibido
 *
 * @param this elemento eVuelo
 * @param HoraDespegue puntero donde se guarda el horario de despegue
 * @return [1]si se realizo con exito [0]si this o punteros son NULL
 */
int vuelo_GetHoraDespegue(eVuelo* this, int* HoraDespegue);

/**
 * @fn int vuelo_GetHoraLlegada(eVuelo*, int*)
 * @brief guarda en un puntero la hora de llegada del eVuelo recibido
 *
 * @param this puntero a elemento eVuelo
 * @param HoraLlegada puntero donde se guarda el horario de llegada
 * @return [1]si se realizo con exito [0]si this o punteros son NULL
 */
int vuelo_GetHoraLlegada(eVuelo* this, int* HoraLlegada);

/**
 * @fn int vuelo_CountPassengers(void*)
 * @brief cuenta la cantidad de pasajeros en el elemento
 *
 * @param element elemento a contar
 * @return cantidad de pasajeros en el elemento
 */
int vuelo_CountPassengers(void* element);

/**
 * @fn int vuelo_CountPassengersToChina(void*)
 * @brief cuenta la cantidad de pasajeros en el elemento si el destino es china
 *
 * @param element elemento a contar
 * @return cantidad de pasajeros a china en este elemento
 */
int vuelo_CountPassengersToChina(void* element);

int vuelo_FiltrarVuelosLargos(void* element);
int vuelo_FiltrarVuelosAPortugal(void* element);
int vuelo_FiltrarPilotos(void* element);




#endif /* SRC_EVUELOS_H_ */
