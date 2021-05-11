#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include "utn.h"


//firmas de privadas

/**
 * @brief ->	*strlwr -> Simula ser la funcion de la libreria que se encuentra dentro de la biblioteca string.
 * @param ->	string -> puntero donde se va a guardar el texto
 * @return ->	int Return (-1) if Error [Invalid or NULL params] - (0) if Ok
**/
static char *strlwr(char *str);

/**
 * @brief ->	getString -> Toma el ingreso por teclado y lo copia en una cadena, con la funcion strncpy
 * @param ->	string -> puntero donde se va a guardar el texto
 * @param ->	len int -> longitud de la cadena
 * @return ->	int Return (-1) if Error [Invalid or NULL params] - (0) if Ok
**/
static int getString(char* string, int len);

/**
 * @brief ->	getInt -> Recorre una cadena y verifica si se encuentra un numero entero.
 * @param ->	integer -> puntero donde se va a guardar el numero entero
 * @return ->	int Return (-1) if Error [Invalid or NULL params] - (0) if Ok
**/
static int getInt(int* integer);

/**
 * @brief ->	isNumber -> Recorre una cadena y verifica que la info sea numerica
 * @param ->	string -> puntero donde se va a guardar el texto
 * @param ->	len -> tamaño de la cadena
 * @return ->	int Return (-1) if Error [Invalid or NULL params] - (0) if Ok
**/
static int isNumber(char* string, int len);

/**
 * @brief ->	getFloat -> Recorre una cadena buscando un numero con decimal
 * @param ->	numberFloat -> puntero donde se va a guardar el numero float
 * @return ->	int Return (-1) if Error [Invalid or NULL params] - (0) if Ok
**/
static int getFloat(float* numberFloat);

/**
 * @brief ->	isFloat -> Recorre una cadena y verifica si es un numero float
 * @param ->	string -> puntero donde se va a guardar el texto
 * @return ->	int Return (-1) if Error [Invalid or NULL params] - (0) if Ok
**/
static int isFloat(char* string);

/**
 * @brief ->	formatString -> Ingresa una cadena,a la que valida, y la normaliza con primera mayuscula
 * @param ->	string -> puntero donde se va a guardar el texto
 * @param ->	len -> longitud de la cadena
 * @return ->	int Return (-1) if Error [Invalid or NULL params] - (0) if Ok
**/
static int formatString(char* string, int len);

/**
 * @brief ->	isString -> Ingresa una cadena, y verifica que sean letras
 * @param ->	string -> puntero donde se va a guardar el texto
 * @param ->	len -> longitud de la cadena
 * @return ->	int Return (-1) if Error [Invalid or NULL params] - (0) if Ok
**/
static int isString(char* string, int len);
//END firmas privadas



//funciones publicas

int utn_getNumero(int* number, char* message, char* errorMessage, int min, int max, int retries){
	int result = ERROR;
	int buffer;
	do{
		printf("%s",message);
		if(	getInt(&buffer) == 0 && buffer >= min && buffer <= max){
			result = 0;
			*number = buffer;
			break;
		} else {
			printf("%s",errorMessage);
			retries--;
		}
	} while(retries>=0);
	return result;
}

int utn_getNumeroFlotante(float* number, char* message, char* errorMessage, float min, float max, int retries){
	float buffer;
	int result;

	do{
		printf("%s",message);
		if(getFloat(&buffer) == 0 && buffer >= min && buffer <= max){
				*number = buffer;
				result = OK;
				break;
		}else{
			printf("%s",errorMessage);
			retries--;
			result = ERROR;
		}
	}while(retries>=0);
	return result;
}

int utn_getString(char* string, int len,char* message, char* errorMessage, int retries){
	char buffer[LIMIT_TEXT];
	int result = ERROR;
	while(retries>=0){
		retries--;
		printf("%s",message);
		__fpurge(stdin);
		if(formatString(buffer,sizeof(buffer)) == OK && strnlen(buffer,sizeof(buffer)) < len ){
			strncpy(string,buffer,len);
			result = OK;
			break;
		}
		printf("%s",errorMessage);
	}
	return result;
}

int utn_stringToInteger(char stringValue[], int* integerValue){
    int result = 0;
    int value;

    if(stringValue != NULL){
        if(strcmp(stringValue, "0") == 0){
            *integerValue = 0;
            result = 1;
        } else {
            value = atoi(stringValue);
            if(value != 0){
                *integerValue = value;
                result = 1;
            }
        }
    }
    return result;
}

int validarNumero (char numeros[]){

    int result = 0, len, i = 0;

    len=strlen(numeros);

    while (i<len && result == 0) {
    	isdigit(numeros[i]) != 0 ? i++ : (result = 1);
    }
    return result;
}


//funciones privadas

//funcion copiada de internet para poder utilizar en linux strlwr, porque no se encuentra normalizada
static char *strlwr(char *str){
  unsigned char *p = (unsigned char *)str;
  while (*p) {
     *p = tolower((unsigned char)*p);
      p++;
  }
  return str;
}

static int getInt(int* integer){
    int result = ERROR;
    char buffer[LIMIT_INTEGER];

    if(integer != NULL){
    	if(getString(buffer,sizeof(buffer)) == OK && isNumber(buffer,sizeof(buffer)) == TRUE){
		*integer = atoi(buffer);
		result = OK;
    	}
	}
    return result;
}


static int isNumber(char* string, int len){
	int result = TRUE;

	if(string != NULL && len > 0){

		for(int i=0;i<len && string[i] != '\0';i++){
			if(string[i] < '0'||string[i] > '9'){
				result = OK;
				break;
			}
		}
	}
	return result;
}


static int getFloat(float* numberFloat){
    int result = ERROR;
    char buffer[LIMIT_FLOAT];

    if(numberFloat != NULL){
    	if(getString(buffer,sizeof(buffer))==0 && (isFloat(buffer) || isNumber(buffer,sizeof(buffer)))){
			*numberFloat = atof(buffer);
			result = OK;
		}
    }
    return result;
}


static int isFloat(char* string){
	int result, points=0;

	if(string != NULL && strlen(string) > 0){
		for(int i=0 ; string[i] != '\0'; i++){
			if(i==0 && (string[i] == '-' || string[i] == '+')) continue;
			if(string[i] < '0' || string[i] > '9' ){
				if(string[i] == '.' && points == 0){
					result = TRUE;
					points++;
				} else {
					result = OK;
					break;
				}
			}
		}
	}
	return result;
}


static int formatString(char* string, int len){
    int result=ERROR;
    char buffer[LIMIT_TEXT];

    if(string != NULL){
    	if(	getString(buffer,sizeof(buffer))==0 && isString(buffer,sizeof(buffer)) && strnlen(buffer,sizeof(buffer))<len){
    		strlwr(buffer);
    		buffer[0]=toupper(buffer[0]);
    		strncpy(string,buffer,len);
			result = OK;
		}
    }
    return result;
}


static int getString(char* string, int len){
	int result=ERROR;
	char buffer[LIMIT_TEXT];

	if(string != NULL && len > 0){
		__fpurge(stdin);
		if(fgets(buffer,sizeof(buffer),stdin) != NULL){

			if(buffer[strnlen(buffer,sizeof(buffer))-1] == '\n')
				buffer[strnlen(buffer,sizeof(buffer))-1] = '\0';

			if(strnlen(buffer,sizeof(buffer)) <= len){
				strncpy(string,buffer,len);
				result=OK;
			}
		}
	}
	return result;
}

static int isString(char* string, int len){
	int result = TRUE;
	if(string != NULL && len > 0){
		for(int i=0 ; string[i] != '\0' && i < len; i++){
			if((string[i] < 'A' || string[i] > 'Z' ) && (string[i] < 'a' || string[i] > 'z' )){
				result = OK;
				break;
			}
		}
	}
	return result;
}

