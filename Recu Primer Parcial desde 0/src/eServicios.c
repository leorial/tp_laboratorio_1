#include "eServicios.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int servicio_searchIndexById(eServicio* unServicio, int size, int id)
{
	int rtn = -1;
	int i;

	for (i=0; i<size; i++)
	{
		if (unServicio[i].id == id)
		{
			rtn = i;
		}
	}
	return rtn;
}

void servicio_listarServicios(eServicio* listaServicios, int size)
{
	int i;

	printf ("idServicio  Descripcion  Precio \n");
	for (i=0; i<size; i++)
	{
		servicio_mostrarUnServicio(listaServicios, i);
	}
}

void servicio_mostrarUnServicio (eServicio* unServicio, int index)
{
	printf ("%d  %s  %f\n", unServicio[index].id, unServicio[index].descripcion, unServicio[index].precio);
}

int servicio_getIdServicio(eServicio* listaServicios, int size3)
{
	int rtn = -1;
	int idServicio;
	int flagError = 0;
	int i;

	while (flagError <= 3)
	{
		Get_Int("ingrese un id de servicio de la lista:\n", "ERROR. el id debe ser numerico. ingrese un id de servicio de la lista:\n", &idServicio);
		for(i=0; i<size3; i++)
		{
			if (idServicio == listaServicios[i].id)
			{
				flagError = 3;
				rtn = idServicio;
				break;
			}
		}
		flagError++;
	}
	return rtn;
}

int servicio_validarId(eServicio* unServicio, int size, int auxId)
{
    int rtn = 0;
    int i;

    for (i=0; i<size; i++)
    {
        if (unServicio[i].id == auxId)
        {
            rtn = auxId;
            break;
        }
    }
    return rtn;
}

void auxServicio_inicializarEstructuraAuxiliar(eServicio* unServicio, int size, eAuxServicio* auxServicio, int size2)
{
	int i;

	for (i=0; i<size; i++)
	{
		auxServicio[i].id = unServicio[i].id;
		strcpy (auxServicio[i].descripcion, unServicio[i].descripcion);
		auxServicio[i].precio = unServicio[i].precio;
		auxServicio[i].contadorTrabajos = 0;
	}
}

void auxServicio_mostrarMayorContadorServicios(eAuxServicio* auxListaServicios, int size3)
{
	int i;
	int mayorContador = 0;

	for (i=0; i<size3; i++)
	{
		if (i==0 || auxListaServicios[i].contadorTrabajos > mayorContador)
		{
			mayorContador = auxListaServicios[i].contadorTrabajos;
		}
	}
	printf("El/Los servicios mas realizados es/son:\n");
	for (i=0; i<size3; i++)
		{
			if (auxListaServicios[i].contadorTrabajos == mayorContador)
			{
				printf("-%s: %d\n", auxListaServicios[i].descripcion, auxListaServicios[i].contadorTrabajos);
			}
		}
}
