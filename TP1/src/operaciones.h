/*
 * operaciones.h
 *
 *  Created on: 25 mar. 2021
 *      Author: Leo
 */
#include <stdio.h>
#ifndef OPERACIONES_H_
#define OPERACIONES_H_


/**
 * @fn float SumarFloat(float, float)
 * @brief suma 2 numeros flotantes.
 *
 * @param float recibe primer numero flotante a sumar.
 * @param float recibe segundo numero flotante a sumar.
 * @return float retorna un numero flotante siendo resultado de la suma realizada.
 */
float SumarFloat (float, float);

/**
 * @fn float RestarFloat(float, float)
 * @brief resta un numero flotante de otro.
 *
 * @param float recibe primer numero flotante a operar.
 * @param float recibe segundo numero flotante a operar.
 * @return float retorna un numero flotante siendo resultado de la resta realizada.
 */
float RestarFloat (float, float);

/**
 * @fn float DividirFloat(float, float)
 * @brief recibe 2 numeros flotantes y el primero divide al segundo.
 *
 * @param float recibe el primer numero a operar.
 * @param float recibe el primer numero a operar.
 * @return float retorna un numero flotante como resultado de la division.
 */
float DividirFloat (float, float);

/**
 * @fn int FactorizarInt(int)
 * @brief realiza la factorizacion de un numero entero.
 *
 * @param int recibe un numero entero a factorizar.
 * @return int retorna un numero entero como resultado de la factorizacion.
 */
int FactorizarInt (int);

/**
 * @fn float MultiplicarFloat(float, float)
 * @brief realiza la multiplicacion de 2 numeros flotantes.
 *
 * @param float recibe el primer numero a multiplicar.
 * @param float recibe el segundo numero a multiplicar.
 * @return float retorna un numero flotante como resultado de la multiplicacion realizada.
 */
float MultiplicarFloat (float, float);






#endif /* OPERACIONES_H_ */
