
#include "menu.h"

void Show_Menu (Employee listaEmpleados[], int size)
{

	int opcion;
	int index;
	int flagMenu;

	flagMenu = 0;

	do
	{
		printf ("     ****************\n");
		printf ("     *     MENU     *\n");
		printf ("     ****************\n\n");
		printf ("1.  ALTA empleado\n");
		printf ("2.  MODIFICAR empleado\n");
		printf ("3.  BAJA empleado\n");
		printf ("4.  INFORMAR\n");
		printf ("0.  SALIR\n\n");

		opcion = Get_IntMinMax ("Seleccione una opcion: \n", "ERROR. Seleccione una opcion valida: \n", 0, 4);

		switch (opcion)
		{
				case 0:
				if (Validate_YesOrNo("Confirma que desea salir? S/N: \n", "ERROR! seleccione una opcion correcta. \nConfirma que desea salir? S/N: \n "))
		        {
					opcion = -1;
		        }
		        break;

		    case 1:
		        index = Search_Free (listaEmpleados, size);
		        if (index == -1)
		        {
		        	printf("No hay mas lugar para ingresar empleados.\n");
		        }
		        else
		        {
		        	addEmployees (listaEmpleados, size, index);
		        	flagMenu = 1;
		        }
		        break;

		    case 2:
		    	if (flagMenu == 1)
		        {
		    		if (Modificate_Employees (listaEmpleados, size) == 1)
		            {
		    			printf("el producto se modifico correctamente. \n");
		            }
		            else
		            {
		                printf("error. no se encontro el producto a modificar. \n");
		            }
		        }
		        else
		        {
		            printf("error. para seleccionar esta opcion primero debe cargar algun trabajo. \n");
		        }
		        break;

		    case 3:
		        if (flagMenu == 1)
		        {
		            if (removeEmployee(listaEmpleados, size) == 1)
		            {
		                printf("el producto se dio de baja correctamente. \n");
		            }
		            else
		            {
		                printf("error. no se encontro el producto a dar de baja. \n");
		            }
		        }
		        else
		        {
		            printf("error. para seleccionar esta opcion primero debe cargar algun trabajo. \n");
		        }
		        break;

		    case 4:
		        if (flagMenu == 1)
		        {
		        	Show_SubMenu(listaEmpleados, size);
		        }
		        else
		        {
		            printf("error. para seleccionar esta opcion primero debe cargar algun trabajo. \n");
		        }
		        break;
		}
	}while (opcion != -1);
}

void Show_SubMenu (Employee empleado[], int size)
{
	int opcion;

	do
	{
		printf ("     ***************\n");
		printf ("     *   SUBMENU   *\n");
		printf ("     ***************\n\n");
		printf ("1.  INFORMAR listado de empleados alfabeticamente por apellido y sector\n");
		printf ("2.  INFORMAR total, promedio de salarios y cuantos empleados superan el promedio\n");
		printf ("0.  SALIR\n\n");

		opcion = Get_IntMinMax ("Seleccione una opcion: \n", "ERROR. Seleccione una opcion valida: \n", 0, 2);

		switch (opcion)
		{
			case 0:
			if (Validate_YesOrNo("Confirma que desea salir? S/N: \n", "ERROR! seleccione una opcion correcta. \nConfirma que desea salir? S/N: \n "))
		    {
				opcion = -1;
		    }
		    break;

		    case 1:
		    	Show_EmployeesByLastNameAndSector (empleado, size);
		    	opcion = -1;
		    	break;

		    case 2:
		    	Show_AveregeAndTotalSalary (empleado, size);
		    	opcion = -1;
		    	break;
		}
	}while (opcion != -1);
}

