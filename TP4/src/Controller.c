#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eVuelos.h"
#include "ePilotos.h"
#include "parser.h"


int controller_loadVuelosFromText(char* path , LinkedList* pArrayListVuelos)
{
	int rtn = 0;
	FILE* pFile;

	if (path != NULL && pArrayListVuelos != NULL)
	{
		pFile = fopen (path, "r");

		if (pFile != NULL)
		{
			rtn = parser_VuelosFromText(pFile, pArrayListVuelos);
			printf("Archivo leido.\n");
		}
		else
		{
			printf("el archivo no existe.\n");
		}
		fclose (pFile);
	}
	else
	{
		printf ("LinkedList o Archivo invalidos.\n");
	}
    return rtn;
}

int controller_loadPilotosFromText(char* path , LinkedList* pArrayListPilotos)
{
	int rtn = 0;
	FILE* pFile;

	ll_clear(pArrayListPilotos);

	if (path != NULL && pArrayListPilotos != NULL)
	{
		pFile = fopen (path, "r");

		if (pFile != NULL)
		{
			rtn = parser_PilotosFromText(pFile, pArrayListPilotos);
			printf("Archivo leido.\n");
		}
		else
		{
			printf("el archivo no existe.\n");
		}
		fclose (pFile);
	}
	else
	{
		printf ("LinkedList o Archivo invalidos.\n");
	}
    return rtn;
}


int controller_PrintVuelo(eVuelo* this, LinkedList* pArrayPilotos)
{
	int rtn = 0;
	int idVuelo;
	int idAvion;
	int idPiloto;
	int dia;
	int mes;
	int anio;
	char destino[15];
	int cantPasajeros;
	int horaDespegue;
	int horaLlegada;
	int auxIdPiloto;
	char nombrePiloto[30];
	int i;
	ePilotos* unPiloto;

	if (this != NULL && pArrayPilotos != NULL)
	{
		vuelo_GetIdVuelo(this, &idVuelo);
		vuelo_GetIdAvion(this, &idAvion);
		vuelo_GetIdPiloto(this, &idPiloto);
		vuelo_GetDia(this, &dia);
		vuelo_GetMes(this, &mes);
		vuelo_GetAnio(this, &anio);
		vuelo_GetDestino(this, destino);
		vuelo_GetCantPasajeros(this, &cantPasajeros);
		vuelo_GetHoraDespegue(this, &horaDespegue);
		vuelo_GetHoraLlegada(this, &horaLlegada);

		for (i=0; i<ll_len(pArrayPilotos); i++)
		{
			unPiloto = (ePilotos*)ll_get(pArrayPilotos, i);
			piloto_getId(unPiloto, &auxIdPiloto);
			if (auxIdPiloto == idPiloto)
			{
				piloto_getNombre(unPiloto, nombrePiloto);
				break;
			}
		}
		printf("%3d %7d %*s %3d/%2d/%4d %*s       %d %15d %13d\n", idVuelo, idAvion, 21, nombrePiloto, dia, mes, anio, 9, destino, cantPasajeros, horaDespegue, horaLlegada);
		rtn = 1;
	}
	else
	{
		printf ("una de las listas que desea utilizar no existe.\n");
	}
	return rtn;
}


int controller_ListVuelos(LinkedList* pArrayVuelos, LinkedList* pArrayPilotos)
{
	int rtn = 0;
	eVuelo* unVuelo;
	int i;

	if (pArrayVuelos != NULL)
	{
		printf("IDvuelo   IDavion   NombrePiloto     Fecha      Destino   Cant.Pasajeros   HoraDespegue   HoraLlegada\n");
		for (i=0; i<ll_len(pArrayVuelos); i++)
		{
			unVuelo = (eVuelo*)ll_get(pArrayVuelos, i);
			if (unVuelo != NULL)
			{
				controller_PrintVuelo(unVuelo, pArrayPilotos);
				rtn = 1;
			}
		}
		printf("\n\n");
	}
	else
	{
		printf ("la lista que desea contar no existe.\n");
	}
	return rtn;
}

void controller_ProgramDown(LinkedList* pArrayVuelos, LinkedList* pArrayPilotos)
{
	ll_deleteLinkedList(pArrayVuelos);
	ll_deleteLinkedList(pArrayPilotos);
	printf ("programa finalizado.");
}

int controller_CounterPassengers(LinkedList* pArrayVuelos)
{
	int rtn = 0;
	int result;

	if (pArrayVuelos != NULL)
	{
		result = ll_count(pArrayVuelos, vuelo_CountPassengers);
		rtn = 1;
	}
	else
	{
		printf ("la lista que desea contar no existe.\n");
	}
	printf ("\nLa cantidad de pasajeros es de: %d\n\n\n", result);
	return rtn;
}

int controller_CounterPassengersToChina(LinkedList* pArrayVuelos)
{
	int rtn = 0;
	int result;

	if (pArrayVuelos != NULL)
	{
		result = ll_count(pArrayVuelos, vuelo_CountPassengersToChina);
		rtn = 1;
	}
	else
	{
		printf ("la lista que desea contar no existe.\n\n\n");
	}
	printf ("\nLa cantidad de pasajeros a China es de: %d\n", result);
	return rtn;
}

int controller_saveAsText(char* path , LinkedList* pArrayVuelos)
{
	FILE* pFile;
	eVuelo* unVuelo;
	int size;
	int i;
	int idVuelo;
	int idAvion;
	int idPiloto;
	int dia;
	int mes;
	int anio;
	char destino[15];
	int cantPasajeros;
	int horaDespegue;
	int horaLlegada;
	int rtn = 0;


	if (path != NULL && pArrayVuelos != NULL)
	{
		pFile = fopen(path, "w");

		if (pFile != NULL)
		{
			size = ll_len(pArrayVuelos);

			for (i=0; i<size; i++)
			{
				unVuelo = (eVuelo*)ll_get(pArrayVuelos, i);
				vuelo_GetIdPiloto(unVuelo, &idPiloto);
				vuelo_GetIdVuelo(unVuelo, &idVuelo);
				vuelo_GetIdAvion(unVuelo, &idAvion);
				vuelo_GetDia(unVuelo, &dia);
				vuelo_GetMes(unVuelo, &mes);
				vuelo_GetAnio(unVuelo, &anio);
				vuelo_GetDestino(unVuelo, destino);
				vuelo_GetCantPasajeros(unVuelo, &cantPasajeros);
				vuelo_GetHoraDespegue(unVuelo, &horaDespegue);
				vuelo_GetHoraLlegada(unVuelo, &horaLlegada);
				fprintf(pFile, "%d %d %d %d/%d/%d %s %d %d %d\n", idVuelo, idAvion, idPiloto, dia, mes, anio, destino, cantPasajeros, horaDespegue, horaLlegada);
			}
			fclose(pFile);
			rtn = 1;
		}
		else
		{
			printf ("no se pudo abrir archivo");
		}
	}
	else
	{
		printf ("LinkedList o Archivo invalidos");
	}
    return rtn;
}

int controller_FilterLongFlys(LinkedList* pArrayVuelos) //PUNTO 6
{
	int rtn = 0;
	LinkedList* listaVuelosLargos = ll_newLinkedList();
	if(listaVuelosLargos != NULL)
	{
		listaVuelosLargos = ll_filter(pArrayVuelos, vuelo_FiltrarVuelosLargos);
		controller_saveAsText("VuelosLargos.csv", listaVuelosLargos);
		rtn = 1;
	}
	return rtn;
}

int controller_ListFlysToPortugal (LinkedList* pArrayVuelos, LinkedList* pArrayPilotos) // PUNTO 7
{
	int rtn = 0;
	LinkedList* listaVuelosAPortugal = ll_newLinkedList();
	if(listaVuelosAPortugal != NULL)
	{
		listaVuelosAPortugal = ll_filter(pArrayVuelos, vuelo_FiltrarVuelosAPortugal);
		controller_ListVuelos(listaVuelosAPortugal, pArrayPilotos);
		rtn = 1;
	}
	return rtn;
}

int controller_listFlysLessPilots (LinkedList* pArrayVuelos, LinkedList* pArrayPilotos) // PUNTO 8
{
	int rtn = 0;
	LinkedList* listaVuelosMenosPilotos = ll_newLinkedList();
	if(listaVuelosMenosPilotos != NULL)
	{
		listaVuelosMenosPilotos = ll_filter(pArrayVuelos, vuelo_FiltrarPilotos);
		controller_ListVuelos(listaVuelosMenosPilotos, pArrayPilotos);
		rtn = 1;
	}
	return rtn;
}


