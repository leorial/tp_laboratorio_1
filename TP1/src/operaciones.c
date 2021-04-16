/*
 * operaciones.c
 *
 *  Created on: 25 mar. 2021
 *      Author: Leo
 */

#include "operaciones.h"



float SumarFloat (float numero1, float numero2)
{
	float resultado;

	resultado = numero1 + numero2;

	return resultado;
}

float RestarFloat (float numero1, float numero2)
{
	float resultado;

	resultado = numero1 - numero2;

	return resultado;
}

float DividirFloat (float numero1, float numero2)
{
	float resultado;

	resultado = numero1 / numero2;

	return resultado;
}

int FactorizarInt (int numero)
{
	int resultado;

    if (numero>1)
    {
    	int i;

    	resultado = 1;

    	for (i=numero ; i>1 ; i--)
    	{
    		resultado=resultado*i;
    	}
    }
    else
    {
    	if (numero == 1 || numero == 0)
    	{
    		resultado = 1;
    	}

    	else
    	{
    		resultado = 0;
    	}
    }

    return resultado;
}

float MultiplicarFloat (float numero1, float numero2)
{
	float resultado;

	resultado = numero1 * numero2;

	return resultado;
}

