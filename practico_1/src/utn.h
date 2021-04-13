/*
 ============================================================================
 Name        : practico_1.c
 Author      : lau carelli
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#ifndef UTN_H_
#define UTN_H_

#endif /* UTN_H_ */


/**
 * @brief ->	utn_getNumeroEntero -> Input de un dato, devuelve un numero entero
 * @param ->	number -> Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * @param ->	message -> Es el mensaje a ser mostrado
 * @param ->	errorMessage -> Es el mensaje de Error a ser mostrado
 * @param ->	min -> Es el numero maximo a ser aceptado
 * @param ->	max -> Es el minimo minimo a ser aceptado
 * @param ->	retries -> Cantidad de reintentos
 * @return ->	Retorna 0 si se obtuvo el numero y -1 si no
**/
int utn_getNumeroEntero(
					int* number,
					char* message,
					char* errorMessage,
					int min,
					int max,
					int retries
					);

/**
 * @brief ->	utn_getNumeroDecimal -> Input de un dato, devuelve un numero decimal
 * @param ->	number -> Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * @param ->	message -> Es el mensaje a ser mostrado
 * @param ->	errorMessage -> Es el mensaje de Error a ser mostrado
 * @param ->	min -> Es el numero maximo a ser aceptado
 * @param ->	max -> Es el minimo minimo a ser aceptado
 * @param ->	retries -> Cantidad de reintentos
 * @return ->	Retorna 0 si se obtuvo el numero y -1 si no
**/
int utn_getNumeroDecimal(
							float* number,
							char* message,
							char* errorMessage,
							int min,
							int max,
							int retries
						);

/**
 * @brief ->	ifInteger -> Chequea que un numero se entero
 * @param ->	number -> Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * @return ->	Retorna 1 (TRUE) si es entero - 0 si no lo es
**/
int ifInteger(float number);
