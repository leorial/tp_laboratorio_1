
#ifndef ESERVICIOS_H_
#define ESERVICIOS_H_

typedef struct
{
    int id;
    char descripcion[20];
    float precio;
}eServicio;

typedef struct
{
    int id;
    char descripcion[20];
    float precio;
    int contadorTrabajos;
}eAuxServicio;

int servicio_searchIndexById(eServicio* unServicio, int size, int id);

/**
 * @fn void servicio_listarServicios(eServicio*, int)
 * @brief imprime en pantalla la lista de servicios
 *
 * @param listaServicios puntero a array de lista de servicios
 * @param size tamaño del array
 */
void servicio_listarServicios(eServicio* listaServicios, int size);
void servicio_mostrarUnServicio (eServicio* unServicio, int index);
int servicio_getIdServicio(eServicio* listaServicios, int size3);
int servicio_validarId(eServicio* unServicio, int size, int auxId);
void auxServicio_inicializarEstructuraAuxiliar(eServicio* unServicio, int size, eAuxServicio* auxServicio, int size2);
void auxServicio_mostrarMayorContadorServicios(eAuxServicio* auxListaServicios, int size3);













#endif /* ESERVICIOS_H_ */
