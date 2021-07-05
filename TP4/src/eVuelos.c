#include "eVuelos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


eVuelo* NewVuelo()
{
	eVuelo* unVuelo;

	unVuelo = (eVuelo*)malloc(sizeof(eVuelo));

	return unVuelo;
}

eVuelo* vuelo_NewParametros(char* idVueloStr, char* idAvionStr,char* idPilotoStr,char* diaStr,char* mesStr,char* anioStr,char* destinoStr,char* cantPasajerosStr,char* horaDespegueStr,char* horaLlegadaStr)
{
	eVuelo* unVuelo;
	int auxIdVuelo;
	int auxIdAvion;
	int auxIdPiloto;
	int auxDia;
	int auxMes;
	int auxAnio;
	int auxCantPasajeros;
	int auxHoraDespegue;
	int auxHoraLlegada;

	unVuelo = NewVuelo();

	if (unVuelo != NULL)
	{
		auxIdVuelo = atoi(idVueloStr);
		auxIdAvion = atoi(idAvionStr);
		auxIdPiloto = atoi(idPilotoStr);
		auxDia = atoi(diaStr);
		auxMes = atoi(mesStr);
		auxAnio = atoi(anioStr);
		auxCantPasajeros = atoi(cantPasajerosStr);
		auxHoraDespegue = atoi(horaDespegueStr);
		auxHoraLlegada = atoi(horaLlegadaStr);

		vuelo_SetIdVuelo(unVuelo, &auxIdVuelo);
		vuelo_SetIdPiloto(unVuelo, &auxIdPiloto);
		vuelo_SetIdAvion(unVuelo, &auxIdAvion);
		vuelo_SetFecha(unVuelo, &auxDia, &auxMes, &auxAnio);
		vuelo_SetDestino(unVuelo, destinoStr);
		vuelo_SetCantPasajeros(unVuelo, &auxCantPasajeros);
		vuelo_SetHoraDespegue(unVuelo, &auxHoraDespegue);
		vuelo_SetHoraLlegada(unVuelo, &auxHoraLlegada);
	}
	return unVuelo;
}

int vuelo_SetIdVuelo(eVuelo* this, int* IdVuelo)
{
	int rtn = 0;

	if (IdVuelo > 0 && IdVuelo != NULL)
	{
		this->idVuelo = *IdVuelo;
		rtn = 1;
	}
	return rtn;
}

int vuelo_SetIdAvion(eVuelo* this, int* IdAvion)
{
	int rtn = 0;

	if (IdAvion > 0 && IdAvion != NULL)
	{
		this->idAvion = *IdAvion;
		rtn = 1;
	}
	return rtn;
}

int vuelo_SetIdPiloto(eVuelo* this, int* IdPiloto)
{
	int rtn = 0;

	if (IdPiloto > 0 && IdPiloto != NULL)
	{
		this->idPiloto = *IdPiloto;
		rtn = 1;
	}
	return rtn;
}

int vuelo_SetFecha(eVuelo* this, int* dia, int* mes, int* anio)
{
	int rtn = 0;

	if (this != NULL)
	{
		this->fecha.dia = *dia;
		this->fecha.mes = *mes;
		this->fecha.anio = *anio;
		rtn = 1;
	}
	return rtn;
}

int vuelo_SetDestino(eVuelo* this, char* destino)
{
	int rtn = 0;

	if (this != NULL)
	{
		strcpy (this->destino, destino);
		rtn = 1;
	}
	return rtn;

}

int vuelo_SetCantPasajeros(eVuelo* this, int* CantPasajeros)
{
	int rtn = 0;

	if (CantPasajeros > 0 && CantPasajeros != NULL)
	{
		this->cantPasajeros = *CantPasajeros;
		rtn = 1;
	}
	return rtn;
}

int vuelo_SetHoraDespegue(eVuelo* this, int* HoraDespegue)
{
	int rtn = 0;

	if (HoraDespegue != NULL)//(HoraDespegue >= 0 && HoraDespegue < 24 && HoraDespegue != NULL)
	{
		this->horaDespegue = *HoraDespegue;
		rtn = 1;
	}
	return rtn;
}

int vuelo_SetHoraLlegada(eVuelo* this, int* HoraLlegada)
{
	int rtn = 0;

	if (HoraLlegada != NULL)//(HoraLlegada >= 0 && HoraLlegada < 24 && HoraLlegada != NULL)
	{
		this->horaLlegada = *HoraLlegada;
		rtn = 1;
	}
	return rtn;
}

int vuelo_GetIdVuelo(eVuelo* this, int* IdVuelo)
{
	int rtn = 0;

	if (this != NULL && IdVuelo != NULL)
	{
		*IdVuelo = this->idVuelo;
		rtn = 1;
	}
	return rtn;
}

int vuelo_GetIdAvion(eVuelo* this, int* IdAvion)
{
	int rtn = 0;

	if (this != NULL && IdAvion != NULL)
	{
		*IdAvion = this->idAvion;
		rtn = 1;
	}
	return rtn;
}

int vuelo_GetIdPiloto(eVuelo* this, int* IdPiloto)
{
	int rtn = 0;

	if (this != NULL && IdPiloto != NULL)
	{
		*IdPiloto = this->idPiloto;
		rtn = 1;
	}
	return rtn;
}

int vuelo_GetDia(eVuelo* this, int* dia)
{
	int rtn = 0;

	if (dia != NULL && this != NULL)
	{
		*dia = this->fecha.dia;
		rtn = 1;
	}
	return rtn;
}

int vuelo_GetMes(eVuelo* this, int* mes)
{
	int rtn = 0;

	if (mes != NULL && this != NULL)
	{
		*mes = this->fecha.mes;
		rtn = 1;
	}
	return rtn;
}

int vuelo_GetAnio(eVuelo* this, int* anio)
{
	int rtn = 0;

	if (anio != NULL && this != NULL)
	{
		*anio = this->fecha.anio;
		rtn = 1;
	}
	return rtn;
}

int vuelo_GetDestino(eVuelo* this, char* destino)
{
	int rtn = 0;

	if (this != NULL && destino != NULL)
	{
		strcpy (destino, this->destino);
		rtn = 1;
	}
	return rtn;

}

int vuelo_GetCantPasajeros(eVuelo* this, int* CantPasajeros)
{
	int rtn = 0;

	if (this != NULL && CantPasajeros != NULL)
	{
		*CantPasajeros = this->cantPasajeros;
		rtn = 1;
	}
	return rtn;
}

int vuelo_GetHoraDespegue(eVuelo* this, int* HoraDespegue)
{
	int rtn = 0;

	if (this != NULL && HoraDespegue != NULL)
	{
		*HoraDespegue = this->horaDespegue;
		rtn = 1;
	}
	return rtn;
}

int vuelo_GetHoraLlegada(eVuelo* this, int* HoraLlegada)
{
	int rtn = 0;

	if (this != NULL && HoraLlegada != NULL)
	{
		*HoraLlegada = this->horaLlegada;
		rtn = 1;
	}
	return rtn;
}

int vuelo_CountPassengers(void* element)
{
	int rtn = 0;
	eVuelo* unVuelo;

	if (element != NULL)
	{
		unVuelo = (eVuelo*)element;
		vuelo_GetCantPasajeros(unVuelo, &rtn);
	}
	return rtn;
}

int vuelo_CountPassengersToChina(void* element)
{
	int rtn = 0;
	eVuelo* unVuelo;
	char destino[30];

	if (element != NULL)
	{
		unVuelo = (eVuelo*)element;
		vuelo_GetDestino(unVuelo, destino);
		if (strcmp(destino, "China") == 0)
		{
			vuelo_GetCantPasajeros(unVuelo, &rtn);
		}
	}
	return rtn;
}

int vuelo_FiltrarVuelosLargos(void* element)
{
	int rtn = 0;
	eVuelo* unVuelo;
	int horaLlegada;
	int horaDespegue;
	int lapsoDeVuelo;

	if (element != NULL)
	{
		unVuelo = (eVuelo*)element;
		vuelo_GetHoraLlegada(unVuelo, &horaLlegada);
		vuelo_GetHoraDespegue(unVuelo, &horaDespegue);
		lapsoDeVuelo = horaDespegue - horaLlegada;

		if (lapsoDeVuelo >= 5 || lapsoDeVuelo <= -5 )
		{
			rtn = 1;
		}
	}
	return rtn;
}

int vuelo_FiltrarVuelosAPortugal(void* element)
{
	int rtn = 0;
	eVuelo* unVuelo;
	char destino[30];

	if (element != NULL)
	{
		unVuelo = (eVuelo*)element;
		vuelo_GetDestino(unVuelo, destino);
		if (strcmp(destino, "Portugal") == 0)
		{
			rtn = 1;
		}
	}
	return rtn;
}

int vuelo_FiltrarPilotos(void* element)
{
	int rtn = 0;
	eVuelo* unVuelo;
	int id;

	if (element != NULL)
	{
		unVuelo = (eVuelo*)element;
		vuelo_GetIdPiloto(unVuelo, &id);
		if (id != 1 && id != 2)
		{
			rtn = 1;
		}
	}
	return rtn;
}
