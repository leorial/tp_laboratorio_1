#include "ePilotos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


ePilotos* NewPiloto()
{
	ePilotos* unPiloto;

	unPiloto = (ePilotos*)malloc(sizeof(ePilotos));

    return unPiloto;
}

ePilotos* piloto_NewParametros(char* idPilotosStr, char* nombreStr)
{
	ePilotos* unPiloto;
	int auxIdPilotos;

	unPiloto = NewPiloto();

	if (unPiloto != NULL)
	{
		auxIdPilotos = atoi(idPilotosStr);
		piloto_setId(unPiloto, &auxIdPilotos);
		piloto_setNombre(unPiloto, nombreStr);
	}
	return unPiloto;
}

int piloto_setId(ePilotos* this, int* id)
{
	int rtn = 0;

	if (id > 0 && this != NULL)
	{
		this->idPiloto = *id;
		rtn = 1;
	}
	return rtn;
}

int piloto_setNombre(ePilotos* this, char* nombre)
{
	int rtn = 0;

	if (this != NULL)
	{
		strcpy (this->nombre, nombre);
		rtn = 1;
	}
	return rtn;
}

int piloto_getId(ePilotos* this, int* id)
{
	int rtn = 0;

	if (id != NULL && this != NULL)
	{
		*id = this->idPiloto;
		rtn = 1;
	}
	return rtn;
}

int piloto_getNombre(ePilotos* this, char* nombre)
{
	int rtn = 0;

	if (this != NULL && nombre != NULL)
	{
		strcpy (nombre, this->nombre);
		rtn = 1;
	}
	return rtn;
}


