#include "eFactura.h"
#include <stdio.h>
#include <stdlib.h>
#include "input.h"


int factura_searchIndexById(eFactura* unaFactura, int size, int id)
{
	int rtn = -1;
	int i;

	for (i=0; i<size; i++)
	{
		if (unaFactura[i].idFactura == id)
		{
			rtn = i;
		}
	}
	return rtn;
}

void factura_listarFacturas(eFactura* listaFacturas, int size)
{
	int i;

	printf ("idFactura  TipoDeFactura  MedioDePago \n");
	for (i=0; i<size; i++)
	{
		factura_mostrarUnaFactura(listaFacturas, i);
	}
}

void factura_mostrarUnaFactura (eFactura* unaFactura, int index)
{
	printf ("%d    %s    %s\n", unaFactura[index].idFactura, unaFactura[index].tipoFactura, unaFactura[index].medioDePago);
}

int factura_getIdFactura(eFactura* listaFacturas, int size4)
{
	int rtn = -1;
	int idFactura;
	int flagError = 0;
	int i;

	while (flagError <= 3)
	{
		Get_Int("ingrese un id de factura de la lista:\n", "ERROR. el id debe ser numerico. ingrese un id de factura de la lista:\n", &idFactura);
		for(i=0; i<size4; i++)
		{
			if (idFactura == listaFacturas[i].idFactura)
			{
				flagError = 3;
				rtn = idFactura;
				break;
			}
		}
		flagError++;
	}
	return rtn;
}
