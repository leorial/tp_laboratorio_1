
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"
#include "eVuelos.h"
#include "ePilotos.h"
#include "menu.h"
#include "../inc/LinkedList.h"
#include "input.h"
//#include "../testing/inc/main_test.h"

int main(void)
{
	setbuf(stdout, NULL);
	LinkedList* listaVuelos = ll_newLinkedList();
	LinkedList* listaPilotos = ll_newLinkedList();
	char archivoVuelos[50];
	char archivoPilotos[50];
	int option;
	int flagControl = 0;

	do
	{
		menuPrincipal();
		Get_IntMinMax("ingrese la opcion deseada.\n", "ERROR. ingrese una opcion valida:\n", 1, 9, &option);
		switch (option)
		{
			case 1:
				Get_String("ingrese el nombre del archivo a leer:\n", "error. ingrese el nombre del archivo a leer:\n", archivoPilotos, 50);
				controller_loadPilotosFromText(archivoPilotos, listaPilotos);
				break;

			case 2:
				Get_String("ingrese el nombre del archivo a leer\n", "error. ingrese el nombre del archivo a leer\n", archivoVuelos, 50);
				controller_loadVuelosFromText(archivoVuelos, listaVuelos);
				break;

			case 3:
				controller_ListVuelos(listaVuelos, listaPilotos);
				break;

			case 4:
				controller_CounterPassengers(listaVuelos);
				break;

			case 5:
				controller_CounterPassengersToChina(listaVuelos);
				break;

			case 6:
				controller_FilterLongFlys(listaVuelos);
				break;

			case 7:
				controller_ListFlysToPortugal(listaVuelos, listaPilotos);
				break;

			case 8:
				controller_listFlysLessPilots(listaVuelos, listaPilotos);
				break;

			case 9:
	            	if (Validate_YesOrNo ("esta seguro que desea salir? s/n\n", "ERROR. ingrese una opcion valida. s/n:\n"))
	            	{
	            		option = 0;
	            	}
					break;
		}

	}while (option != 0);

	controller_ProgramDown(listaPilotos, listaVuelos);

	return 0;
}

































