#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eVuelos.h"
#include "ePilotos.h"



int parser_VuelosFromText(FILE* pFile, LinkedList* pArrayVuelos)
{
	eVuelo* vuelo;
	char rtn = 0;
	char idVuelo[5];
	char idAvion[5];
	char idPiloto[5];
	char dia[5];
	char mes[5];
	char anio[5];
	char destino[20];
	char cantPasajeros[5];
	char horaDespegue[5];
	char horaLlegada[5];

	if (pArrayVuelos != NULL && pFile != NULL)
	{
		fscanf (pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idVuelo, idAvion, idPiloto, dia, destino, cantPasajeros, horaDespegue, horaLlegada);
		do
		{
			fscanf (pFile, "%[^,],%[^,],%[^,],%[^/]/%[^/]/%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idVuelo, idAvion, idPiloto, dia, mes, anio, destino, cantPasajeros, horaDespegue, horaLlegada);
			vuelo = vuelo_NewParametros(idVuelo, idAvion, idPiloto, dia, mes, anio, destino, cantPasajeros, horaDespegue, horaLlegada);
			ll_add(pArrayVuelos, vuelo);
			rtn = 1;
		}while (!feof(pFile));
	}
	return rtn;
}

int parser_PilotosFromText(FILE* pFile, LinkedList* pArrayPilotos)
{
	int rtn;
	ePilotos* piloto;
	char idPiloto[5];
	char nombre[30];

	if (pArrayPilotos != NULL && pFile != NULL)
	{
		fscanf (pFile, "%[^,],%[^\n]\n", idPiloto, nombre);
		do
		{
			fscanf (pFile, "%[^,],%[^\n]\n", idPiloto, nombre);
			piloto = piloto_NewParametros(idPiloto, nombre);
			ll_add(pArrayPilotos, piloto);
			rtn = 1;
		}while (!feof(pFile));
	}
	return rtn;
}


