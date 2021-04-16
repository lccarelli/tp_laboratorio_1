/*
 ============================================================================
 Name        : practico_1.c
 Author      : lau carelli
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#ifndef CALCULOS_H_INCLUDE
#define CALCULOS_H_INCLUDE
#endif /* CALCULOS_H_ */

/**
 * \brief 	-> getAdd 		  -> devuelve el resultado de una suma entre operador a y b
 * \param 	-> float a 		  -> operador numerico
 * \param 	-> float b 		  -> operador numerico
 * \param 	-> float* pResult -> puntero donde guardará el resultaod de la operacion
 * \return 	-> void 		  -> no tiene retorno
 **/
void getAdd(float a, float b, float *pResult);

/* -----------------------------------------------------------------------------
 * \brief 	-> getSubtraction -> devuelve el resultado de una resta entre operador a y b
 * \param 	-> float a 		  -> operador numerico
 * \param 	-> float b 		  -> operador numerico
 * \param 	-> float* pResult -> puntero donde guardará el resultaod de la operacion
 * \return 	-> void 		  -> no tiene retorno
 */
void getSubtraction(float a, float b, float *pResult);

/* -----------------------------------------------------------------------------
 * \brief 	-> getDivision	  -> devuelve el resultado de una division entre operador a y b
 * \param 	-> float a 		  -> operador numerico
 * \param 	-> float b 		  -> operador numerico
 * \param 	-> float* pResult -> puntero donde guardará el resultaod de la operacion
 * \return 	-> void 		  -> no tiene retorno
 */
void getDivision(float a, float b, float *pResult);

/* -----------------------------------------------------------------------------
 * \brief 	-> getMultiplication -> devuelve el resultado de una multiplicacion entre operador a y b
 * \param 	-> float a 		  	 -> operador numerico
 * \param 	-> float b 		 	 -> operador numerico
 * \param 	-> float* pResult	 -> puntero donde guardará el resultaod de la operacion
 * \return 	-> void 			 -> no tiene retorno
 */
void getMultiplication(float a, float b, float *pResult);

/* -----------------------------------------------------------------------------
 * \brief 	-> getFactorial 	  -> devuelve el resultado de una operacion factorial de un operador
 * \param 	-> float a 			  -> operador numerico
 * \return 	-> long double result -> si es numero mayor a 1 retorna el resultado || si el operador es 1 retorna 1 || si es otro valor retorna 0
 */
long double getFactorial(float a);



