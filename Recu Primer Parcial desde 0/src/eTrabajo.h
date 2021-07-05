
#ifndef ETRABAJO_H_
#define ETRABAJO_H_

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int idTrabajo;
    int idBicicleta;
    int idServicio;
    eFecha fecha;
    int idFactura;
    int isEmpty;
}eTrabajo;

void trabajo_startArray (eTrabajo* trabajo, int tam);
int trabajo_searchFree (eTrabajo* unTrabajo, int size);
int trabajo_getDate(eTrabajo* unTrabajo, int size);
int trabajo_validarId(eTrabajo* unTrabajo, int size, int auxId);
int trabajo_buscarIndexPorId(eTrabajo* listaTrabajos, int size, int id);
void trabajo_clonarListaTrabajos(eTrabajo* listaTrabajos, int size1, eTrabajo* auxListaTrabajos, int size2);

#endif /* ETRABAJO_H_ */
