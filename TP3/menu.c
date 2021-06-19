#include "menu.h"

void Show_Menu ()
{
	printf ("     ******************************\n");
	printf ("     *                            *\n");
	printf ("     *   MENU DE CARGA DE DATOS   *\n");
	printf ("     *                            *\n");
	printf ("     ******************************\n\n");
	printf (" 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
	printf (" 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
	printf (" 3. Alta de empleado\n");
	printf (" 4. Modificar datos de empleado\n");
	printf (" 5. Baja de empleado\n");
	printf (" 6. Listar empleados\n");
	printf (" 7. Ordenar empleados\n");
	printf (" 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
	printf (" 9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
	printf (" 10. Salir\n");
}

void Show_SubMenuOrdenamiento ()
{
	printf (" Sub-Menu de ordenamiento\n ");
	printf (" 1. Ordenar por ID\n ");
	printf (" 2. Ordenar por NOMBRE\n ");
	printf (" 3. Ordenar por Horas Trabajadas\n ");
	printf (" 4. Ordenar por Sueldo\n ");
}
