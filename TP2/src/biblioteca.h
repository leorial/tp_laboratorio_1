#include "employee.h"
#include "input.h"

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_
/**
 * @fn void Start_Array (eTrabajo[], int)
 * @brief inicializa cierto datos de un array de estructura
 * @param Employee recibe un array de estructura
 * @param int recibe un entero como tamaño del array
 */
void initEmployees (Employee*, int);

/**
 * @fn void addEmployees(Employee[], int, int)
 * @brief agrega al array de estructura todos los datos de un empleado solicitandolos.
 * @param Employee array lista de empleados
 * @param int tamaño del array
 * @param int index en donde guardar el dato solicitado
 */
void addEmployees (Employee*, int, int);

/**
 * @fn int Search_Free(Employee[], int)
 * @brief busca un indice del array en donde no se haya guardado datos aun.
 * @param Employee array lista de empleados
 * @param int tamaño de array
 * @return retorna como entero el indice del array en donde aun no se cargaron datos
 */
int Search_Free (Employee*, int);

/**
 * @fn int findEmployeeById(char[], char[], Employee[], int)
 * @brief busca el indice de un empleado por el id del mismo
 * @param char mensaje solicitando id a buscar
 * @param char mensaje de error
 * @param Employee array lista de empleados
 * @param int tamaño de array
 * @return retorna como entero el indice del id buscado
 */
int findEmployeeById (char*, char*, Employee*, int);

/**
 * @fn void printEmployees(Employee[], int)
 * @brief imprime en pantalla todo el array de empleados cargados
 * @param Employee array lista de empleados
 * @param int tamaño de array
 */
void printEmployees (Employee*, int);

/**
 * @fn void printOneEmployee(Employee[], int, int)
 * @brief imprime en pantalla 1 indice del array de empleados
 * @param Employee array lista de empleados
 * @param int tamaño de array
 * @param int indice en el array a mostrar
 */
void printOneEmployee (Employee*, int, int);

/**
 * @fn int Modificate_Employees(Employee[], int)
 * @brief permite modificar datos de un empleado cargado
 * @param Employee array lista de empleados
 * @param int tamaño de array
 * @return retorna como entero 1 si se pudo realizar la modificacion y 0 si no se realizo
 */
int Modificate_Employees (Employee*, int);

/**
 * @fn int removeEmployee(Employee[], int)
 * @brief permite dar de baja un empleado cargado
 * @param Employee array lista de empleados
 * @param int tamaño de array
 * @return retorna como entero 1 si se pudo realizar la baja y 0 si no se realizo
 */
int removeEmployee (Employee*, int);

/**
 * @fn void Show_EmployeesByLastNameAndSector(Employee[], int)
 * @brief ordena y muestra la lista de empleados por apellido y por sector, de forma ascendente o dencendente a eleccion
 * @param Employee array lista de empleados
 * @param int tamaño de array
 */
void Show_EmployeesByLastNameAndSector (Employee*, int);

/**
 * @fn void Clone_Array(Employee[], int, Employee[], int)
 * @brief clona un array de estructura
 * @param Employee array lista de empleados
 * @param int tamaño de array
 * @param Employee array auxiliar de lista de empleados
 * @param int tamaño de array
 */
void Clone_Array (Employee*, int, Employee*, int);

/**
 * @fn void sortEmployees(Employee[], int, int)
 * @brief ordena la lista de empleados por apellido y por sector, de forma ascendente o dencendente
 * @param Employee array lista de empleados
 * @param int tamaño de array
 * @param int entero que demarca la forma en que se ordenada. 1 para ascendente y 2 para descendente
 */
void sortEmployees (Employee*, int, int);

/**
 * @fn void Show_AveregeAndTotalSalary(Employee[], int)
 * @brief calcula y muestra total de salarios, salario promedio y quienes superan dicho salario
 * @param Employee array lista de empleados
 * @param int tamaño de array
 */
void Show_AveregeAndTotalSalary (Employee*, int);


#endif /* BIBLIOTECA_H_ */
