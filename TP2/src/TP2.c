/*
 ============================================================================
 Name        : TP2.c
 Author      : Rial Leonardo
 Version     :
 Copyright   : Your copyright notice
 Description : Laboratorio Trabajo Practico 2
 ============================================================================
 */
#include "menu.h"

int main(void)
{
	setbuf(stdout, NULL);

	Employee listaEmpleados[1000];

	initEmployees(listaEmpleados, 1000);

	Show_Menu(listaEmpleados, 1000);
}
