#include "eTrabajo.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void trabajo_startArray (eTrabajo* trabajo, int tam)
{
    int i;

    for (i=0; i<tam; i++)
    {
        trabajo[i].idTrabajo = -1;
        trabajo[i].isEmpty = 0;
    }
}

int trabajo_searchFree (eTrabajo* unTrabajo, int size)
{
    int i;
    int index = -1;

    for (i=0; i<size; i++)
    {
        if (unTrabajo[i].idTrabajo == -1)
        {
            index = i;
            break;
        }
    }
    return index;
}

int trabajo_getDate(eTrabajo* unTrabajo, int size)
{
	int rtn = 0;
	int dia;
	int mes;
	int anio;

	Get_IntMinMax("ingrese dia:\n", "ERROR. ingrese dia:\n", 1, 31, &dia);
	Get_IntMinMax("ingrese mes:\n", "ERROR. ingrese mes:\n", 1, 12, &mes);
	Get_IntMinMax("ingrese año:\n", "ERROR. ingrese año:\n", 1980, 2021, &anio);
	printf("dia: %d\n", dia);
	printf("mes: %d\n", mes);
	printf("anio: %d\n", anio);
	unTrabajo->fecha.dia = dia;
	unTrabajo->fecha.mes = mes;
	unTrabajo->fecha.anio = anio;
	rtn = 1;

	return rtn;
}

int trabajo_validarId(eTrabajo* unTrabajo, int size, int auxId)
{
    int rtn = 0;
    int i;

    for (i=0; i<size; i++)
    {
        if (unTrabajo[i].idTrabajo == auxId)
        {
            rtn = auxId;
            break;
        }
    }
    return rtn;
}

int trabajo_buscarIndexPorId(eTrabajo* listaTrabajos, int size, int id)
{
    int i;
    int index;

    index = -1;

    for (i=0; i<size; i++)
    {
        if (listaTrabajos[i].idTrabajo == id)
        {
            index = i;
            break;
        }
    }
    return index;
}

void trabajo_clonarListaTrabajos(eTrabajo* listaTrabajos, int size1, eTrabajo* auxListaTrabajos, int size2)
{
	int i;

	for (i=0; i<size1; i++)
	{
		auxListaTrabajos[i] = listaTrabajos[i];
	}
}
