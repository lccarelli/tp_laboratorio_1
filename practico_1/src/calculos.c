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

void getAdd(float a, float b, float* pResult){

	*pResult = a + b;
};

void getSubtraction(float a, float b, float* pResult){

	*pResult = a - b;
};

void getDivision(float a, float b, float* pResult){

	(b == 0) ? (*pResult = 0) : (*pResult = a /b);
};

void getMultiplication(float a, float b, float* pResult){

	*pResult = a * b;
};

long double getFactorial(float a){

	long double result;
	if (a > 1) (result = a * getFactorial(a-1));
			else if (a == 1) (result = 1);
			else (result = 0);

	return result;
};


