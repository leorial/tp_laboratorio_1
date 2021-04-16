/*
 ============================================================================
Rial Leonardo.
DNI 35994816
Division 1F
=============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "dataIO.h"
#include "operaciones.h"
#include "validacion.h"

#define COLOR_RED     "\x1b[31m"
#define COLOR_RESET   "\x1b[0m"


int main(void)
{
	setbuf(stdout, NULL);

	int opcion;
	float primerNumero;
	float segundoNumero;
	float resultadoSuma;
	float resultadoResta;
	float resultadoDivision;
	float producto;
	int factorialA;
	int factorialB;
	int validadorFlotante;
	int flagOpcionIngresada;
	int verificadorCero;

	flagOpcionIngresada = 0;

	do
	{
		system("cls");
		printf ("\n\nMENU: \n");
		printf ("1. Ingresar 1er operando.\n");
		printf ("2. Ingresar 2do operando.\n");
		printf ("3. Calcular todas las operaciones.\n");
		printf ("4. Informar resultados.\n");
		printf ("5. Salir.\n");
		if (flagOpcionIngresada > 0)
		{
			printf ("\nPrimer numero ingresado: %.2f\n", primerNumero);
		}
		if (flagOpcionIngresada > 1 )
		{
			printf ("Segundo numero ingresado: %.2f\n", segundoNumero);
		}
		opcion = Get_IntMinMax ("\ningrese una opcion: \n", COLOR_RED "ERROR. Ingrese una opcion valida: \n"COLOR_RESET, 1, 5);

		switch (opcion)
		{
			case 1 :
			{
				primerNumero = Get_Float ("ingrese el primer numero: \n", "ERROR. ingrese el primer numero: \n ");
				flagOpcionIngresada++;
				printf ("Usted ha ingresado el primer operando.\n");
				system("PAUSE");
				break;
			}
			case 2 :
			{
				if (flagOpcionIngresada < 1)
				{
					printf (COLOR_RED"SILLAZO!! aun no ha ingresado el primer operando. por fvor elija una opcion correcta.\n"COLOR_RESET);
					system("PAUSE");
					break;
				}
				segundoNumero = Get_Float ("ingrese el segundo numero: \n", "ERROR. ingrese el segundo numero: \n ");
				flagOpcionIngresada++;
				printf ("Usted ha ingresado el segundo operando.\n");
				system("PAUSE");
				break;
			}
			case 3 :
			{
				if (flagOpcionIngresada < 2)
				{
					printf (COLOR_RED"SILLAZO!! aun no ha ingresado todos los datos requeridos. por favor ingrese una opcion correcta.\n"COLOR_RESET);
					system("PAUSE");
					break;
				}
				resultadoSuma = SumarFloat (primerNumero, segundoNumero);
				resultadoResta = RestarFloat (primerNumero, segundoNumero);
				resultadoDivision = DividirFloat (primerNumero, segundoNumero);
				producto = MultiplicarFloat (primerNumero, segundoNumero);
				validadorFlotante = Validate_IntPositive (primerNumero);
				factorialA = Validate_Factorial (validadorFlotante, primerNumero);
				validadorFlotante = Validate_IntPositive (segundoNumero);
				factorialB = Validate_Factorial (validadorFlotante, segundoNumero);
				verificadorCero = Validate_Zero (segundoNumero);
				flagOpcionIngresada += 4;
				printf ("Se estan realizando los calculos.\n");
				system("PAUSE");
				break;
			}
			case 4 :
			{
				if (flagOpcionIngresada < 3)
				{
					printf (COLOR_RED"SILLAZO!! aun no ha ingresado todos los datos requeridos. por favor ingrese una opcion correcta.\n"COLOR_RESET);
					system("PAUSE");
					break;
				}
				Show_Results ("La suma de los numeros ingresados es:", resultadoSuma,
						      "La resta de los numeros ingresados es:", resultadoResta,
							  "el primero numero ingresado dividido por el segundo es:", resultadoDivision, verificadorCero,
							  "la multiplicacion de ambos numeros ingresados da como resultado:", producto );
				Show_Factorial (factorialA, factorialB);
				flagOpcionIngresada=0;
				primerNumero=0;
				segundoNumero=0;
				system("PAUSE");
				break;
			}
			case 5 :
			{
				printf ("Cerrando calculadora...\n");
				system("PAUSE");
				break;
			}
		}

	}while (opcion != 5);

}


