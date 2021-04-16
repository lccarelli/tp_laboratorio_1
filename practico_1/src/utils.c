/*
 ============================================================================
 Name        : practico_1.c
 Author      : lau carelli
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utn.h"
#include "calculos.h"
#define MENU_CALCULATES "\nMenú de cálculos:"
#define MENU_ADD "\n\ta). Calcular la suma (A+B)->(%.2f + %.2f)"
#define MENU_SUBSTRACTION "\n\tb). Calcular la resta (A-B)->(%.2f - %.2f)"
#define MENU_DIVISION "\n\tc). Calcular la division (A/B)->(%.2f / %.2f)"
#define MENU_MULTIPLICATION "\n\td). Calcular la multiplicacion (A*B)->(%.2f * %.2f)"
#define MENU_FACTORIAL "\n\te). Calcular el factorial (A!) y (B!)->(%.2f!) && (%.2f!)"

/**
 * \brief 	->	printResult 	-> Muestra resultado por pantalla
 * \param 	->	float* pResult 	-> Puntero donde se guarda el resultado
 * \param 	->	char* message  	-> Es el mensaje a ser mostrado
 * \return  ->	void 			-> no tiene retorno
**/
void printResult(float* pResult, char* message);

void getMenu(float a , float b, int* select){

	printf("\nMenu:"
			"\n\t1). Ingresar 1er operando (A=%.2f)"
			"\n\t2). Ingresar 2do operando (B=%.2f)"
			"\n\t3). Calcular todas las operaciones"
			"\n\t4). Informar resultados"
			"\n\t5). salir\n", a, b);
	utn_getNumeroEntero(select, "\nIngrese su seleccion -> ", "\nERROR -> Debe ser una de las opciones", 1, 5, 3);
}

void getMenuCalculate(float a , float b){
	printf(MENU_CALCULATES);
	printf(MENU_ADD, a, b);
	printf(MENU_SUBSTRACTION, a, b);
	printf(MENU_DIVISION, a, b);
	printf(MENU_MULTIPLICATION, a, b);
	printf(MENU_FACTORIAL, a, b);
}


void excecuteCalculates(float a, float b, float* pSum, float* pSub, float* pDiv, float* pMult, long double* pFactA, long double* pFactB, int* flag){

	if(pSum!=NULL && pSub!=NULL && pDiv != NULL && pMult != NULL && pFactA != NULL && pFactB != NULL){

		getAdd(a, b, pSum);
		getSubtraction(a, b, pSub);
		getDivision(a, b, pDiv);
		getMultiplication(a, b, pMult);
		ifInteger(a) ? (*pFactA = getFactorial(a)) : (*pFactA = -1);
		ifInteger(b) ? (*pFactB = getFactorial(b)) : (*pFactB = -1);
		printf("\nOperaciones calculadas.");
		*flag = 1;

	} else {
		printf("\nERROR -> ejecutando cálculos");
	}
}


void showCalculates(float *pSum, float *pSub, float *pDiv, float *pMult,
		long double *pFactA, long double *pFactB) {

	if (!(pSum == NULL && pSub == NULL && pDiv == NULL && pMult == NULL
			&& pFactA == NULL && pFactB == NULL)) {

		printResult(pSum, "\nEl resultado de A+B es: ");

		printResult(pSub, "\nEl resultado de A-B es: ");

		if (*pDiv == 0) printResult(pDiv, "\nNo se puede dividir por -> ");
		else printResult(pDiv, "\nEl resultado de A/B es: ");

		printResult(pMult, "\nEl resultado de A*B es: ");

		if (*pFactA == 0) printf("\nNo se puede calcular el factorial porque el operador A -> es CERO");
		else if (*pFactA == -1) printf("\nNo se puede calcular el factorial porque el operador A -> NO es un ENTERO");
		else printf("\nEl factorial de A es: %.2Lf", *pFactA);

		if (*pFactB == 0) printf("\nNo se puede calcular el factorial porque el operador B -> es CERO");
		else if (*pFactB == -1) printf("\nNo se puede calcular el factorial porque el operador A -> NO es un ENTERO");
		else printf("\nEl factorial de  B es: %.2Lf", *pFactB);

	} else {
		printf("\nERROR -> mostrando resultados");
	}
}

void printResult(float* pResult, char* message){

	printf("%s %.2f", message, *pResult);
}
