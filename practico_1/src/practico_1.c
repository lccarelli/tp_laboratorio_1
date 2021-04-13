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
#include "utn.h"
#include "utils.h"
#define SELECTION_1 1
#define SELECTION_2 2
#define SELECTION_3 3
#define SELECTION_4 4
#define SELECTION_5 5

int main(void) {

	//setbuff(stdout, NULL);

		int selection;
		float operA;
		float operB;

		int flagA = 0;
		int flagB = 0;
		int flagCalculate = 0;

		float sumRt = 0;
		float subtRt = 0;
		float divRt = 0;
		float multRt = 0;
		long double factARt = 0;
		long double factBRt = 0;

		do {

			getMenu(operA, operB, &selection);

			switch(selection){

			case SELECTION_1:

				if(utn_getNumeroDecimal(&operA, "\nIngrese A -> ", "\nERROR -> Debe ser un número", -10000000, 10000000, 3)==0) flagA = 1;
				break;

			case SELECTION_2:

				if(utn_getNumeroDecimal(&operB, "\nIngrese B -> ", "\nERROR -> Debe ser un número", -10000000, 10000000, 3)==0) flagB = 1;
				break;

			case SELECTION_3:

				(flagA == 0 || flagB == 0) ?
					printf("\nERROR -> falta ingresar un operador") :
					excecuteCalculates(operA, operB, &sumRt, &subtRt, &divRt, &multRt, &factARt, &factBRt, &flagCalculate);
				break;

			case SELECTION_4:

				(flagCalculate == 0) ?
					printf("\nERROR -> MARQUE EL 3 para calcular.\n"):
					showCalculates(&sumRt, &subtRt, &divRt, &multRt, &factARt, &factBRt );
				break;
			};
		}
		while(!(selection == SELECTION_5));

		printf("Adiós, nos vemos la próxima vez que quieras calcular algo!");

	return EXIT_SUCCESS;
}
