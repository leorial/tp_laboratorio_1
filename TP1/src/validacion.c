/*
 * validacion.c
 *
 *  Created on: 28 mar. 2021
 *      Author: Leo
 */
#include "validacion.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>



int Validate_IntPositive (float numero)
{
	int entero;
	float validador;

	entero = numero;

	validador = numero - entero;

	if (validador != 0 || numero < 0)
	{
		validador = 1;
	}

	return validador;
}

int Validate_Factorial (int validador, float numero)
{
	int factorial;

	if (validador == 0 && numero > 1)
	{
		factorial = FactorizarInt (numero);
	}
	else
	{
		if (validador == 0 && (numero == 1 || numero == 0))
		{
			factorial = 1;
		}
		else
		{
			factorial = -1;
		}
	}
	return factorial;
}

int Validate_Zero (float numero)
{
	int rtn;
	rtn = 1;

	if (numero == 0)
	{
		rtn = 0;
	}

	return rtn;
}
