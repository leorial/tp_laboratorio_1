/*
 * validacion.h
 *
 *  Created on: 28 mar. 2021
 *      Author: Leo
 */
#include <stdio.h>
#include "operaciones.h"
#ifndef VALIDACION_H_
#define VALIDACION_H_

/**
 * @fn int Validate_IntPositive(float)
 * @brief recibe un numero flotante y valida si el mismo es entero y positivo.
 *
 * @param float recibe numero flotante a validar
 * @return int en caso de que se valide correctamente devuelve 0. en caso de que no devuelve 1.
 */
int Validate_IntPositive (float);

/**
 * @fn int Validate_Factorial(int, float)
 * @brief valida mediente el numero entero recibido si es posible factorizar el flotante y lo hace. si no es posible retorna otro numero entero.
 *
 * @param int recibe numero entero que indica si es posible fatorizar.
 * @param float recibe numero flotante a factorizar.
 * @return retorna un numero entero factorizado o en caso de que no se pueda factorizar -1.
 */
int Validate_Factorial (int , float );

/**
 * @fn int Validate_Zero(float)
 * @brief valida si el numero recibido es 0
 * @param float recibe numero flotante a validar
 * @return int retorna un entero. valida devolviendo 0 si es eso mismo. caso contrario, 1.
 */
int Validate_Zero (float);



#endif /* VALIDACION_H_ */
