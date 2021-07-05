
#ifndef INPUT_H_
#define INPUT_H_




//GET

/**
 * @fn int Get_Int(char*, char*, int*)
 * @brief pide un numero entero y verifica que eso sea lo que se ingreso.
 * @param char* mensaje solicitando el numero.
 * @param char* mensaje de error volviendo a solicitar el numero.
 * @param int* variable donde se guardara el numero ingresado.
 * @return [1]si se verifico correctamente [0]si el puntero por referencia es NULL
 */
int Get_Int (char*, char*, int*);

/**
 * @fn char Get_Char(char*, char*, char*)
 * @brief pide un caracter y verifica que eso sea lo que se ingreso.
 * @param char* mensaje solicitando el caracter
 * @param char* mensaje de error volviendo a solicitar caracter.
 * @param char* variable char donde se guardara el carater ingresado.
 * @return [1]si se verifico correctamente [0]si el puntero por referencia es NULL
 */
int Get_Char(char*, char*, char*);

/**
 * @fn void Get_String(char*, char*, char*, int)
 * @brief pide una cadena de caracteres y verifica que eso sea lo que se ingreso.
 * @param char* mensaje solicitando el caracter
 * @param char* mensaje de error volviendo a solicitar caracter.
 * @param char* variable char array donde se guardara la cadena
 * @param int entero que indica el tama�o de la caneda recibida
 * @return [1]si se verifico correctamente [0]si el puntero por referencia es NULL
 */
int Get_String(char*, char*, char*, int);

/**
 * @fn float Get_Float(char*, char*, float*)
 * @brief pide un numero flotante y verifica que eso sea lo que se ingreso.
 * @param char* mensaje solicitando el numero.
 * @param char* mensaje de error volviendo a solicitar el numero.
 * @param float* variable donde se guardara el numero ingresado.
 * @return [1]si se verifico correctamente [0]si el puntero por referencia es NULL
 */
int Get_Float (char*, char*, float*);

/**
 * @fn int Get_IntMinMax(char[], char[], int, int)
 * @brief pide un numero entero, valida que eso sea lo ingresado y que este dentro del parametro de un minimo y un maximo.
 * @param char* mensaje solicitando el numero.
 * @param char* mensaje de error volviendo a solicitar el numero.
 * @param int numero entero minimo para parametros.
 * @param int numero entero maximo para parametros.
 * @param int* variable donde se guardara el numero ingresado.
 * @return int [1]si se verifico correctamente [0]si el puntero por referencia es NULL
 */
int Get_IntMinMax (char*, char*, int, int, int*);

//VALIDATE

/**
 * @fn int Validate_Int(char[])
 * @brief recibe un numero en forma de String y lo valida para saber si es un entero.
 * @param char recibe un numero en forma de string
 * @return int [1]si se verifico correctamente [0]si el puntero por referencia es NULL
 */
int Validate_Int (char*);

/**
 * @fn int Validate_Digit (char[])
 * @brief recibe un numero en forma de String y lo valida para saber si es un digito.
 * @param char recibe un numero en forma de string
 * @return int retorna un numero entero. 1 si pasa la validacion de numero entero, caso contrario 0.
 */
int Validate_Digit (char*);

/**
 * @fn float Validate_Float(char*)
 * @brief recibe un numero en forma de String y lo valida para saber si es un numero en si.
 * @param char recibe un numero en forma de string
 * @return float retorna un numero flotante. 1 si pasa la validacion de numero flotante, caso contrario 0.
 */
int Validate_Float (char*);

/**
 * @fn int Validate_IntMinMax(char*, int, int)
 * @brief recibe una cadena y valida si es un entero dentro de una maximo y minimo.
 * @param char* recibe cadena con numero a validar.
 * @param int numero entero de delimita el minimo del rango a validar.
 * @param int numero entero de delimita el maximo del rango a validar.
 * @return int retorna un numero entero. 1 si pasa la validacion, 0 en caso contrario.
 */
int Validate_IntMinMax (char*, int, int);

/**
 * @fn int Validate_MinMax (char*, int, int)
 * @brief recibe una cadena como numero entero y valida si esta dentro de un maximo y minimo.
 * @param char[] recibe cadena con numero a validar.
 * @param int numero entero de delimita el minimo del rango a validar.
 * @param int numero entero de delimita el maximo del rango a validar.
 * @return int retorna un numero entero. 1 si pasa la validacion, 0 en caso contrario.
 */
int Validate_MinMax (char*, int, int);

/**
 * @fn int Validate_YesOrNo(char[], char[])
 * @brief pide un caracter, lo valida y verifica que sea 's' o 'n'
 * @param char recibe char en forma de string
 * @return int retorna un numero entero. 1 si pasa la validacion, caso contrario 0.
 */
int Validate_YesOrNo(char*, char*);


#endif /* INPUT_H_ */
