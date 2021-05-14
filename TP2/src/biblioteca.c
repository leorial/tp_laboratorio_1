#include "biblioteca.h"

void initEmployees(Employee empleados[], int size)
{
	int i;

	    for (i=0; i<size; i++)
	    {
	    	empleados[i].id = -1;
	    	empleados[i].isEmpty = 1;
	    }
}

void addEmployees (Employee empleados[], int size, int index)
{

	char auxString[51];

	index = Search_Free(empleados, size);

	empleados[index].id = Get_Int("Ingrese ID:\n", "Error. Dato invalido. Ingrese ID:\n");

	Get_String("Ingrese el nombre del empleado:\n", "Error. Ingrese el nombre del empleado:\n", auxString, 51);
	strcpy (empleados[index].name, auxString);

	Get_String("Ingrese el apellido del empleado:\n", "Error. Ingrese el apellido del empleado:\n", auxString, 51);
	strcpy (empleados[index].lastName, auxString);

	empleados[index].salary = Get_Float("Ingrese salario: \n", "ERROR. Ingrese salario: \n");

	empleados[index].sector = Get_Int("Ingrese numero de sector: \n", "ERROR. Ingrese numero de sector: \n");

	empleados[index].isEmpty = 0;
}

int Search_Free (Employee empleados[], int size)
{
    int i;
    int index;

    index = -1;

    for (i=0; i<size; i++)
    {
        if (empleados[i].id == -1)
        {
            index = i;
            break;
        }
    }
    return index;
}

int findEmployeeById (char message[], char messageError[], Employee empleado[], int size)
{
	int i;
	int id;
	int rtn;

	rtn = -1;

	id = Get_Int (message, messageError);

	for (i=0; i<size; i++)
	{
		if (empleado[i].id == id)
		{
			rtn = i;
			break;
		}
	}
	return rtn;
}

int Modificate_Employees (Employee empleado[], int size)
{
	int opcion;
	int index;
	int rtn;
	int auxInt;
	float auxFloat;
	char auxString[51];

	printEmployees (empleado, size);

	index = findEmployeeById ("Ingrese ID del empleado a modificar: \n", "ERROR. Ingrese ID del empleado a modificar: \n", empleado, size);

	if (index == -1)
	{
		rtn = index;
	}
	else
	{
		printOneEmployee (empleado, size, index);
		opcion = Get_IntMinMax ("Ingrese la opcion a modificar.\n 1- Nombre\n 2- Apellido\n 3- salario\n 4- sector\n ",
								"ERROR. Opcion incorrecta.\nIngrese la opcion a modificar.\n 1- Nombre\n 2- Apellido\n 3- salario\n 4- sector\n ",
								1, 4);

		switch (opcion)
		{
			case 1:
				Get_String("Ingrese nuevo nombre del empleado:\n", "Error. Ingrese nuevo nombre del empleado:\n", auxString, 51);
				printOneEmployee (empleado, size, index);
				if (Validate_YesOrNo("esta seguro que desea realizar el cambio? s/n \n", "ERROR. esta seguro que desea realizar el cambio? s/n \n"))
				{
					strcpy (empleado[index].name, auxString);
					rtn = 1;
				}
				else
				{
					rtn = 0;
				}
				break;

			case 2:
				Get_String("Ingrese nuevo apellido del empleado:\n", "Error. Ingrese nuevo apellido del empleado:\n", auxString, 51);
				printOneEmployee (empleado, size, index);
				if (Validate_YesOrNo("esta seguro que desea realizar el cambio? s/n \n", "ERROR. esta seguro que desea realizar el cambio? s/n \n"))
				{
					strcpy (empleado[index].lastName, auxString);
					rtn = 1;
				}
				else
				{
					rtn = 0;
				}
				break;

			case 3:
				auxFloat = Get_Float ("Ingrese nuevo salario del empleado:\n", "Error. Ingrese nuevo salario del empleado:\n");
				printOneEmployee (empleado, size, index);
				if (Validate_YesOrNo("esta seguro que desea realizar el cambio? s/n \n", "ERROR. esta seguro que desea realizar el cambio? s/n \n"))
				{
					empleado[index].salary = auxFloat;
					rtn = 1;
				}
				else
				{
					rtn = 0;
				}
				break;

			case 4:
				auxInt = Get_Int ("Ingrese nuevo sector del empleado:\n", "Error. Ingrese nuevo sector del empleado:\n");
				printOneEmployee (empleado, size, index);
				if (Validate_YesOrNo("esta seguro que desea realizar el cambio? s/n \n", "ERROR. esta seguro que desea realizar el cambio? s/n \n"))
				{
					empleado[index].sector = auxInt;
					rtn = 1;
				}
				else
				{
					rtn = 0;
				}
				break;
		}
	}
	return rtn;
}

void printEmployees (Employee empleados[], int size)
{
	int i;

	printf ("%4s   %10s   %10s   %8s   %3s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");

	for (i=0; i<size; i++)
	{
		if (empleados[i].isEmpty == 0 && empleados[i].id != -1)
		{
			printf ("%4d   %10s   %10s   %8.2f   %3d\n", empleados[i].id, empleados[i].name, empleados[i].lastName, empleados[i].salary, empleados[i].sector);
		}
	}
}

void printOneEmployee (Employee empleados[], int size, int index)
{
	printf ("%4s   %10s   %10s   %8s   %3s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
	printf ("%4d   %10s   %10s   %8.2f   %3d\n", empleados[index].id, empleados[index].name, empleados[index].lastName, empleados[index].salary, empleados[index].sector);
}

int removeEmployee (Employee empleado[], int size)
{
	int rtn;
	int index;

	printEmployees (empleado, size);

	index = findEmployeeById ("Ingrese ID del empleado a dar de baja: \n", "ERROR. Ingrese ID del empleado a dar de baja: \n", empleado, size);

	if (index == -1)
	{
		rtn = index;
	}
	else
	{
		printOneEmployee(empleado, size, index);
		if (Validate_YesOrNo("esta seguro que desea dar la baja? s/n \n", "ERROR. esta seguro que desea dar la baja? s/n \n"))
		{
			empleado[index].isEmpty = 1;
			rtn = 1;
		}
		else
		{
			rtn = 0;
		}
	}
	return rtn;
}

void Show_EmployeesByLastNameAndSector (Employee empleado[], int size)
{
	Employee auxEmpleado[1000];
	int opcion;

	Clone_Array (empleado, size, auxEmpleado, 1000);

	opcion = Get_IntMinMax ("seleccione el modo de ordenamiento:\n-1. Ascendente\n-2. Descendiente\n",
								"ERROR. seleccione el modo de ordenamiento:\n-1. Ascendente\n-2. Descendiente\n",
								1, 2);

	sortEmployees (auxEmpleado, size, opcion);

	printEmployees (auxEmpleado, size);
}

void sortEmployees (Employee auxEmpleado[], int size, int opcion)
{
	int i;
	int j;
	Employee auxiliar;

	for (i=0; i<size-1; i++)
	{
		for (j=i+1; j<size; j++)
		{
			if (opcion == 1 && auxEmpleado[i].isEmpty == 0 && auxEmpleado[j].isEmpty == 0)
			{
				if (strcmp(auxEmpleado[j].lastName, auxEmpleado[i].lastName)<=0)
				{
					auxiliar = auxEmpleado[i];
					auxEmpleado[i] = auxEmpleado[j];
					auxEmpleado[j] = auxiliar;
				}
				if (strcmp(auxEmpleado[j].lastName, auxEmpleado[i].lastName)==0)
				{
					if(auxEmpleado[j].sector < auxEmpleado[i].sector)
					{
						auxiliar = auxEmpleado[i];
						auxEmpleado[i] = auxEmpleado[j];
						auxEmpleado[j] = auxiliar;
					}
				}
			}

			else if (opcion == 2 && auxEmpleado[i].isEmpty == 0 && auxEmpleado[j].isEmpty == 0)
			{
				if (strcmp(auxEmpleado[j].lastName, auxEmpleado[i].lastName)>=0)
				{
					auxiliar = auxEmpleado[i];
					auxEmpleado[i] = auxEmpleado[j];
					auxEmpleado[j] = auxiliar;
				}
				if (strcmp(auxEmpleado[j].lastName, auxEmpleado[i].lastName)==0)
				{
					if(auxEmpleado[j].sector > auxEmpleado[i].sector)
					{
						auxiliar = auxEmpleado[i];
						auxEmpleado[i] = auxEmpleado[j];
						auxEmpleado[j] = auxiliar;
					}
				}
			}
		}
	}
}

void Clone_Array (Employee empleado[], int size, Employee auxEmpleado[], int size2)
{
	int i;

	for (i=0; i<size; i++)
	{
		auxEmpleado[i] = empleado[i];
	}
}

void Show_AveregeAndTotalSalary (Employee empleado[], int size)
{
	int i;
	int contadorSalarios;
	float acumuladorSalarios;
	float salarioPromedio;

	contadorSalarios = 0;
	acumuladorSalarios = 0;

	for (i=0; i<size; i++)
	{
		if (empleado[i].isEmpty == 0)
		{
			acumuladorSalarios+=empleado[i].salary;
			contadorSalarios++;
		}
	}

	salarioPromedio = acumuladorSalarios/contadorSalarios;

	printf ("Total de salarios: %.2f\nSalario promedio: %.2f\n", acumuladorSalarios, salarioPromedio);

	printf ("Los empleados que superan el salario promedio son: \n");

	for (i=0; i<size; i++)
	{
		if (empleado[i].salary > salarioPromedio)
		{
			printOneEmployee (empleado, size, i);
		}
	}

}


