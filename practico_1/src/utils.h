/*
 ============================================================================
 Name        : practico_1.c
 Author      : lau carelli
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#ifndef UTILS_H_INCLUDE
#define UTILS_H_INCLUDE

#endif /* UTILS_H_ */

/* -----------------------------------------------------------------------------
 * @brief -> getMenu -> muestra un menu por pantalla y guarda la seleccion
 * @param -> float a 		-> operador numerico
 * @param -> float b 		-> operador numerico
 * @param -> int* selet 	-> puntero donde guardará el resultaod de la operacion
 * @RETURN -> no devuelve retorno
 */
void getMenu(float a, float b, int* select);

/* -----------------------------------------------------------------------------
 * @brief -> excecuteCalculates -> valida que todos los argumentos no sean NULL
 * 		  -> y ejecuta todas las operaciones, de los operadores ingresados
 * @param -> float a 		-> operador numerico
 * @param -> float b 		-> operador numerico
 * @param -> float* pSum	-> puntero donde se guardara el resultado de la suma
 * @param -> float* pSub	-> puntero donde se guardara el resultado de la resta
 * @param -> float* pDiv	-> puntero donde se guardara el resultado de la division
 * @param -> float* pMult	-> puntero donde se guardara el resultado de la multiplicacion
 * @param -> float* pFactA	-> puntero donde se guardara el resultado de un factorial
 * @param -> float* pFactB	-> puntero donde se guardara el resultado de un factorial
 * @param -> int* flag 		-> puntero donde guardará una bandera si se ejecutaron todas las operaciones
 * @RETURN -> no devuelve retorno
 */
void excecuteCalculates(float a, float b, float* pSum, float* pSub, float* pDiv, float* pMult, long double* pFactA, long double* pFactB, int* flag);

/* -----------------------------------------------------------------------------
 * @brief -> showCalculates -> valida que todos los argumentos no sean NULL
 * 		  -> y muestra por pantalla los resultados de todas las operaciones
 * @param -> float* pSub	-> puntero donde se encuentra el resultado de la resta
 * @param -> float* pSum	-> puntero donde se encuentra el resultado de la suma
 * @param -> float* pDiv	-> puntero donde se encuentra el resultado de la division
 * @param -> float* pMult	-> puntero donde se encuentra el resultado de la multiplicacion
 * @param -> float* pFactA	-> puntero donde se encuentra el resultado de un factorial
 * @param -> float* pFactB	-> puntero donde se encuentra el resultado de un factorial
 * @RETURN -> no devuelve retorno
 */
void showCalculates(float* pSum, float* pSub, float* pDiv, float* pMult, long double* pFactA, long double* pFactB );