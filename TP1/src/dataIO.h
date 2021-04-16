/*
 * dataIO.h
 *
 *  Created on: 24 mar. 2021
 *      Author: Leo
 */

#include <stdio.h>

#ifndef DATAIO_H_
#define DATAIO_H_

/**
 * @fn int Get_Int(char[], char[])
 * @brief pide un numero entero y verifica que eso sea lo que se ingreso.
 * @param char mensaje solicitando el numero.
 * @param char mensaje de error volviendo a solicitar el numero.
 * @return int devuelve le numero entero ingresado.
 */
int Get_Int (char[], char[]);

/**
 * @fn float Get_Float(char[], char[])
 * @brief pide un numero flotante y verifica que eso sea lo que se ingreso.
 * @param char[] mensaje solicitando el numero.
 * @param char[] mensaje de error volviendo a solicitar el numero.
 * @return float devuelve le numero flotante ingresado.
 */
float Get_Float (char[], char[]);

/**
 * @fn int Get_IntMinMax(char[], char[], int, int)
 * @brief pide un numero entero, valida que eso sea lo ingresado y que este dentro del parametro de un minimo y un maximo.
 * @param char[] mensaje solicitando el numero.
 * @param char[] mensaje de error volviendo a solicitar el numero.
 * @param int numero entero minimo para parametros.
 * @param int numero entero maximo para parametros.
 * @return int retorna un numero entero entre un max y un min validado como tal.
 */
int Get_IntMinMax (char[], char[], int, int);

/**
 * @fn void Show_Results(char[], float, char[], float, char[], float, char[], float)
 * @brief recibe los resultados de las operaciones y los informa.
 * @param char[] mensaje informando la operacion que se realizo.
 * @param float variable con el resultado de la operacion cargada
 * @param int el entero recibido es una validador de 0.
 */
void Show_Results (char[], float, char[], float, char[], float, int, char[], float);

/**
 * @fn void Show_Factorial(int, int)
 * @brief recibe los resultados del factorial y los informa, se hayan podido hacer o no.
 * @param int numero entero resultado del primer factorial.
 * @param int numero entero resultado del segundo factorial.
 */
void Show_Factorial (int, int);

/**
 * @fn int Validate_Int(char[])
 * @brief recibe un numero en forma de String y lo valida para saber si es un entero.
 * @param char recibe un numero en forma de string
 * @return int retorna un numero entero. 1 si pasa la validacion de numero entero, caso contrario 0.
 */
int Validate_Int (char[]);

/**
 * @fn float Validate_Float(char[])
 * @brief recibe un numero en forma de String y lo valida para saber si es un numero en si.
 * @param char recibe un numero en forma de string
 * @return float retorna un numero flotante. 1 si pasa la validacion de numero flotante, caso contrario 0.
 */
float Validate_Float (char[]);

/**
 * @fn int Validate_IntMinMax(char[], int, int)
 * @brief recibe una cadena y valida si es un entero dentro de una maximo y minimo.
 * @param char[] recibe cadena con numero a validar.
 * @param int numero entero de delimita el minimo del rango a validar.
 * @param int numero entero de delimita el maximo del rango a validar.
 * @return int retorna un numero entero. 1 si pasa la validacion, 0 en caso contrario.
 */
int Validate_IntMinMax (char[], int, int);






#endif /* DATAIO_H_ */
