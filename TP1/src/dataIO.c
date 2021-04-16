/*
 * dataIO.c
 *
 *  Created on: 24 mar. 2021
 *      Author: Leo Rial
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "dataIO.h"
#include <math.h>

#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"
#define COLOR_RED     "\x1b[31m"

int Get_Int (char message[], char errorMessage[])
{
	char auxiliar[256];
	int result;

	printf ("%s", message);
	fflush(stdin);
	scanf("%s", auxiliar);

	while (Validate_Int(auxiliar) == 0)
	{
		printf("%s", errorMessage);
		fflush(stdin);
		scanf("%s", auxiliar);
	}

	result = atoi(auxiliar);

	return result;
}


int Validate_Int (char numero[])
{
	int i;
	int result;
	int flagSign;

	flagSign = 0;

	result = 1;

	for (i=0; i<strlen(numero); i++)
	{
		if (numero[i] == '-')
		{
			flagSign++;
		}
		if((!isdigit(numero[i]) && numero[i] != '-') || flagSign > 1)
		{
			result = 0;
			break;
		}
	}
	return result;
}

float Get_Float (char message[], char errorMessage[])
{
	char auxiliar[256];
	float result;

	printf ("%s", message);
	fflush(stdin);
	scanf("%s", auxiliar);

	while (Validate_Float(auxiliar) == 0)
	{
		printf("%s", errorMessage);
		fflush(stdin);
		scanf("%s", auxiliar);
	}

	result = atof(auxiliar);

	return result;
}

float Validate_Float (char numero[])
{
	int i;
	float result;
	int flag;
	int flagMinus;


	flagMinus = 0;
	flag = 0;
	result = 1;

	for (i=0; i<strlen(numero); i++)
	{
		if(!isdigit(numero[i]) && numero[i] != '.' && numero[i] != '-')
		{
			result = 0;
			break;
		}
		else
		{
			if(numero[i] == '.')
			{
				flag++;
			}
		}
		if(flag>1)
		{
			result = 0;
			break;
		}

		if(numero[i]== '-')
		{
			flagMinus++;
		}
		if(flagMinus > 1)
		{
			result = 0;
			break;
		}
	}
	return result;
}

int Get_IntMinMax (char message[], char errorMessage[], int min, int max)
{
	char auxiliar[256];
	int result;

	printf ("%s", message);
	fflush(stdin);
	scanf("%s", auxiliar);

	while (Validate_IntMinMax(auxiliar, min, max) == 0)
	{
		printf("%s", errorMessage);
		fflush(stdin);
		scanf("%s", auxiliar);
	}

	result = atoi(auxiliar);



	return result;
}

int Validate_IntMinMax (char numero[], int min, int max)
{
	int i;
	int result;
	int flagMinus;
	int entero;

	flagMinus = 0;

	result = 1;

	for (i=0; i<strlen(numero); i++)
	{
		if(!isdigit(numero[i]) && numero[i] != '-')
		{
			result = 0;
			break;
		}
		else
		{
			if(numero[i]== '-')
			{
				flagMinus++;
			}
		}
		if(flagMinus > 1)
		{
			result = 0;
			break;
		}

		entero = atoi(numero);

		if(entero>max || entero<min)
		{
			result = 0;
			break;
		}
	}
	return result;
}

void Show_Results (char mensajeSuma[], float suma, char mensajeResta[], float resta, char mensajeDivision[], float division, int validador, char mensajeMultiplicacion[], float multiplicacion)
{
	printf (COLOR_YELLOW"%s %.2f \n"COLOR_RESET, mensajeSuma, suma);
	printf (COLOR_GREEN"%s %.2f \n"COLOR_RESET, mensajeResta, resta);
	if (validador == 0)
	{
		printf (COLOR_BLUE"no se puede realizar una division por 0.\n"COLOR_RESET);
	}
	else
	{
		printf (COLOR_BLUE"%s %.2f \n"COLOR_RESET, mensajeDivision, division);
	}
	printf (COLOR_MAGENTA"%s %.2f \n"COLOR_RESET, mensajeMultiplicacion, multiplicacion);
}

void Show_Factorial (int factorialA, int factorialB)
{
	if (factorialA > 0)
	{
		printf (COLOR_CYAN"el factorial del primer numero ingresado es: %d \n"COLOR_RESET, factorialA);
	}
	else
	{
		printf (COLOR_RED"no se puede calcular el factorial del primer numero ingresado.\n"COLOR_RESET);
	}
	if (factorialB > 0)
	{
		printf (COLOR_CYAN"el factorial del segundo numero ingresado es: %d \n"COLOR_RESET, factorialB);
	}
	else
	{
		printf (COLOR_RED"no se puede calcular el factorial del segundo numero ingresado.\n"COLOR_RESET);
	}
}







