#ifndef UTN_H_INCLUDE
#define UTN_H_INCLUDE
#define LIMIT_TEXT 4096
#define LIMIT_INTEGER 50
#define LIMIT_FLOAT 64
#define OK 0
#define ERROR -1
#define TRUE 1
/**
 * @brief ->	Input de un dato de tipo numero entero
 * @param ->	number // Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * @param ->	message // Es el mensaje a ser mostrado
 * @param ->	errorMessage // Es el mensaje de Error a ser mostrado
 * @param ->	min // Es el numero maximo a ser aceptado
 * @param ->	max // Es el minimo minimo a ser aceptado
 * @return ->	Retorna 0 si se obtuvo el numero y -1 si no
**/
int utn_getNumero(int* number, char* message, char* errorMessage, int min, int max, int retries);
/**
 * @brief ->	Input de un dato de tipo numero flotante
 * @param ->	number // Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * @param ->	message // Es el mensaje a ser mostrado
 * @param ->	errorMessage // Es el mensaje de Error a ser mostrado
 * @param ->	min // Es el numero maximo a ser aceptado
 * @param ->	max // Es el minimo minimo a ser aceptado
 * @return ->	Retorna 0 si se obtuvo el numero y -1 si no
**/
int utn_getNumeroFlotante(float* number, char* message, char* errorMessage, float min, float max, int retries);
/**
 * @brief ->	Input de un dato tipo cadena de texto
 * @param ->	number // Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * @param ->	message // Es el mensaje a ser mostrado
 * @param ->	errorMessage // Es el mensaje de Error a ser mostrado
 * @param ->	min // Es el numero maximo a ser aceptado
 * @param ->	max // Es el minimo minimo a ser aceptado
 * @return ->	Retorna 0 si se obtuvo el numero y -1 si no
**/
int utn_getString(char* string, int len,char* message, char* errorMessage, int retries);
/**
 * @brief ->	transforma un string a numero entero
 * @param ->	stringValue // char -> cadena a transformar
 * @param ->	integerValue // int* -> puntero donde se guarda resultado
 * @return ->	Retorna 0 si se obtuvo el numero y -1 si no
**/
int utn_stringToInteger(char stringValue[], int* integerValue);
int validarNumero (char numeros[]);
int inputs_getString(char* input, char message[], char eMessage[], int lowLimit, int hiLimit);

#endif /* UTN_H_ */
