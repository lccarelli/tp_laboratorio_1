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
 * \brief ->	utn_getNumeroEntero -> Devuelve un numero entero
 * \param ->	int* number 		-> Puntero donde se guardara el numero ingresado por stdin
 * \param ->	char* message 		-> Es el mensaje a ser mostrado
 * \param ->	char* errorMessage 	-> Es el mensaje de Error a ser mostrado
 * \param ->	int min				-> Es el numero minimo a ser aceptado
 * \param ->	int max				-> Es el numero maximo a ser aceptado
 * \param ->	int retries 		-> Cantidad de reintentos
 * \return ->	int 				-> 0 si se obtuvo el numero || -1 si no se obtuvo el numero
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
 * \brief ->	utn_getNumeroDecimal-> Devuelve un numero entero
 * \param ->	int* number 		-> Puntero donde se guardara el numero ingresado por stdin
 * \param ->	char* message 		-> Es el mensaje a ser mostrado
 * \param ->	char* errorMessage 	-> Es el mensaje de Error a ser mostrado
 * \param ->	int min				-> Es el numero minimo a ser aceptado
 * \param ->	int max				-> Es el numero maximo a ser aceptado
 * \param ->	int retries 		-> Cantidad de reintentos
 * \return ->	int 				-> 0 si se obtuvo el numero || -1 si no se obtuvo el numero
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
 * \brief ->	ifInteger 		-> Chequea que un numero se entero
 * \param ->	float number	-> Numero a comprobar
 * \return ->	int 			-> 1 (TRUE) si es entero || 0 si es FALSE
**/
int ifInteger(float number);
